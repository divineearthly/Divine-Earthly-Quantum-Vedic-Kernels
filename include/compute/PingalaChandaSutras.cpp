#include "compute/PingalaChandaSutras.h"
#include <vector>

namespace DivineEarthlyKernels::Compute {
    std::vector<uint64_t> PingalaChandaSutras::generateMeruPrastara(size_t n) {
        std::vector<uint64_t> row(n + 1, 1);
        for (size_t k = 1; k <= n / 2; ++k) {
            row[k] = row[n - k] = row[k - 1] * (n - k + 1) / k;
        }
        return row;
    }

    uint64_t PingalaChandaSutras::getBinaryCombinatorics(uint32_t n, uint32_t k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n / 2) k = n - k;
        uint64_t res = 1;
        for (uint32_t i = 1; i <= k; ++i) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }
}