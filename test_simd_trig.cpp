#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "compute/SuryaSIMD.h"

using namespace DivineEarthlyKernels::Compute;

int main() {
    const size_t N = 800000; // Large workload to test SIMD throughput
    std::vector<float> angles(N, 0.785f);
    std::vector<float> results(N, 0.0f);

    std::cout << "--- SURYA SIDDHANTA SIMD BENCHMARK ---\n";
    
    auto start = std::chrono::high_resolution_clock::now();
    SuryaSIMD::calculateJyaAVX(angles.data(), results.data(), N);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> diff = end - start;
    std::cout << "Processed " << N << " angles in: " << diff.count() << " ms\n";
    std::cout << "Throughput: " << (N / diff.count()) / 1000.0 << " Million Ops/sec\n";
    std::cout << "Sample Result [sin(0.785)]: " << results[0] << " (Standard: 0.7071)\n";

    return 0;
}
