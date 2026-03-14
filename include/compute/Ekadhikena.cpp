#include "include/compute/Ekadhikena.h"

// Level 2: Ekadhikena Purvena - "By one more than the previous"
// Application: Predictive coding, auto-increment/decrement operations.

void Ekadhikena::generateSeries(std::vector<float>& series, size_t length, float start_val) {
    series.resize(length);
    series[0] = start_val;
    for (size_t i = 1; i < length; ++i) {
        // Each subsequent element is based on the previous one, conceptually simple.
        series[i] = series[i-1] * 1.05f; // Example: a 5% growth
    }
}
