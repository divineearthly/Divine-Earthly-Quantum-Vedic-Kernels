#ifndef VEDIC_ALU_H
#define VEDIC_ALU_H

#include <cstdint> // For uint16_t, etc.

namespace DivineEarthlyKernels {
namespace Compute {

// Level 1: Vedic Mathematics - Urdhva Tiryagbhyam (Vertically and Crosswise)
// This technique is highly efficient for multiplication, often reducing the number of
// partial products and therefore computational steps. It is particularly elegant
// when applied digit by digit, or in this case, segment by segment (e.g., 8-bit blocks).
//
// Level 21: The 13 Upa-Sutras (Corollaries)
// While a full implementation of all 13 Upa-Sutras is extensive, the principles
// of optimization and pattern recognition inherent in them guide the choice of
// algorithms for efficiency. Urdhva Tiryagbhyam itself can be seen as an application
// of such principles for multiplication. The focus here is on a general-purpose
// Urdhva Tiryagbhyam for binary numbers, leveraging bitwise operations for efficiency
// suitable for low-resource environments like mobile-first Termux deployments.

class VedicALU {
public:
    // Urdhva Tiryagbhyam Multiplier for uint16_t
    // This function implements the Vertically and Crosswise method for multiplying
    // two 16-bit unsigned integers. It effectively breaks down the 16-bit numbers
    // into two 8-bit 'digits' (high and low parts) and applies the Vedic principle.
    //
    // Let a = A_H * 2^8 + A_L
    // Let b = B_H * 2^8 + B_L
    //
    // Then a * b = (A_H * 2^8 + A_L) * (B_H * 2^8 + B_L)
    //            = A_H*B_H * (2^8)^2 + (A_H*B_L + A_L*B_H) * 2^8 + A_L*B_L
    //
    // This method calculates three partial products and sums them with appropriate
    // shifts and carry propagations, which is the essence of Urdhva Tiryagbhyam.
    static constexpr uint32_t urdhvaTiryagbhyamMultiply(uint16_t a, uint16_t b) {
        // We treat uint16_t as two 'digits' of uint8_t (base 2^8)
        uint8_t a_h = static_cast<uint8_t>(a >> 8); // High 8 bits of a
        uint8_t a_l = static_cast<uint8_t>(a & 0xFF); // Low 8 bits of a
        uint8_t b_h = static_cast<uint8_t>(b >> 8); // High 8 bits of b
        uint8_t b_l = static_cast<uint8_t>(b & 0xFF); // Low 8 bits of b

        // Step 1: Vertical product of LSBs (A_L * B_L)
        // This forms the lowest 8 bits of the result and generates a carry.
        uint32_t product_ll = static_cast<uint32_t>(a_l) * b_l;
        uint32_t carry0 = product_ll >> 8; // Carry to the next 'digit' position
        uint32_t part0 = product_ll & 0xFF; // Lowest 8 bits of the final result

        // Step 2: Crosswise products and add previous carry (A_H*B_L + A_L*B_H + carry0)
        // This forms the middle 8 bits of the result and generates a new carry.
        uint32_t cross_product_sum = static_cast<uint32_t>(a_h) * b_l +
                                     static_cast<uint32_t>(a_l) * b_h +
                                     carry0;
        uint32_t carry1 = cross_product_sum >> 8; // Carry to the most significant 'digit' position
        uint32_t part1 = cross_product_sum & 0xFF; // Middle 8 bits of the final result

        // Step 3: Vertical product of MSBs and add current carry (A_H*B_H + carry1)
        // This forms the most significant part of the result.
        uint32_t product_hh = static_cast<uint32_t>(a_h) * b_h + carry1;

        // Combine the parts to form the final 32-bit result
        // The parts are combined using bitwise OR and left shifts, as each 'part'
        // represents a segment of 8 bits in the final 32-bit product.
        // part0 occupies bits 0-7
        // part1 occupies bits 8-15
        // product_hh occupies bits 16-31 (or higher if product_hh itself exceeds 8 bits)
        return part0 | (part1 << 8) | (product_hh << 16);
    }

    // For illustrative purposes, an example of an Upa-Sutra inspired optimization
    // Ekadhikena Purvena (By one more than the previous one) - useful for squaring numbers ending in 5.
    // This demonstrates how specific patterns can be leveraged for faster calculation.
    static constexpr uint32_t squareEndingIn5(uint16_t n) {
        if (n % 10 != 5) {
            // If the number doesn't end in 5, fall back to standard multiplication
            // or the general urdhvaTiryagbhyamMultiply for a more 'Vedic' consistent approach.
            return static_cast<uint32_t>(n) * n;
        }
        uint16_t prev_digits = n / 10; // The part of the number preceding the '5'
        // The rule states: multiply the 'previous digits' by ('previous digits' + 1),
        // then append '25' to the result.
        uint32_t result_prefix = static_cast<uint32_t>(prev_digits) * (prev_digits + 1);
        return result_prefix * 100 + 25; // Equivalent to appending '25'
    }

    // Nikhilam Sutra Optimization for numbers near a base of 65536 (2^16)
    // Instead of heavy multiplication, we use bitwise left-shifts (<<)
    static inline constexpr uint32_t nikhilamMultiply(uint32_t a, uint32_t b) {
        // This implementation assumes numbers are slightly less than 2^16 (65536).
        // The full Nikhilam Sutra is more general, but this is an efficient
        // application for binary numbers near a power of two base.
        // If a and b are slightly less than 65536:
        // Let Base = 65536
        // a = Base - d_a
        // b = Base - d_b
        // a * b = (Base - d_a) * (Base - d_b)
        //       = Base * (Base - d_a - d_b) + d_a * d_b
        //       = Base * (a - d_b) + d_a * d_b
        // Where d_a = Base - a and d_b = Base - b are the deficiencies.
        uint32_t diffA = 65536 - a;
        uint32_t diffB = 65536 - b;

        // The 'Base * (a - d_b)' part is a left-shift by 16 bits.
        uint32_t part1 = (a - diffB) << 16; // (Base - d_a - d_b) * Base
        uint32_t part2 = diffA * diffB;     // Product of deficiencies

        return part1 + part2;
    }
};

} // namespace Compute
} // namespace DivineEarthlyKernels

#endif // VEDIC_ALU_H
