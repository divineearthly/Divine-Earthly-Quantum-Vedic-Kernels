#ifndef SHUNYAM_ANYAT_H
#define SHUNYAM_ANYAT_H

#include <vector>

class ShunyamAnyat {
public:
    static void applyPruning(std::vector<float>& weights, float threshold);
};
#endif