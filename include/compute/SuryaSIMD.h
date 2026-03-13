#ifndef SURYA_SIMD_H
#define SURYA_SIMD_H

#include <vector>
#include <immintrin.h>
#include <cmath>

namespace DivineEarthlyKernels::Compute {

class SuryaSIMD {
public:
    // Vedic Jya Table (24 segments of 90 degrees)
    static inline const float JyaTable[25] = {
        0.0000f, 0.0654f, 0.1305f, 0.1951f, 0.2588f, 0.3214f, 0.3827f, 0.4423f, 
        0.5000f, 0.5556f, 0.6088f, 0.6593f, 0.7071f, 0.7518f, 0.7934f, 0.8315f, 
        0.8660f, 0.8973f, 0.9239f, 0.9469f, 0.9659f, 0.9808f, 0.9914f, 0.9979f, 1.0000f
    };

    /**
     * @brief Vectorized Sine calculation using Vedic Tables and AVX2
     * Processes 8 floats at once.
     */
    static void calculateJyaAVX(const float* angles_rad, float* results, size_t count) {
        // Step size for 90 degrees / 24 segments
        const float step = 1.570796f / 24.0f;
        __m256 v_step_inv = _mm256_set1_ps(1.0f / step);

        for (size_t i = 0; i < count; i += 8) {
            __m256 v_angles = _mm256_loadu_ps(&angles_rad[i]);
            
            // Calculate segment index
            __m256 v_idx_f = _mm256_mul_ps(v_angles, v_step_inv);
            __m256i v_idx = _mm256_cvttps_epi32(v_idx_f);

            // For this SIMD demo, we use a simple horizontal gather/interpolation
            // In a full production kernel, we'd use _mm256_i32gather_ps
            alignas(32) int indices[8];
            alignas(32) float fractions[8];
            _mm256_store_si256((__m256i*)indices, v_idx);
            _mm256_store_ps(fractions, _mm256_sub_ps(v_idx_f, _mm256_cvtepi32_ps(v_idx)));

            for (int j = 0; j < 8; ++j) {
                int idx = indices[j] % 24;
                results[i + j] = JyaTable[idx] + fractions[j] * (JyaTable[idx+1] - JyaTable[idx]);
            }
        }
    }
};

}
#endif
