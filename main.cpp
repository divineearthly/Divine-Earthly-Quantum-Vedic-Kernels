#include <iostream>
#include <string>
#include "vedic_logic.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char* argv[]) {
    std::string sutra_name = "MainSutra_1";
    std::string input_json_str = "{\"value\": 10, \"multiplier\": 1}";

    if (argc >= 3) {
        sutra_name = argv[1];
        input_json_str = argv[2];
    }

    try {
        std::string result_json = processVedicSutra(sutra_name, input_json_str);
        std::cout << result_json << std::endl;
    } catch (const std::exception& e) {
        json error_json;
        error_json["status"] = "error";
        error_json["message"] = e.what();
        std::cout << error_json.dump() << std::endl;
        return 1;
    }
    return 0;
}