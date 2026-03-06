#include "vedic_logic.h"
#include <string>
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// --- Forward Declarations for 16 Main Sutras ---
std::string mainSutra1_impl(const std::string& input_json_str);
std::string mainSutra2_impl(const std::string& input_json_str);
std::string mainSutra3_impl(const std::string& input_json_str);
std::string mainSutra4_impl(const std::string& input_json_str);
std::string mainSutra5_impl(const std::string& input_json_str);
std::string mainSutra6_impl(const std::string& input_json_str);
std::string mainSutra7_impl(const std::string& input_json_str);
std::string mainSutra8_impl(const std::string& input_json_str);
std::string mainSutra9_impl(const std::string& input_json_str);
std::string mainSutra10_impl(const std::string& input_json_str);
std::string mainSutra11_impl(const std::string& input_json_str);
std::string mainSutra12_impl(const std::string& input_json_str);
std::string mainSutra13_impl(const std::string& input_json_str);
std::string mainSutra14_impl(const std::string& input_json_str);
std::string mainSutra15_impl(const std::string& input_json_str);
std::string mainSutra16_impl(const std::string& input_json_str);

// --- Forward Declarations for 16 Sub-Sutras ---
std::string subSutra1_impl(const std::string& input_json_str);
std::string subSutra2_impl(const std::string& input_json_str);
std::string subSutra3_impl(const std::string& input_json_str);
std::string subSutra4_impl(const std::string& input_json_str);
std::string subSutra5_impl(const std::string& input_json_str);
std::string subSutra6_impl(const std::string& input_json_str);
std::string subSutra7_impl(const std::string& input_json_str);
std::string subSutra8_impl(const std::string& input_json_str);
std::string subSutra9_impl(const std::string& input_json_str);
std::string subSutra10_impl(const std::string& input_json_str);
std::string subSutra11_impl(const std::string& input_json_str);
std::string subSutra12_impl(const std::string& input_json_str);
std::string subSutra13_impl(const std::string& input_json_str);
std::string subSutra14_impl(const std::string& input_json_str);
std::string subSutra15_impl(const std::string& input_json_str);
std::string subSutra16_impl(const std::string& input_json_str);

std::string processVedicSutra(const std::string& sutra_name, const std::string& input_data_json) {
    if (sutra_name == "MainSutra_1") {
        return mainSutra1_impl(input_data_json);
    } else if (sutra_name == "MainSutra_2") {
        return mainSutra2_impl(input_data_json);
    } else if (sutra_name == "MainSutra_3") {
        return mainSutra3_impl(input_data_json);
    } else if (sutra_name == "MainSutra_4") {
        return mainSutra4_impl(input_data_json);
    } else if (sutra_name == "MainSutra_5") {
        return mainSutra5_impl(input_data_json);
    } else if (sutra_name == "MainSutra_6") {
        return mainSutra6_impl(input_data_json);
    } else if (sutra_name == "MainSutra_7") {
        return mainSutra7_impl(input_data_json);
    } else if (sutra_name == "MainSutra_8") {
        return mainSutra8_impl(input_data_json);
    } else if (sutra_name == "MainSutra_9") {
        return mainSutra9_impl(input_data_json);
    } else if (sutra_name == "MainSutra_10") {
        return mainSutra10_impl(input_data_json);
    } else if (sutra_name == "MainSutra_11") {
        return mainSutra11_impl(input_data_json);
    } else if (sutra_name == "MainSutra_12") {
        return mainSutra12_impl(input_data_json);
    } else if (sutra_name == "MainSutra_13") {
        return mainSutra13_impl(input_data_json);
    } else if (sutra_name == "MainSutra_14") {
        return mainSutra14_impl(input_data_json);
    } else if (sutra_name == "MainSutra_15") {
        return mainSutra15_impl(input_data_json);
    } else if (sutra_name == "MainSutra_16") {
        return mainSutra16_impl(input_data_json);
    } else if (sutra_name == "SubSutra_1") {
        return subSutra1_impl(input_data_json);
    } else if (sutra_name == "SubSutra_2") {
        return subSutra2_impl(input_data_json);
    } else if (sutra_name == "SubSutra_3") {
        return subSutra3_impl(input_data_json);
    } else if (sutra_name == "SubSutra_4") {
        return subSutra4_impl(input_data_json);
    } else if (sutra_name == "SubSutra_5") {
        return subSutra5_impl(input_data_json);
    } else if (sutra_name == "SubSutra_6") {
        return subSutra6_impl(input_data_json);
    } else if (sutra_name == "SubSutra_7") {
        return subSutra7_impl(input_data_json);
    } else if (sutra_name == "SubSutra_8") {
        return subSutra8_impl(input_data_json);
    } else if (sutra_name == "SubSutra_9") {
        return subSutra9_impl(input_data_json);
    } else if (sutra_name == "SubSutra_10") {
        return subSutra10_impl(input_data_json);
    } else if (sutra_name == "SubSutra_11") {
        return subSutra11_impl(input_data_json);
    } else if (sutra_name == "SubSutra_12") {
        return subSutra12_impl(input_data_json);
    } else if (sutra_name == "SubSutra_13") {
        return subSutra13_impl(input_data_json);
    } else if (sutra_name == "SubSutra_14") {
        return subSutra14_impl(input_data_json);
    } else if (sutra_name == "SubSutra_15") {
        return subSutra15_impl(input_data_json);
    } else if (sutra_name == "SubSutra_16") {
        return subSutra16_impl(input_data_json);
    } else {
        json error_json;
        error_json["status"] = "error";
        error_json["message"] = "Unknown Sutra: " + sutra_name;
        return error_json.dump();
    }
}
