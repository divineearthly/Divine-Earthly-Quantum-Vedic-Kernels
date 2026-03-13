#include "logic/NyayaSutras.h"
#include <iostream>

namespace DivineEarthlyKernels::Logic {
bool NyayaSutras::infer(const std::string& premise, const std::string& conclusion) {
    // Symbolic Logic: If premise contains keyword, conclude validity
    return premise.find("Veda") != std::string::npos;
}
}