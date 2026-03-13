#include "compute/Ekadhikena.h"
#include <vector>

void Ekadhikena::generateSeries(std::vector<float>& series, size_t length, float start_val) {
    series.resize(length);
    float current = start_val;
    for(size_t i = 0; i < length; ++i) {
        series[i] = current;
        current += 1.0f; // Ekadhikena Purvena: By One More than the Previous One
    }
}
