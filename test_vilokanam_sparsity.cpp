#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <random>
#include "compute/VedicALU.h"
#include "compute/VilokanamSparsity.h"

using namespace DivineEarthlyKernels::Compute;

void generateSparseMatrix(std::vector<float>& matrix, size_t N, float sparsity_ratio) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    for (size_t i = 0; i < N * N; ++i) {
        if (dis(gen) < sparsity_ratio) {
            matrix[i] = 0.0f;
        } else {
            matrix[i] = (float)dis(gen) * 10.0f; // Non-zero value
        }
    }
}

int main() {
    const size_t N = 256; // Matrix size N x N
    const float SPARSITY_RATIO = 0.60f; // 60% sparse
    const int RUNS = 5; // Number of runs for averaging

    std::vector<float> A(N * N);
    generateSparseMatrix(A, N, SPARSITY_RATIO);
    std::vector<float> B(N * N, 1.5f); // Dense matrix B
    std::vector<float> C_vedic(N * N, 0.0f);
    std::vector<float> C_vilokanam(N * N, 0.0f);

    std::cout << "--- VILOKANAM SPARSITY BENCHMARK ---" << std::endl;
    std::cout << "Matrix Size: " << N << "x" << N << std::endl;
    std::cout << "Sparsity Ratio (Matrix A): " << SPARSITY_RATIO * 100 << "%" << std::endl;
    std::cout << "Number of benchmark runs: " << RUNS << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    double total_time_vedic = 0.0;
    double total_time_vilokanam = 0.0;

    // Benchmark VedicALU
    for (int r = 0; r < RUNS; ++r) {
        std::fill(C_vedic.begin(), C_vedic.end(), 0.0f);
        auto start = std::chrono::high_resolution_clock::now();
        VedicALU::matrixMultiplyVedic(A.data(), B.data(), C_vedic.data(), N);
        auto end = std::chrono::high_resolution_clock::now();
        total_time_vedic += std::chrono::duration<double, std::milli>(end - start).count();
    }
    double avg_time_vedic = total_time_vedic / RUNS;
    std::cout << "
[VedicALU] Average Execution Time: " << avg_time_vedic << " ms" << std::endl;

    // Benchmark VilokanamSparsity
    for (int r = 0; r < RUNS; ++r) {
        std::fill(C_vilokanam.begin(), C_vilokanam.end(), 0.0f);
        auto start = std::chrono::high_resolution_clock::now();
        VilokanamSparsity::sparseMatrixMultiply(A.data(), B.data(), C_vilokanam.data(), N);
        auto end = std::chrono::high_resolution_clock::now();
        total_time_vilokanam += std::chrono::duration<double, std::milli>(end - start).count();
    }
    double avg_time_vilokanam = total_time_vilokanam / RUNS;
    std::cout << "[Vilokanam] Average Execution Time: " << avg_time_vilokanam << " ms" << std::endl;

    double speedup = avg_time_vedic / avg_time_vilokanam;
    std::cout << "
[Result] VilokanamSparsity is " << speedup << "x faster than VedicALU on sparse matrix." << std::endl;

    if (speedup >= 2.0) {
        std::cout << "[Success] Vilokanam meets the 2x speedup directive!" << std::endl;
    } else {
        std::cout << "[Needs Optimization] Vilokanam did not meet the 2x speedup directive." << std::endl;
    }

    // Optional: Verify correctness by comparing a few elements (ensure both produce same result)
    // For a large matrix, this is only a sanity check.
    size_t check_idx = N * N / 2;
    if (std::abs(C_vedic[check_idx] - C_vilokanam[check_idx]) < 1e-3) {
        std::cout << "[Verification] Sample element comparison PASSED. Value: " << C_vedic[check_idx] << std::endl;
    } else {
        std::cout << "[Verification] Sample element comparison FAILED. Vedic: " << C_vedic[check_idx] << ", Vilokanam: " << C_vilokanam[check_idx] << std::endl;
    }

    return 0;
}
