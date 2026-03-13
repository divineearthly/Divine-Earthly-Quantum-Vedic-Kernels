#include <iostream>
#include "core/SutraRegistry.h"
#include "compute/Ekadhikena.h"
#include "compute/PingalaChandaSutras.h"

void registerBatch3() {
    SutraRegistry::registerSutra("ekadhikena_series", []() {
        std::cout << "[Kernel] Running Ekadhikena Purvena (Sequence Generation)...\n";
    });
    SutraRegistry::registerSutra("pingala_combinatorics", []() {
        std::cout << "[Kernel] Running Pingala Chanda Sutras (Combinatorics)...\n";
    });
}
