#include "include/compute/BuddhiLogic.h"
#include <cmath> // For std::tanh
#include <random> // For std::mt19937 and std::uniform_real_distribution
#include <iostream>

namespace DivineEarthlyKernels::Compute {

// Level 4: Buddhi - The Discerning, Decisive Faculty
// Application: Higher-order logic, fuzzy decision making, and heuristic adjustments.

// Simulates a fuzzy logic gate (e.g., for confidence scoring).
float BuddhiLogic::fuzzyInference(float input) {
    // A simple sigmoid-like function (tanh) to map any input to a range [-1, 1]
    // representing a decision from 'strong reject' to 'strong accept'.
    return std::tanh(input);
}

// Simulates a heuristic adjustment based on a pseudo-quantum principle.
void BuddhiLogic::applyQuantumHeuristic(std::vector<float>& weights) {
    // This is a conceptual simulation, not a real quantum algorithm.
    // It represents applying a 'quantum leap' in thinking to escape a local minimum.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-0.1, 0.1);

    std::cout << "[Buddhi] Applying quantum heuristic jump to weights...\n";
    for (auto& weight : weights) {
        // Add a small random value to each weight, simulating a sudden insight or shift in perspective.
        weight += dis(gen);
    }
}

} // namespace DivineEarthlyKernels::Compute
