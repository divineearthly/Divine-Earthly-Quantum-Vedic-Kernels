#pragma once

#include <string>
#include <vector>
#include "nlohmann/json.hpp"

// Define Rule structure (must be consistent with vedic_logic.cpp)
struct Rule {
    std::string id;
    std::string name;
    std::string description;
    nlohmann::json conditions; // Store conditions as raw JSON to parse dynamically
    nlohmann::json actions;    // Store actions as raw JSON to parse dynamically
    int priority;
};

// Global vector to store loaded rules
extern std::vector<Rule> loaded_rules;

// Function to load rules from JSON file
void loadRules(const std::string& filepath);

// Main function to process a Vedic Sutra (cognitive gate) with JSON input
std::string processVedicSutra(const std::string& sutra_name, const std::string& json_input);
