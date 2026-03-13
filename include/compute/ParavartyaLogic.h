#ifndef PARAVARTYA_LOGIC_H
#define PARAVARTYA_LOGIC_H

#include <vector>

class ParavartyaLogic {
public:
    static float fastDivide(float numerator, float denominator);
    static void normalize(std::vector<float>& data, float factor);
};
#endif