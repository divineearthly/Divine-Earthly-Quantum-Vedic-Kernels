#include <iostream>
#include <string>
#include "vedic_logic.h" // Include the corrected header

int main(int argc, char* argv[]) {
    // Load rules once at application startup
    static bool rules_loaded = false;
    if (!rules_loaded) {
        loadRules("/content/Divine-Earthly-Quantum-Vedic-Kernels/configs/rules.json");
        rules_loaded = true;
    }

    if (argc < 3) {
        std::cerr << R"({"status":"error", "message":"Usage: ./vedic_engine <gate_name> <json_input>"})" << std::endl;
        return 1;
    }

    std::string gate_name = argv[1];
    std::string input_json = argv[2];

    try {
        std::string result = processVedicSutra(gate_name, input_json);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << R"({"status":"error", "message":"Runtime error: )" << e.what() << R"("})" << std::endl;
        return 1;
    }

    return 0;
}
