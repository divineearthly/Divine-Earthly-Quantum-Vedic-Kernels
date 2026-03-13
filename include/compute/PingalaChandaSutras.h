#ifndef PINGALA_CHANDA_SUTRAS_H
#define PINGALA_CHANDA_SUTRAS_H

#include <iostream>
#include <vector>
#include <cstdint>

namespace DivineEarthlyKernels::Compute {

/**
 * @brief Level 6 - Pingala's Chanda Sutras: The Science of Verse and Combinatorics
 * Implements Meru Prastara (Pascal's Triangle) and binary logic for Edge AI kernels.
 */
class PingalaChandaSutras {
public:
    /**
     * @brief Generates a specific row of Meru Prastara (Pascal's Triangle).
     */
    static std::vector<uint64_t> generateMeruPrastara(size_t n);

    /**
     * @brief Calculates binary combinatorics nCr.
     */
    static uint64_t getBinaryCombinatorics(uint32_t n, uint32_t k);

    /**
     * @brief Utility: Count set bits using bitwise shifts.
     */
    static uint8_t countSetBits(uint32_t n) {
        uint8_t count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    /**
     * @brief Utility: Optimized bitwise XOR.
     */
    static uint32_t bitwiseXOR(uint32_t a, uint32_t b) {
        return a ^ b;
    }
};

}
#endif