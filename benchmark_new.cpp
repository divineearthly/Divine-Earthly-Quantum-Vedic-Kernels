#include <iostream>
#include <chrono>
#include <vector>
#include "include/compute/VedicMath.h"
#include "include/compute/SriYantraArchitecture.h"

void run_benchmark() {
    VedicMath vm;
    SriYantra sy;

    auto start = std::chrono::high_resolution_clock::now();

    // Benchmark 1: 1 Million Vedic Math operations
    for(int i=0; i < 1000000; ++i) {
        vm.nikhilam(i % 10);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "[Benchmark] 1M Vedic Math Ops: " << diff.count() << "s\n";

    // Benchmark 2: 10,000 Sri Yantra Projections
    start = std::chrono::high_resolution_clock::now();
    for(int i=0; i < 10000; ++i) {
        sy.projectHolographic();
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "[Benchmark] 10K Sri Yantra Projections: " << diff.count() << "s (Includes I/O overhead)\n";
}

int main() {
    std::cout << "--- STARTING VEDIC PERFORMANCE AUDIT ---\n";
    run_benchmark();
    return 0;
}