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
        std::cout << "Successfully loaded " << loaded_rules.size() << " rules." << std::endl;
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
            std::string val = cond.value("value", "");
            if (type == "gate_name" && sutra_name != val) match = false;
            else if (input_data.contains(type)) {
                if (op == "equals" && input_data[type].dump() != "\""+val+"\"") match = false;
            } else match = false;
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
}
