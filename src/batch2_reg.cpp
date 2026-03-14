#include <iostream>
#include "include/core/SutraRegistry.h"
#include "include/compute/ParavartyaLogic.h"
#include "include/compute/ShunyamAnyat.h"

void registerBatch2() {
    SutraRegistry::registerSutra("paravartya_logic", []() {
        std::cout << "[Kernel] Running Paravartya Yojayet (Algebraic Normalization)...\n";
    });
    SutraRegistry::registerSutra("shunyam_pruning", []() {
        std::cout << "[Kernel] Running Shunyam Anyat (Sparse Pruning)...\n";
    });
}
