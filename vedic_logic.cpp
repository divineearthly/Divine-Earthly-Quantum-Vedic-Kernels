#include "vedic_logic.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath> // For M_PI and math functions

// Use nlohmann for JSON parsing
using json = nlohmann::json;

// Global vector to store loaded rules (declared in .h, defined here)
std::vector<Rule> loaded_rules;

// External C-style declarations for advanced kernels (found in workspace, not part of this file)
extern "C" {
    // void urdhva_3x3_matmul_c(const double* A, const double* B, double* C);
    // void paravartya_3x3_inverse_c(const double* A, double* invA);
    // void reconstruct_kernel(const double* X, const double* Y, const double* Z, double* out, size_t n, double b00, double b10, double b20);
}

// Forward declarations for existing 32 Sutras (implementations in sutras/*.cpp)
std::string mainSutra1_impl(const std::string& input);
// ... other main and sub sutra declarations ...

// Function to load rules from JSON file
void loadRules(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open rules file: " << filepath << std::endl;
        return;
    }
    json data;
    try {
        file >> data;
    } catch (const json::parse_error& e) {
        std::cerr << "Error parsing rules JSON: " << e.what() << std::endl;
        return;
    }

    if (data.contains("rules") && data["rules"].is_array()) {
        loaded_rules.clear(); // Clear existing rules before loading new ones
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
        std::cerr << "Successfully loaded " << loaded_rules.size() << " rules." << std::endl;
    } else {
        std::cerr << "Error: 'rules' array not found in JSON." << std::endl;
    }
}

// Main function to process a Vedic Sutra (cognitive gate) with JSON input
std::string processVedicSutra(const std::string& sutra_name, const std::string& input_data_json) {
    json input_data;
    try {
        input_data = json::parse(input_data_json);
    } catch (const json::parse_error& e) {
        // If input_data_json is not valid JSON, treat it as empty or handle as error
        json error_resp;
        error_resp["status"] = "error";
        error_resp["message"] = "Invalid JSON input: " + std::string(e.what());
        error_resp["sutra"] = sutra_name;
        return error_resp.dump();
    }

    // --- Dynamic Rule Evaluation --- 
    // Iterate through rules and find a match
    for (const auto& rule : loaded_rules) {
        // Check if the rule is specifically for this gate or a general rule
        bool gate_name_matches = true;
        // Check if this rule is applicable to the current sutra_name (gate)
        // For simplicity, we assume rules should apply to any gate unless specified
        // In a more complex system, rules might have a 'target_gate' field.
        
        bool match_conditions = true;
        for (const auto& cond : rule.conditions) {
            std::string type = cond.value("type", "");
            std::string op = cond.value("operator", "");
            json target_val = cond["value"];

            // Special condition for matching the gate name itself
            if (type == "gate_name") {
                if (sutra_name != target_val.get<std::string>()) {
                    match_conditions = false;
                    break;
                }
            } else if (input_data.contains(type)) {
                auto& input_val = input_data[type];
                
                if (op == "equals") {
                    if (input_val.is_number() && target_val.is_number()) {
                        if (input_val.get<double>() != target_val.get<double>()) {
                            match_conditions = false;
                            break;
                        }
                    } else if (input_val.is_string() && target_val.is_string()) {
                        if (input_val.get<std::string>() != target_val.get<std::string>()) {
                            match_conditions = false;
                            break;
                        }
                    } else {
                        // Type mismatch, or unsupported comparison
                        match_conditions = false;
                        break;
                    }
                } else if (op == "greater_than") {
                    if (input_val.is_number() && target_val.is_number()) {
                        if (input_val.get<double>() <= target_val.get<double>()) {
                            match_conditions = false;
                            break;
                        }
                    } else {
                        // Cannot compare non-numeric types with 'greater_than'
                        match_conditions = false;
                        break;
                    }
                } // Add other operators as needed (e.g., less_than, contains)
            } else {
                // Input data does not contain the required type for condition
                match_conditions = false;
                break;
            }
        }

        if (match_conditions) {
            json resp;
            resp["status"] = "success";
            resp["message"] = "Rule Applied: " + rule.name;
            resp["sutra"] = sutra_name;
            resp["rule_id"] = rule.id;
            resp["actions_to_take"] = rule.actions;
            return resp.dump();
        }
    }

    // If no dynamic rule matched, proceed with static gate logic or default fallback
    json output_json;
    output_json["status"] = "success"; // Default to success
    output_json["sutra"] = sutra_name;

    // Example of a static gate logic (placeholder)
    if (sutra_name == "matrix_engine_tool") {
        std::string op = input_data.value("operation", "");
        // Dummy matrix data for demonstration
        if (op == "inverse") {
            output_json["computed_value"] = "matrix_inverse_simulated";
        } else {
            output_json["computed_value"] = "operation_not_implemented";
        }
    } else if (sutra_name == "vedic_trig_tool") {
        double angle = input_data.value("angle_degrees", 0.0);
        std::string op = input_data.value("operation", "sin");
        double rad = angle * M_PI / 180.0;
        output_json["computed_value"] = (op == "sin") ? std::sin(rad) : (op == "cos" ? std::cos(rad) : std::tan(rad));
    } else if (sutra_name == "fourier_transform_tool") {
        output_json["dominant_frequency"] = "125 Hz"; // Placeholder
    } else if (sutra_name.find("MainSutra_") != std::string::npos || sutra_name.find("SubSutra_") != std::string::npos) {
        // Generic handling for original 32 sutras if no dynamic rule applied
        output_json["computed_value"] = input_data.value("value", 0);
        output_json["message"] = "Processed by static sutra logic.";
    } else {
        output_json["message"] = "No intervention required"; // Consistent fallback for unmatched inputs
    }
    
    return output_json.dump();
}
