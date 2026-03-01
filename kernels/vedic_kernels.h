#ifndef VEDIC_KERNELS_H
#define VEDIC_KERNELS_H

#include <stddef.h>

/* Hardware-aware Dispatcher */
void urdhva_3x3_matmul_dispatch(const double* __restrict__ A, const double* __restrict__ B, double* __restrict__ res, size_t N);

/* AVX-512 Optimized Kernels (SoA Layout) */
void urdhva_3x3_matmul_avx512(const double* __restrict__ X, const double* __restrict__ Y, const double* __restrict__ Z,
                             const double* __restrict__ B,
                             double* __restrict__ resX, double* __restrict__ resY, double* __restrict__ resZ,
                             size_t N);

/* Standard Scalar Kernels */
void urdhva_3x3_matmul_c(const double* __restrict__ A, const double* __restrict__ B, double* __restrict__ res, size_t N);
void nikhilam_base_shift_c(const double* __restrict__ in, double* __restrict__ out, double base, size_t size);
int paravartya_3x3_inverse_c(const double* __restrict__ B, double* __restrict__ res);

#endif
