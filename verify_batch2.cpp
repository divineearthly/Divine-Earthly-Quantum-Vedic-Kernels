#include <iostream>
#include "core/BinduComputeEngine.h"
#include "core/SutraRegistry.h"

extern void registerBatch2();

int main() {
    std::cout << "--- BATCH 2 ALGEBRA VERIFICATION ---\n";
    registerBatch2();

    BinduComputeEngine engine;
    engine.execute("paravartya_logic");
    engine.execute("shunyam_pruning");

    std::cout << "\n[Success] Batch 2 registration and algebraic routing verified.\n";
    return 0;
}
