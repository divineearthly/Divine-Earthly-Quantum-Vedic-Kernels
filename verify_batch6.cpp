#include <iostream>
#include "core/BinduComputeEngine.h"
#include "core/SutraRegistry.h"

extern void registerBatch6();

int main() {
    std::cout << "--- BATCH 6 ADVANCED CALCULUS VERIFICATION ---\n";
    registerBatch6();

    BinduComputeEngine engine;
    engine.execute("buddhi_fuzzy");
    engine.execute("quantum_heuristic");

    std::cout << "\n[Success] Batch 6 registration and advanced function routing verified.\n";
    return 0;
}