#ifndef BUDDHI_LOGIC_H
#define BUDDHI_LOGIC_H

#include <vector>

namespace DivineEarthlyKernels::Compute {
class BuddhiLogic {
public:
    static float fuzzyInference(float input);
    static void applyQuantumHeuristic(std::vector<float>& weights);
};
}
#endif