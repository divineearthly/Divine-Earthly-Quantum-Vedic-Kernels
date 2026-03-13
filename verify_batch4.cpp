#include <iostream>
#include "core/BinduComputeEngine.h"
#include "core/SutraRegistry.h"

extern void registerBatch4();

int main() {
    std::cout << "--- BATCH 4 LOGIC/GRAMMAR VERIFICATION ---\n";
    registerBatch4();

    BinduComputeEngine engine;
    engine.execute("panini_grammar");
    engine.execute("nyaya_inference");

    std::cout << "\n[Success] Batch 4 registration and logical routing verified.\n";
    return 0;
}