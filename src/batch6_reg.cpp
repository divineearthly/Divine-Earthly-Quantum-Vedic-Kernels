#include <iostream>
#include "include/core/SutraRegistry.h"
#include "include/compute/BuddhiLogic.h"

void registerBatch6() {
    SutraRegistry::registerSutra("buddhi_fuzzy", []() {
        std::cout << "[Kernel] Running Buddhi Logic (Fuzzy Inference)...\n";
    });
    SutraRegistry::registerSutra("quantum_heuristic", []() {
        std::cout << "[Kernel] Running Quantum-inspired Siddhanta Heuristic...\n";
    });
}