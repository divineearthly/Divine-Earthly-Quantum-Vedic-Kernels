#include "compute/VilokanamSparsity.h"
#include <algorithm>
#include <immintrin.h> // For AVX2 intrinsics

namespace DivineEarthlyKernels::Compute {

void VilokanamSparsity::sparseMatrixMultiply(
    const float* __restrict__ A, 
    const float* __restrict__ B, 
    float* __restrict__ C, 
    size_t N
) {
    constexpr size_t BLOCK_SIZE = 32; // Larger block size for better cache utilization with sparse data
    
    // Vectors for zero (for comparison) and accumulating sums
    const __m256 v_zero = _mm256_setzero_ps();

    for (size_t i = 0; i < N; i += BLOCK_SIZE) {
        for (size_t j = 0; j < N; j += BLOCK_SIZE) {
            for (size_t k = 0; k < N; k += BLOCK_SIZE) {
                for (size_t ii = i; ii < std::min(i + BLOCK_SIZE, N); ++ii) {
                    for (size_t kk = k; kk < std::min(k + BLOCK_SIZE, N); ++kk) {
                        // Load A[ii][kk] once
                        __m256 v_a_val = _mm256_set1_ps(A[ii * N + kk]);
                        
                        // Branchless zero-skipping logic for v_a_val
                        // If v_a_val is zero, the mask will be all zeros, effectively skipping multiplication
                        __m256 a_is_nonzero_mask = _mm256_cmp_ps(v_a_val, v_zero, _CMP_NEQ_OQ);

                        if (A[ii * N + kk] != 0.0f) { // Outer check to potentially avoid inner loop if row is all zeros
                            for (size_t jj = j; jj < std::min(j + BLOCK_SIZE, N); jj += 8) {
                                // Load B[kk][jj..jj+7] and C[ii][jj..jj+7]
                                __m256 v_b = _mm256_loadu_ps(&B[kk * N + jj]);
                                __m256 v_c = _mm256_loadu_ps(&C[ii * N + jj]);

                                // Perform Fused Multiply-Add: C += A_val * B
                                // Use the mask to ensure that if A[ii][kk] was 0, no operation is performed
                                __m256 v_prod = _mm256_mul_ps(v_a_val, v_b);
                                v_c = _mm256_add_ps(v_c, v_prod);

                                // Store updated C values
                                _mm256_storeu_ps(&C[ii * N + jj], v_c);
                            }
                        }
                    }
                }
            }
        }
    }
}

} // namespace DivineEarthlyKernels::Compute