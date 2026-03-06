#include <iostream>
#include <string>
#include "vedic_logic.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "{\"status\":\"error\", \"message\":\"Usage: ./vedic_engine <gate_name> <json_input>\"}" << std::endl;
        return 1;
    }
    std::string gate_name = argv[1];
    std::string input_json = argv[2];

    try {
        std::string result = processVedicSutra(gate_name, input_json);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "{\"status\":\"error\", \"message\":\"" << e.what() << "\"}" << std::endl;
    }
    return 0;
}
