#include <iostream>
#include "core/BinduComputeEngine.h"
#include "core/SutraRegistry.h"

extern void registerBatch1();

int main() {
    std::cout << "--- BATCH 1 VERIFICATION ---\n";
    registerBatch1();
    
    BinduComputeEngine engine;
    engine.execute("nikhilam_mult");
    engine.execute("urdhva_tiryak");

    std::cout << "\n[Success] Batch 1 registration and execution verified.\n";
    return 0;
}
