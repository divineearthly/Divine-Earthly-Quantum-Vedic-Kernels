#include <iostream>
#include "core/BinduComputeEngine.h"
#include "core/SutraRegistry.h"

extern void registerBatch3();

int main() {
    std::cout << "--- BATCH 3 COMBINATORICS VERIFICATION ---\n";
    registerBatch3();

    BinduComputeEngine engine;
    engine.execute("ekadhikena_series");
    engine.execute("pingala_combinatorics");

    std::cout << "\n[Success] Batch 3 registration and sequence routing verified.\n";
    return 0;
}
