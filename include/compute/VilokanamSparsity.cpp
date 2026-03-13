#include "compute/VilokanamSparsity.h"
#include <algorithm>
#include <immintrin.h> 

namespace DivineEarthlyKernels::Compute {

void VilokanamSparsity::sparseMatrixMultiply(
    const float* __restrict__ A, 
    const float* __restrict__ B, 
    float* __restrict__ C, 
    size_t N
) {
    // Row-major sparse accumulation with 2x unrolling and pointer arithmetic optimization
    for (size_t i = 0; i < N; ++i) {
        const float* row_A = &A[i * N];
        float* row_C = &C[i * N];

        for (size_t k = 0; k < N; ++k) {
            float a_val = row_A[k];

            // Level 14 Vilokanam Logic: Skip zeros immediately
            if (a_val == 0.0f) continue;

            __m256 v_a = _mm256_set1_ps(a_val);
            const float* row_B = &B[k * N];
            
            // Inner SIMD loop: Unrolled to maximize throughput
            for (size_t j = 0; j < N; j += 16) {
                _mm256_storeu_ps(&row_C[j], _mm256_add_ps(_mm256_loadu_ps(&row_C[j]), _mm256_mul_ps(v_a, _mm256_loadu_ps(&row_B[j]))));
                _mm256_storeu_ps(&row_C[j + 8], _mm256_add_ps(_mm256_loadu_ps(&row_C[j + 8]), _mm256_mul_ps(v_a, _mm256_loadu_ps(&row_B[j + 8]))));
            }
        }
    }
}

} // namespace DivineEarthlyKernels::Compute