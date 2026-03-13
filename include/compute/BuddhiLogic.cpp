#include "compute/BuddhiLogic.h"
#include <cmath>
#include <vector>
#include <algorithm>

namespace DivineEarthlyKernels::Compute {
float BuddhiLogic::fuzzyInference(float input) {
    return 1.0f / (1.0f + std::exp(-input)); // Sigmoid-based fuzzy logic
}
void BuddhiLogic::applyQuantumHeuristic(std::vector<float>& weights) {
    for(auto& w : weights) {
        w = std::sin(w * 3.14159f); // Quantum-inspired phase shift
    }
}
}