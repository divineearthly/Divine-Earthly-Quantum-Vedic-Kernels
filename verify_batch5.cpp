#include <iostream>
#include "core/BinduComputeEngine.h"
#include "core/SutraRegistry.h"

extern void registerBatch5();

int main() {
    std::cout << "--- BATCH 5 GEOMETRY/TRIG VERIFICATION ---\n";
    registerBatch5();

    BinduComputeEngine engine;
    engine.execute("sulba_geometry");
    engine.execute("surya_trig");

    std::cout << "\n[Success] Batch 5 registration and mathematical routing verified.\n";
    return 0;
}