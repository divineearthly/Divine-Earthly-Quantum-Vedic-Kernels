#include "SuryaSiddhanta.h"
#include <cmath>

namespace DivineEarthlyKernels::Compute {
double SuryaSiddhanta::calculateJya(double angle_rad) {
    // Taylor approximation for Sine (Ancient Jya)
    return angle_rad - (std::pow(angle_rad, 3)/6.0);
}
double SuryaSiddhanta::calculateKotiJya(double angle_rad) {
    return 1.0 - (std::pow(angle_rad, 2)/2.0);
}
}