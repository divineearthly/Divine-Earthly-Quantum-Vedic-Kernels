#include <iostream>
#include <string>
#include "vedic_logic.h"

int main(int argc, char* argv[]) {
    // CI-Resilient path loading
    loadRules("configs/rules.json");
    if (loaded_rules.empty()) loadRules("../configs/rules.json");
    if (loaded_rules.empty()) loadRules("/content/Divine-Earthly-Quantum-Vedic-Kernels/configs/rules.json");

    if (argc < 3) {
        std::cerr << R"({"status":"error", "message":"Usage: ./vedic_engine <gate_name> <json_input>"})" << std::endl;
        return 1;
    }

    std::string result = processVedicSutra(argv[1], argv[2]);
    std::cout << result << std::endl;
    return 0;
}
