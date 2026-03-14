#include "include/compute/NikhilamMath.h"
#include <iostream>

// Level 2 Sutra: Nikhilam Navatashcaramam Dashatah
// "All from 9 and the Last from 10"
// Application: Optimized multiplication and subtraction, especially near a base (10, 100, etc.).

/**
 * @brief Multiplication using the Nikhilam Sutra.
 * This works best when numbers are close to a power-of-10 base.
 *
 * Example: 96 * 98 (Base 100)
 * 1. Find complements from base: 100-96=4, 100-98=2.
 * 2. Multiply complements: 4 * 2 = 8. This is the right part of the answer. (08)
 * 3. Subtract crosswise: 96 - 2 = 94 (or 98 - 4 = 94). This is the left part.
 * 4. Result: 9408.
 *
 * @param a The first number.
 * @param b The second number.
 * @param base The power of 10 that 'a' and 'b' are close to.
 * @return The product of a and b.
 */
uint64_t NikhilamMath::multiply(uint64_t a, uint64_t b, uint64_t base) {
    // This implementation demonstrates the principle for numbers *below* the base.
    if (a < base && b < base) {
        uint64_t comp_a = base - a;
        uint64_t comp_b = base - b;
        uint64_t lhs = a - comp_b;
        uint64_t rhs = comp_a * comp_b;
        return lhs * base + rhs;
    }
    // A similar logic applies for numbers *above* the base (surplus).
    else if (a > base && b > base) {
        uint64_t surplus_a = a - base;
        uint64_t surplus_b = b - base;
        uint64_t lhs = a + surplus_b; // or b + surplus_a
        uint64_t rhs = surplus_a * surplus_b;
        return lhs * base + rhs;
    }
    // If numbers are not close to the base, this method is inefficient.
    // Fallback to standard multiplication for simplicity.
    std::cout << "[Nikhilam] Numbers not suitable for Nikhilam with the given base. Using standard multiplication.\n";
    return a * b;
}

/**
 * @brief Subtraction is fundamental. The Nikhilam sutra is famous for
 * simplifying subtraction by converting it to addition using complements.
 * For example, a - b becomes a + (complement of b).
 * The sutra "All from 9, last from 10" is the method to find the complement.
 * For a direct computation in C++, we just perform the subtraction.
 */
uint64_t NikhilamMath::subtract(uint64_t a, uint64_t b) {
    if (a < b) {
        std::cerr << "Warning: NikhilamMath::subtract result will be negative (undefined behavior for uint64_t).\n";
    }
    return a - b;
}
