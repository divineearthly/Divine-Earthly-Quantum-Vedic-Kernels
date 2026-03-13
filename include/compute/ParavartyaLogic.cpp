#include "compute/ParavartyaLogic.h"
#include <vector>

float ParavartyaLogic::fastDivide(float numerator, float denominator) {
    if (denominator == 0) return 0.0f;
    return numerator * (1.0f / denominator);
}

void ParavartyaLogic::normalize(std::vector<float>& data, float factor) {
    float inv_factor = fastDivide(1.0f, factor);
    for(auto& val : data) val *= inv_factor;
}
