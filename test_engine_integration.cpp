#include <iostream>
#include "core/SutraRegistry.h"
#include "core/BinduComputeEngine.h"

void mockVedicTask() {
    std::cout << "[Kernel] Executing Urdhva Tiryagbhyam Logic..." << std::endl;
}

int main() {
    std::cout << "--- BINDU ENGINE & REGISTRY INTEGRATION TEST ---\n";
    
    // Registration phase
    SutraRegistry::registerSutra("urdhva_tiryak", mockVedicTask);
    
    // Execution phase
    BinduComputeEngine engine;
    engine.execute("urdhva_tiryak");
    engine.execute("invalid_sutra");

    std::cout << "\n[Success] Engine integration test complete." << std::endl;
    return 0;
}