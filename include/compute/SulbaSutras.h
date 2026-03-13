#ifndef SULBA_SUTRAS_H
#define SULBA_SUTRAS_H

#include <cstdint> // For uint16_t, uint32_t
#include <iostream>
#include <cmath>   // For std::sqrt, only if truly needed, but aiming for integer math

namespace DivineEarthlyKernels {
namespace Compute {

// Level 4: Sulba Sutras (Geometry & Algorithmic Framework)
// Authors: Baudhayana, Apastamba, Katyayana (Appendices to the Yajurveda)
// Structure: Ancient algorithms for complex geometry and spatial calculations without heavy floating-point math.
// Application: Low-CPU spatial arrays, precise dimensional computing.
class SulbaSutras {
public:
    // Calculates the area of a rectangle using integer arithmetic.
    // Simulates the precise measurement and construction principles of Sulba Sutras.
    static constexpr uint32_t calculateRectangleArea(uint16_t length, uint16_t width) {
        std::cout << "[Sulba] Calculating rectangle area for length " << length << " and width " << width << ".\n";
        return static_cast<uint32_t>(length) * width;
    }

    // Checks if three integer sides form a right-angled triangle using Pythagorean theorem.
    // Emphasizes integer-based geometric validation, avoiding floating-point inaccuracies.
    static constexpr bool isRightTriangle(uint32_t a, uint32_t b, uint32_t c) {
        std::cout << "[Sulba] Checking for right triangle with sides " << a << ", " << b << ", " << c << ".\n";
        // To avoid overflow for large numbers, cast to uint64_t before squaring.
        // Note: For very large numbers, even uint64_t might overflow if a,b,c are near its max and squared.
        // For typical use cases with uint32_t sides, this should be fine.
        uint64_t a_sq = static_cast<uint64_t>(a) * a;
        uint64_t b_sq = static_cast<uint64_t>(b) * b;
        uint64_t c_sq = static_cast<uint64_t>(c) * c;

        return (a_sq + b_sq == c_sq) || (a_sq + c_sq == b_sq) || (b_sq + c_sq == a_sq);
    }

    // Calculates the square root of a perfect square using integer approximation (Babylonian method).
    // This avoids floating-point types for integer-based square roots.
    static uint32_t integerSquareRoot(uint32_t n) {
        if (n == 0) return 0;
        uint32_t x = n; // Initial guess
        uint32_t y = 1;
        while (x > y) {
            x = (x + y) / 2;
            y = n / x;
        }
        std::cout << "[Sulba] Integer square root of " << n << " is approximately " << x << ".\n";
        return x; // Will return floor(sqrt(n)) for non-perfect squares
    }

    // A simplified example of constructing a square from a rope (perimeter).
    // Demonstrates algorithmic thinking for geometric construction.
    static constexpr uint16_t constructSquareSideFromPerimeter(uint16_t perimeter) {
        std::cout << "[Sulba] Constructing square side from perimeter " << perimeter << ".\n";
        if (perimeter % 4 != 0) {
            std::cout << "[Sulba] Warning: Perimeter not perfectly divisible by 4. Assuming integer side.\n";
        }
        return perimeter / 4;
    }
};

} // namespace Compute
} // namespace DivineEarthlyKernels

#endif // SULBA_SUTRAS_H
