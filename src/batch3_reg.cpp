#include <iostream>
#include "include/core/SutraRegistry.h"
#include "include/compute/Ekadhikena.h"
#include "include/compute/PingalaChandaSutras.h"

void registerBatch3() {
    SutraRegistry::registerSutra("ekadhikena_series", []() {
        std::cout << "[Kernel] Running Ekadhikena Purvena (Sequence Generation)...\n";
    });
    SutraRegistry::registerSutra("pingala_combinatorics", []() {
        std::cout << "[Kernel] Running Pingala Chanda Sutras (Combinatorics)...\n";
    });
}
