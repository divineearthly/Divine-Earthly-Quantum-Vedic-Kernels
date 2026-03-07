#include "vedic_logic.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <vector>

// Define Rule structure
struct Rule {
    std::string id;
    std::string name;
    std::string description;
    nlohmann::json conditions; // Store conditions as raw JSON to parse dynamically
    nlohmann::json actions;    // Store actions as raw JSON to parse dynamically
    int priority;
};

std::vector<Rule> loaded_rules;

// Function to load rules from JSON
void loadRules(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open rules file: " << filepath << std::endl;
        return;
    }
    nlohmann::json data;
    try {
        file >> data;
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "Error parsing rules JSON: " << e.what() << std::endl;
        return;
    }

    if (data.contains("rules") && data["rules"].is_array()) {
        for (const auto& rule_json : data["rules"]) {
            Rule rule;
            rule.id = rule_json.value("id", "");
            rule.name = rule_json.value("name", "");
            rule.description = rule_json.value("description", "");
            rule.conditions = rule_json.value("conditions", nlohmann::json::array());
            rule.actions = rule_json.value("actions", nlohmann::json::array());
            rule.priority = rule_json.value("priority", 0);
            loaded_rules.push_back(rule);
        }
        std::cerr << "Successfully loaded " << loaded_rules.size() << " rules." << std::endl;
    } else {
        std::cerr << "Error: 'rules' array not found in JSON." << std::endl;
    }
}


#include <string>
#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <cmath>

using json = nlohmann::json;

// External C-style declarations for advanced kernels found in workspace
extern "C" {
    void urdhva_3x3_matmul_c(const double* A, const double* B, double* C);
    void paravartya_3x3_inverse_c(const double* A, double* invA);
    void reconstruct_kernel(const double* X, const double* Y, const double* Z, double* out, size_t n, double b00, double b10, double b20);
}

// Forward declarations for existing 32 Sutras
std::string mainSutra1_impl(const std::string& input);
// ... (rest of implementation functions are linked via sutras/*.cpp)

std::string processVedicSutra(const std::string& sutra_name, const std::string& input_data_json) {
    
    
    if (loaded_rules.empty()) loadRules("/content/Divine-Earthly-Quantum-Vedic-Kernels/configs/rules.json");
    nlohmann::json input_data;
    try { input_data = nlohmann::json::parse(input_data_json); } catch (...) {}

    for (const auto& rule : loaded_rules) {
        bool match = true;
        for (const auto& cond : rule.conditions) {
            std::string type = cond.value("type", "");
            std::string op = cond.value("operator", "");
            nlohmann::json target_val = cond["value"];

            if (type == "gate_name") {
                if (sutra_name != target_val.get<std::string>()) match = false;
            } else if (input_data.contains(type)) {
                auto& input_val = input_data[type];
                if (op == "equals") {
                    if (input_val.is_number() && target_val.is_number()) {
                        if (input_val.get<double>() != target_val.get<double>()) match = false;
                    } else {
                        std::string s1 = input_val.is_string() ? input_val.get<std::string>() : input_val.dump();
                        std::string s2 = target_val.is_string() ? target_val.get<std::string>() : target_val.dump();
                        if (s1 != s2) match = false;
                    }
                } else if (op == "greater_than") {
                    double val1 = input_val.is_number() ? input_val.get<double>() : std::stod(input_val.is_string() ? input_val.get<std::string>() : "0");
                    double val2 = target_val.is_number() ? target_val.get<double>() : std::stod(target_val.is_string() ? target_val.get<std::string>() : "0");
                    if (val1 <= val2) match = false;
                }
            } else { match = false; }
            if (!match) break;
        }
        if (match) {
            nlohmann::json resp;
            resp["status"] = "success";
            resp["message"] = "Rule Applied: " + rule.name;
            resp["sutra"] = sutra_name;
            return resp.dump();
        }
    }
    nlohmann::json no_match_resp;
    no_match_resp["status"] = "success";
    no_match_resp["message"] = "No intervention required";
    no_match_resp["sutra"] = sutra_name;
    return no_match_resp.dump();
}