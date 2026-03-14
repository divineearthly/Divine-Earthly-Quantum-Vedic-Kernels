#include "include/compute/SulbaSutras.h"
#include <cmath>

namespace DivineEarthlyKernels::Compute {

// Level 1: Sulba Sutras - The Foundation of Geometry & Algorithm
// Application: Geometric calculations, memory layout, and spatial data structures.

double SulbaSutras::BaudhayanaTheorem(double a, double b) {
    return std::sqrt(a*a + b*b);
}

double SulbaSutras::calculateAltarArea(double side) {
    return side * side;
}

} // namespace DivineEarthlyKernels::Compute
