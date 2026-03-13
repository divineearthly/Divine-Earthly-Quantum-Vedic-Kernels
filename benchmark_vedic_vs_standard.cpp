#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "include/compute/VedicALU.h"

int main() {
    const size_t N = 512; // Test with 512x512 tensors
    std::vector<float> A(N * N, 1.0f);
    std::vector<float> B(N * N, 2.0f);
    std::vector<float> C_vedic(N * N, 0.0f);
    std::vector<float> C_std(N * N, 0.0f);

    std::cout << "--- VEDIC HPC ENGINE BENCHMARK ---\n";
    std::cout << "Tensor Size: " << N << "x" << N << " (" << (N*N*sizeof(float))/(1024*1024) << " MB)\n\n";

    // Benchmark Standard
    auto start_std = std::chrono::high_resolution_clock::now();
    VedicALU::matrixMultiplyStandard(A.data(), B.data(), C_std.data(), N);
    auto end_std = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff_std = end_std - start_std;

    // Benchmark Vedic (Urdhva Tiryak)
    auto start_vedic = std::chrono::high_resolution_clock::now();
    VedicALU::matrixMultiplyVedic(A.data(), B.data(), C_vedic.data(), N);
    auto end_vedic = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff_vedic = end_vedic - start_vedic;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "[Standard] Execution Time: " << diff_std.count() << " ms\n";
    std::cout << "[Vedic UT]  Execution Time: " << diff_vedic.count() << " ms\n";
    
    double speedup = diff_std.count() / diff_vedic.count();
    std::cout << "\n[Result] Vedic UT is " << speedup << "x faster than Standard Naive Implementation.\n";

    return 0;
}
