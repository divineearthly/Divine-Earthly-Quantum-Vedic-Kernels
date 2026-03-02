
#include <stddef.h>

// Portable implementation of the Vedic-Quantum reconstruction kernel
// This allows the compiler to auto-vectorize safely across different runner architectures
void reconstruct_kernel(const double* X, const double* Y, const double* Z, 
                        double* out, size_t n, 
                        double b00, double b10, double b20) {
    for (size_t i = 0; i < n; ++i) {
        // Urdhva Tiryakbhyam cross-product logic implemented with standard loops
        double rx = X[i] * b00;
        rx += Y[i] * b10;
        rx += Z[i] * b20;
        out[i] = rx;
    }
}
