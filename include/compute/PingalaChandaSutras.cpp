#include "PingalaChandaSutras.h"

namespace DivineEarthlyKernels::Compute {

/**
 * Generates the n-th row of Pascal's Triangle (Meru Prastara).
 * nCr = (n-1)C(r-1) + (n-1)Cr
 */
std::vector<uint64_t> PingalaChandaSutras::generateMeruPrastara(size_t n) {
    std::vector<uint64_t> row;
    uint64_t C = 1;
    for (size_t k = 1; k <= n; ++k) {
        row.push_back(C);
        C = C * (n - k) / k;
    }
    return row;
}

/**
 * Efficiently calculates nCr using the property nCr = nC(n-k).
 */
uint64_t PingalaChandaSutras::getBinaryCombinatorics(uint32_t n, uint32_t k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    uint64_t res = n;
    for (uint32_t i = 2; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

} // namespace DivineEarthlyKernels::Compute
