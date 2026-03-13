#include "compute/SulbaSutras.h"
#include <cmath>

namespace DivineEarthlyKernels::Compute {
double SulbaSutras::BaudhayanaTheorem(double a, double b) {
    return std::sqrt(a*a + b*b);
}
double SulbaSutras::calculateAltarArea(double side) {
    return side * side; // Simplified Vedic square altar
}
}