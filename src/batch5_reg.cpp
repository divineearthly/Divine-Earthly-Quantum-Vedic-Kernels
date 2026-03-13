#include <iostream>
#include "core/SutraRegistry.h"
#include "compute/SulbaSutras.h"
#include "compute/SuryaSiddhanta.h"

void registerBatch5() {
    SutraRegistry::registerSutra("sulba_geometry", []() {
        std::cout << "[Kernel] Running Sulba Sutras (Geometric Routines)...\n";
    });
    SutraRegistry::registerSutra("surya_trig", []() {
        std::cout << "[Kernel] Running Surya Siddhanta (Trig Approximations)...\n";
    });
}