#include "include/compute/ShunyamAnyat.h"
#include <iostream>

// Level 3 Sutra: Shunyam Anyat - "If one is in ratio, the other is zero"
// Application: Sparsity, pruning, solving simultaneous equations.

/**
 * @brief Applies pruning to a vector of weights.
 * This is a core concept in model compression. If a weight is below a
 * certain threshold, it is considered insignificant and set to zero ("Shunyam").
 * This creates sparsity, reducing computational load.
 */
void ShunyamAnyat::applyPruning(std::vector<float>& weights, float threshold) {
    int pruned_count = 0;
    for (float& weight : weights) {
        if (std::abs(weight) < threshold) {
            weight = 0.0f;
            pruned_count++;
        }
    }
    std::cout << "[ShunyamAnyat] Pruned " << pruned_count << " / " << weights.size() << " weights.\n";
}
