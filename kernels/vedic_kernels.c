#include "vedic_kernels.h"
#include <math.h>
#include <immintrin.h>

/**
 * @brief AVX-512 Optimized Urdhva Tiryakbhyam Matmul (Flexible SoA Layout)
 *
 * Uses unaligned loads (_mm512_loadu_pd) to support arbitrary pointers.
 */
void urdhva_3x3_matmul_avx512(const double* __restrict__ X, const double* __restrict__ Y, const double* __restrict__ Z,
                             const double* __restrict__ B,
                             double* __restrict__ resX, double* __restrict__ resY, double* __restrict__ resZ,
                             size_t N) {

    __m512d b00 = _mm512_set1_pd(B[0]); __m512d b01 = _mm512_set1_pd(B[1]); __m512d b02 = _mm512_set1_pd(B[2]);
    __m512d b10 = _mm512_set1_pd(B[3]); __m512d b11 = _mm512_set1_pd(B[4]); __m512d b12 = _mm512_set1_pd(B[5]);
    __m512d b20 = _mm512_set1_pd(B[6]); __m512d b21 = _mm512_set1_pd(B[7]); __m512d b22 = _mm512_set1_pd(B[8]);

    size_t i = 0;
    for (; i <= N - 8; i += 8) {
        // Switched to unaligned loads for safety with arbitrary pointers
        __m512d x = _mm512_loadu_pd(&X[i]);
        __m512d y = _mm512_loadu_pd(&Y[i]);
        __m512d z = _mm512_loadu_pd(&Z[i]);

        __m512d rx = _mm512_mul_pd(x, b00);
        rx = _mm512_fmadd_pd(y, b10, rx);
        rx = _mm512_fmadd_pd(z, b20, rx);
        _mm512_storeu_pd(&resX[i], rx); // Also use unaligned store

        __m512d ry = _mm512_mul_pd(x, b01);
        ry = _mm512_fmadd_pd(y, b11, ry);
        ry = _mm512_fmadd_pd(z, b21, ry);
        _mm512_storeu_pd(&resY[i], ry);

        __m512d rz = _mm512_mul_pd(x, b02);
        rz = _mm512_fmadd_pd(y, b12, rz);
        rz = _mm512_fmadd_pd(z, b22, rz);
        _mm512_storeu_pd(&resZ[i], rz);
    }

    for (; i < N; ++i) {
        resX[i] = (X[i] * B[0]) + (Y[i] * B[3]) + (Z[i] * B[6]);
        resY[i] = (X[i] * B[1]) + (Y[i] * B[4]) + (Z[i] * B[7]);
        resZ[i] = (X[i] * B[2]) + (Y[i] * B[5]) + (Z[i] * B[8]);
    }
}

void urdhva_3x3_matmul_c(const double* __restrict__ A, const double* __restrict__ B, double* __restrict__ res, size_t N) {
    const double b00 = B[0], b01 = B[1], b02 = B[2];
    const double b10 = B[3], b11 = B[4], b12 = B[5];
    const double b20 = B[6], b21 = B[7], b22 = B[8];
    for (size_t i = 0; i < N; ++i) {
        size_t offset = i * 3;
        res[offset + 0] = (A[offset + 0] * b00) + (A[offset + 1] * b10) + (A[offset + 2] * b20);
        res[offset + 1] = (A[offset + 0] * b01) + (A[offset + 1] * b11) + (A[offset + 2] * b21);
        res[offset + 2] = (A[offset + 0] * b02) + (A[offset + 1] * b12) + (A[offset + 2] * b22);
    }
}

void nikhilam_base_shift_c(const double* __restrict__ in, double* __restrict__ out, double base, size_t size) {
    for (size_t i = 0; i < size; ++i) out[i] = base - in[i];
}

int paravartya_3x3_inverse_c(const double* __restrict__ B, double* __restrict__ res) {
    const double b00 = B[0], b01 = B[1], b02 = B[2];
    const double b10 = B[3], b11 = B[4], b12 = B[5];
    const double b20 = B[6], b21 = B[7], b22 = B[8];
    double det = b00 * (b11 * b22 - b12 * b21) - b01 * (b10 * b22 - b12 * b20) + b02 * (b10 * b21 - b11 * b20);
    if (fabs(det) < 1e-15) return 0;
    double invDet = 1.0 / det;
    res[0] = (b11 * b22 - b12 * b21) * invDet; res[1] = (b02 * b21 - b01 * b22) * invDet; res[2] = (b01 * b12 - b02 * b11) * invDet;
    res[3] = (b12 * b20 - b10 * b22) * invDet; res[4] = (b00 * b22 - b02 * b20) * invDet; res[5] = (b10 * b02 - b00 * b12) * invDet;
    res[6] = (b10 * b21 - b11 * b20) * invDet; res[7] = (b20 * b01 - b00 * b21) * invDet; res[8] = (b00 * b11 - b10 * b01) * invDet;
    return 1;
}
