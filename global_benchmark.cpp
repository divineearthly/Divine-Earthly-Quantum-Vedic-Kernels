#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <string>
#include "compute/VedicALU.h"
#include "compute/NikhilamMath.h"
#include "compute/ParavartyaLogic.h"
#include "compute/PingalaChandaSutras.h"
#include "compute/Ekadhikena.h"
#include "nlp/PaniniAshtadhyayi.h"
#include "compute/SuryaSiddhanta.h"
#include "compute/BuddhiLogic.h"

using namespace DivineEarthlyKernels::Compute;
using namespace DivineEarthlyKernels::NLP;

template<typename Func>
double benchmark(Func f, int iterations = 100) {
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<iterations; ++i) f();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count() / iterations;
}

int main() {
    std::cout << "--- GLOBAL VEDIC KERNEL BENCHMARK SUITE ---\n";
    std::cout << std::fixed << std::setprecision(6);

    // Batch 1 & 2: MatMul
    double t1_std = benchmark([]() {
        const int N = 128; std::vector<float> A(N*N, 1.0f), B(N*N, 1.0f), C(N*N, 0.0f);
        VedicALU::matrixMultiplyStandard(A.data(), B.data(), C.data(), N);
    }, 10);
    double t1_vedic = benchmark([]() {
        const int N = 128; std::vector<float> A(N*N, 1.0f), B(N*N, 1.0f), C(N*N, 0.0f);
        VedicALU::matrixMultiplyVedic(A.data(), B.data(), C.data(), N);
    }, 10);

    // Batch 3: Pascal
    double t3_std = benchmark([]() {
        int n = 20; std::vector<std::vector<uint64_t>> tri(n+1);
        for(int i=0; i<=n; ++i) { tri[i].resize(i+1); tri[i][0]=tri[i][i]=1;
        for(int j=1; j<i; ++j) tri[i][j] = tri[i-1][j-1]+tri[i-1][j]; }
    });
    double t3_vedic = benchmark([]() { PingalaChandaSutras::generateMeruPrastara(20); });

    // Batch 4: Hash
    double t4_std = benchmark([]() { std::hash<std::string>{}("VedicCompute"); });
    double t4_vedic = benchmark([]() { PaniniAshtadhyayi::applySutra("VedicCompute"); });

    // Batch 5: Trig
    double t5_std = benchmark([]() { std::sin(0.785); });
    double t5_vedic = benchmark([]() { SuryaSiddhanta::calculateJya(0.785); });

    std::cout << "\n| Batch | Category | Standard (ms) | Vedic (ms) | Speedup |\n";
    std::cout << "|-------|----------|---------------|------------|---------|\n";
    std::cout << "| B1/2  | MatMul   | " << t1_std << " | " << t1_vedic << " | " << t1_std/t1_vedic << "x |\n";
    std::cout << "| B3    | Pascal   | " << t3_std << " | " << t3_vedic << " | " << t3_std/t3_vedic << "x |\n";
    std::cout << "| B4    | Hash     | " << t4_std << " | " << t4_vedic << " | " << t4_std/t4_vedic << "x |\n";
    std::cout << "| B5    | Trig Jya | " << t5_std << " | " << t5_vedic << " | " << t5_std/t5_vedic << "x |\n";

    return 0;
}
