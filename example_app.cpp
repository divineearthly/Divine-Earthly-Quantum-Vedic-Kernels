#include <iostream>
#include "core/BinduComputeEngine.h"
#include "core/SutraRegistry.h"

// External registration functions from our implemented batches
extern void registerBatch1();
extern void registerBatch2();
extern void registerBatch3();
extern void registerBatch4();
extern void registerBatch5();
extern void registerBatch6();

int main() {
    std::cout << "=== Sovereign App Integration: BinduComputeEngine ===\n";

    // 1. Initialization: Register the sutra kernels you need
    // In a production app, you might only register specific batches to save memory.
    registerBatch1(); // Arithmetic
    registerBatch3(); // Combinatorics
    registerBatch4(); // Logic/NLP

    // 2. Instantiate the Core Engine
    BinduComputeEngine engine;

    // 3. Dynamic Task Routing
    std::cout << "\n[App] Requesting Matrix Multiplication...\n";
    engine.execute("urdhva_tiryak");

    std::cout << "\n[App] Requesting Pascal Triangle Generation...\n";
    engine.execute("pingala_combinatorics");

    std::cout << "\n[App] Requesting Linguistic Analysis...\n";
    engine.execute("panini_grammar");

    std::cout << "\n[Success] All tasks routed through BinduComputeEngine.\n";
    return 0;
}
