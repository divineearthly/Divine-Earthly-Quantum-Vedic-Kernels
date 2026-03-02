
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

// Symbol for Urdhva Tiryakbhyam matrix multiplication
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

// Symbol for Paravartya Yojayet matrix inversion
void paravartya_3x3_inverse_c(const double* A, double* invA) {
    double det = A[0]*(A[4]*A[8] - A[5]*A[7]) - 
                 A[1]*(A[3]*A[8] - A[5]*A[6]) + 
                 A[2]*(A[3]*A[7] - A[4]*A[6]);
    double invDet = (det != 0) ? 1.0 / det : 0;
    invA[0] = (A[4]*A[8] - A[5]*A[7]) * invDet;
    invA[1] = (A[2]*A[7] - A[1]*A[8]) * invDet;
    invA[2] = (A[1]*A[5] - A[2]*A[4]) * invDet;
    invA[3] = (A[5]*A[6] - A[3]*A[8]) * invDet;
    invA[4] = (A[0]*A[8] - A[2]*A[6]) * invDet;
    invA[5] = (A[3]*A[2] - A[0]*A[5]) * invDet;
    invA[6] = (A[3]*A[7] - A[4]*A[6]) * invDet;
    invA[7] = (A[6]*A[1] - A[0]*A[7]) * invDet;
    invA[8] = (A[0]*A[4] - A[3]*A[1]) * invDet;
}

// Symbol for Nikhilam base shifting (added to fix current linker error)
void nikhilam_base_shift_c(double* data, size_t n, double shift) {
    for (size_t i = 0; i < n; ++i) {
        data[i] += shift;
    }
}

#ifdef __cplusplus
}
#endif
