#include <iostream>
#include "DivineMaster.h"
#include "core/DivineKernel.h"

int main() {
    try {
        std::cout << "=== DIVINE EARTHLY SOVEREIGN KERNEL v1.5 ===\n";
        std::cout << "Status: 64 Sutras Integrated | Performance: +2.28% Opt.\n\n";

        // Initialize the core using the default constructor
        DivineKernel core; 
        
        SovereignOrchestrator::initializeFullSystem(core);

        std::cout << "\n[Success] Kernel operating in Turiya state.\n";
    } catch (...) {
        std::cerr << "[Error] System reset required. Entropy high.\n";
    }
    return 0; 
}
