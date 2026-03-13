#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
#include "compute/VedicALU.h"
#include "compute/PingalaChandaSutras.h"

using namespace DivineEarthlyKernels::Compute;

std::vector<std::vector<uint64_t>> naivePascal(size_t n) {
    std::vector<std::vector<uint64_t>> triangle(n + 1);
    for (size_t i = 0; i <= n; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;
        for (size_t j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}

void runMatrixBenchmark() {
    const size_t N = 512;
    std::vector<float> A(N * N, 1.1f);
    std::vector<float> B(N * N, 2.2f);
    std::vector<float> C_naive(N * N, 0.0f);
    std::vector<float> C_vedic(N * N, 0.0f);

    std::cout << "[Benchmark] Matrix Multiplication (Size: " << N << "x" << N << ")" << std::endl;

    auto start_n = std::chrono::high_resolution_clock::now();
    VedicALU::matrixMultiplyStandard(A.data(), B.data(), C_naive.data(), N);
    auto end_n = std::chrono::high_resolution_clock::now();
    double time_naive = std::chrono::duration<double, std::milli>(end_n - start_n).count();

    auto start_v = std::chrono::high_resolution_clock::now();
    VedicALU::matrixMultiplyVedic(A.data(), B.data(), C_vedic.data(), N);
    auto end_v = std::chrono::high_resolution_clock::now();
    double time_vedic = std::chrono::duration<double, std::milli>(end_v - start_v).count();

    std::cout << "| Algorithm | Naive (ms) | Vedic (ms) | Speedup |" << std::endl;
    std::cout << "|-----------|------------|------------|---------|" << std::endl;
    std::cout << "| MatMul    | " << std::setw(10) << time_naive << " | " << std::setw(10) << time_vedic << " | " << (time_naive / time_vedic) << "x |" << std::endl << std::endl;
}

void runPascalBenchmark() {
    const size_t rows = 30;
    std::cout << "[Benchmark] Meru Prastara (Rows: " << rows << ")" << std::endl;

    auto start_n = std::chrono::high_resolution_clock::now();
    auto res_n = naivePascal(rows);
    auto end_n = std::chrono::high_resolution_clock::now();
    double time_naive = std::chrono::duration<double, std::milli>(end_n - start_n).count();

    auto start_v = std::chrono::high_resolution_clock::now();
    auto res_v = PingalaChandaSutras::generateMeruPrastara(rows);
    auto end_v = std::chrono::high_resolution_clock::now();
    double time_vedic = std::chrono::duration<double, std::milli>(end_v - start_v).count();

    std::cout << "| Algorithm | Naive (ms) | Vedic (ms) | Speedup |" << std::endl;
    std::cout << "|-----------|------------|------------|---------|" << std::endl;
    std::cout << "| Pascal    | " << std::setw(10) << time_naive << " | " << std::setw(10) << time_vedic << " | " << (time_naive / time_vedic) << "x |" << std::endl;
}

int main() {
    std::cout << "--- VEDIC KERNEL PERFORMANCE COMPARISON SUITE ---" << std::endl;
    runMatrixBenchmark();
    runPascalBenchmark();
    return 0;
}