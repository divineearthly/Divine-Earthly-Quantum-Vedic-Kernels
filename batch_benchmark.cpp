#include <iostream>
#include <chrono>
#include <vector>
#include "include/compute/VedicMatrixBatch.h"

int main() {
    const int N = 1000000; // 1 Million batches of 4
    std::vector<int> A(N * 8, 5), B(N * 8, 2), C(N * 8, 0);

    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < N; ++i) {
        VedicMatrixBatch::multiply2x2_x4(&A[i*8], &B[i*8], &C[i*8]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> diff = end - start;
    std::cout << "[Sattva] Batch SIMD (AVX2) Time for 8M elements: " << diff.count() << " ms" << std::endl;
    return 0;
}
