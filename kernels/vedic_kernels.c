
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Portable implementation of the Vedic-Quantum reconstruction kernel
void reconstruct_kernel(const double* X, const double* Y, const double* Z, 
                        double* out, size_t n, 
                        double b00, double b10, double b20) {
    for (size_t i = 0; i < n; ++i) {
        out[i] = X[i] * b00 + Y[i] * b10 + Z[i] * b20;
    }
}

// Explicitly exported symbol for the C++ unified library
void urdhva_3x3_matmul_c(const double* A, const double* B, double* C) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double sum = 0;
            for (int k = 0; k < 3; k++) {
                sum += A[i * 3 + k] * B[k * 3 + j];
            }
            C[i * 3 + j] = sum;
        }
    }
}

#ifdef __cplusplus
}
#endif
