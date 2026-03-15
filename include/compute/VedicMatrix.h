#ifndef VEDIC_MATRIX_H
#define VEDIC_MATRIX_H

#include <vector>
#include <iostream>

class VedicMatrix {
public:
    // Level 1: Urdhva-Tiryagbhyam (Vertically and Crosswise)
    // Optimized for 2x2 sub-matrices
    static void multiply2x2(const int A[2][2], const int B[2][2], int C[2][2]);

    static void demonstrate();
};

#endif
