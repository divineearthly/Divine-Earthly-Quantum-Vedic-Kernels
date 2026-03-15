#include <iostream>
#include <chrono>
#include <vector>
#include "include/compute/VedicMatrixBatch.h"

int main() {
    const int TOTAL_MATRICES = 1000000; // 1 Million matrices
    std::vector<int> A(TOTAL_MATRICES * 4, 5);
    std::vector<int> B(TOTAL_MATRICES * 4, 3);
    std::vector<int> C(TOTAL_MATRICES * 4, 0);

    auto start = std::chrono::high_resolution_clock::now();
    
    // Process in batches of 4 matrices
    for(int i = 0; i < TOTAL_MATRICES; i += 4) {
        VedicMatrixBatch::multiply2x2_x4(&A[i*4], &B[i*4], &C[i*4]);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff = end - start;

    std::cout << "--- BATCH SIMD VEDIC BENCHMARK ---\n";
    std::cout << "Processed " << TOTAL_MATRICES << " matrices in " << diff.count() << " ms\n";
    std::cout << "Sample Result: " << C[0] << " (Expected 15 for scalar simplification)\n";

    return 0;
}
