#include <iostream>
#include "core/SutraRegistry.h"
#include "compute/VedicALU.h"
#include "compute/NikhilamMath.h"

void registerBatch1() {
    SutraRegistry::registerSutra("urdhva_tiryak", []() {
        std::cout << "[Kernel] Running Urdhva Tiryagbhyam (SIMD Optimized)...\n";
        // Placeholder for specific execution test
    });
    SutraRegistry::registerSutra("nikhilam_mult", []() {
        std::cout << "[Kernel] Running Nikhilam Base Multiplication...\n";
    });
}
