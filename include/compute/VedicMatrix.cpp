#include "VedicMatrix.h"
#include <immintrin.h>
#include <iostream>

// Level 1: Urdhva-Tiryagbhyam via SIMD (AVX2)
void VedicMatrix::multiply2x2(const int A[2][2], const int B[2][2], int C[2][2]) {
    // Load elements into 128-bit SIMD registers
    __m128i row1A = _mm_set_epi32(A[0][1], A[0][0], A[0][1], A[0][0]);
    __m128i row2A = _mm_set_epi32(A[1][1], A[1][0], A[1][1], A[1][0]);
    __m128i colB  = _mm_set_epi32(B[1][1], B[0][1], B[1][0], B[0][0]);

    // Multiply packed 32-bit integers
    __m128i res1 = _mm_mullo_epi32(row1A, colB);
    __m128i res2 = _mm_mullo_epi32(row2A, colB);

    // Extract and sum to get the crosswise result
    int r1[4], r2[4];
    _mm_storeu_si128((__m128i*)r1, res1);
    _mm_storeu_si128((__m128i*)r2, res2);

    C[0][0] = r1[0] + r1[1];
    C[0][1] = r1[2] + r1[3];
    C[1][0] = r2[0] + r2[1];
    C[1][1] = r2[2] + r2[3];
}

void VedicMatrix::demonstrate() {
    int A[2][2] = {{5, 2}, {3, 4}};
    int B[2][2] = {{1, 6}, {7, 8}};
    int C[2][2] = {{0, 0}, {0, 0}};
    multiply2x2(A, B, C);
    std::cout << "[Sattva] Vedic Matrix Result (2x2):\n";
    for(int i=0; i<2; ++i) {
        for(int j=0; j<2; ++j) std::cout << C[i][j] << " ";
        std::cout << "\n";
    }
}
