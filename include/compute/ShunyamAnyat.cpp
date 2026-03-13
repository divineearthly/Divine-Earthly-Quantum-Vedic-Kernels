#include "compute/ShunyamAnyat.h"
#include <vector>
#include <cmath>

void ShunyamAnyat::applyPruning(std::vector<float>& weights, float threshold) {
    for(auto& w : weights) {
        if (std::abs(w) < threshold) w = 0.0f;
    }
}
