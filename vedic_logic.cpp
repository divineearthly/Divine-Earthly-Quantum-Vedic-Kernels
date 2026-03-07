#include "vedic_logic.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using json = nlohmann::json;
std::vector<Rule> loaded_rules;

void loadRules(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        return;
    }
    json data;
    try {
        file >> data;
    } catch (...) {
        return;
    }

    if (data.contains("rules") && data["rules"].is_array()) {
        loaded_rules.clear();
        for (const auto& rule_json : data["rules"]) {
            Rule rule;
            rule.id = rule_json.value("id", "");
            rule.name = rule_json.value("name", "");
            rule.description = rule_json.value("description", "");
            rule.conditions = rule_json.value("conditions", json::array());
            rule.actions = rule_json.value("actions", json::array());
            rule.priority = rule_json.value("priority", 0);
            loaded_rules.push_back(rule);
        }
        std::cerr << "[DEBUG] Successfully loaded " << loaded_rules.size() << " rules from: " << filepath << std::endl;
    }
}

std::string processVedicSutra(const std::string& sutra_name, const std::string& input_data_json) {
    json input_data;
    try { 
        input_data = json::parse(input_data_json); 
    } catch (...) { 
        return R"({"status":"error", "message":"invalid_json"})"; 
    }

    for (const auto& rule : loaded_rules) {
        bool match_conditions = true;
        for (const auto& cond : rule.conditions) {
            std::string type = cond.value("type", "");
            std::string op = cond.value("operator", "");
            json target_val = cond["value"];

            if (input_data.contains(type)) {
                auto& input_val = input_data[type];
                if (op == "equals") {
                    if (input_val.is_number() && target_val.is_number()) {
                        if (input_val.get<double>() != target_val.get<double>()) match_conditions = false;
                    } else if (input_val.is_string() && target_val.is_string()) {
                        if (input_val.get<std::string>() != target_val.get<std::string>()) match_conditions = false;
                    } else { match_conditions = false; }
                } else if (op == "greater_than") {
                    if (input_val.is_number() && target_val.is_number()) {
                        if (input_val.get<double>() <= target_val.get<double>()) match_conditions = false;
                    } else { match_conditions = false; }
                }
            } else { match_conditions = false; }
            if (!match_conditions) break;
        }

        if (match_conditions) {
            json resp;
            resp["status"] = "success";
            resp["message"] = "Rule Applied: " + rule.name;
            resp["sutra"] = sutra_name;
            return resp.dump();
        }
    }

    json output_json;
    output_json["status"] = "success";
    output_json["message"] = "No intervention required";
    output_json["sutra"] = sutra_name;
    return output_json.dump();
}
