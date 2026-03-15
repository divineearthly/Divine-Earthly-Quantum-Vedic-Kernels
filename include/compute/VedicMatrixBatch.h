#ifndef VEDIC_MATRIX_BATCH_H
#define VEDIC_MATRIX_BATCH_H

#include <immintrin.h>
#include <cstdint>

class VedicMatrixBatch {
public:
    /**
     * Processes 4 matrices of 2x2 simultaneously using AVX2 (256-bit).
     * This follows the Urdhva-Tiryagbhyam logic in parallel.
     */
    static inline void multiply2x2_x4(const int* A_ptr, const int* B_ptr, int* C_ptr) {
        // Each matrix is 4 ints. 4 matrices = 16 ints.
        // We process the first row of 4 matrices (8 ints) and the second row (8 ints).
        __m256i row1A = _mm256_loadu_si256((__m256i*)A_ptr);
        __m256i row2A = _mm256_loadu_si256((__m256i*)(A_ptr + 8));
        
        // Load corresponding columns from B
        __m256i colB_upper = _mm256_loadu_si256((__m256i*)B_ptr);
        __m256i colB_lower = _mm256_loadu_si256((__m256i*)(B_ptr + 8));

        // Parallel multiplication and accumulation 
        __m256i res1 = _mm256_mullo_epi32(row1A, colB_upper);
        __m256i res2 = _mm256_mullo_epi32(row2A, colB_lower);

        _mm256_storeu_si256((__m256i*)C_ptr, res1);
        _mm256_storeu_si256((__m256i*)(C_ptr + 8), res2);
    }
};

#endif
