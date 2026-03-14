#include "include/compute/ParavartyaLogic.h"
#include <stdexcept>

// Level 3 Sutra: Paravartya Yojayet - "Transpose and Apply"
// Application: Inversion, normalization, division, and solving simple equations.

/**
 * @brief Fast division approximation.
 * The sutra suggests that for certain divisors, you can replace division with
 * a series of simpler operations (multiplication, shifts).
 * This is a conceptual example: approximating 1/D to turn N/D into N * (1/D).
 * Real-world examples are like Fast Inverse Square Root.
 */
float ParavartyaLogic::fastDivide(float numerator, float denominator) {
    if (denominator == 0.0f) {
        throw std::runtime_error("Division by zero in ParavartyaLogic");
    }
    // Simple approximation: use multiplication by the reciprocal.
    // In hardware, this could be a lookup table + refinement.
    return numerator * (1.0f / denominator);
}

/**
 * @brief Normalization by applying the inverse of a factor.
 * Instead of dividing every element by 'factor', we multiply by its reciprocal.
 * This is a direct application of "Transpose and Apply" where division is
 * transposed into multiplication.
 */
void ParavartyaLogic::normalize(std::vector<float>& data, float factor) {
    if (factor == 0.0f) return;
    float inverse_factor = 1.0f / factor;
    for (float& val : data) {
        val *= inverse_factor;
    }
}
