#include "compute/NikhilamMath.h"
#include <cstdint>

uint64_t NikhilamMath::multiply(uint64_t a, uint64_t b, uint64_t base) {
    // Formula: (Base + D1)(Base + D2) = (Base + D1 + D2) | (D1 * D2)
    int64_t d1 = static_cast<int64_t>(a) - static_cast<int64_t>(base);
    int64_t d2 = static_cast<int64_t>(b) - static_cast<int64_t>(base);

    uint64_t left_part = static_cast<uint64_t>(static_cast<int64_t>(a) + d2);
    uint64_t right_part = static_cast<uint64_t>(d1 * d2);

    return (left_part * base) + right_part;
}
