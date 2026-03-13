#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "compute/VedicALU.h"
#include "compute/PingalaChandaSutras.h"
#include "nlp/PaniniAshtadhyayi.h"

using namespace DivineEarthlyKernels::Compute;
using namespace DivineEarthlyKernels::NLP;

void test_vedic_alu() {
    std::cout << "[Test] Running VedicALU Matrix Identity Test... ";
    const size_t N = 2;
    float A[4] = {1, 0, 0, 1};
    float B[4] = {5, 6, 7, 8};
    float C[4] = {0, 0, 0, 0};
    VedicALU::matrixMultiplyVedic(A, B, C, N);
    assert(std::abs(C[0] - 5.0f) < 1e-5);
    assert(std::abs(C[1] - 6.0f) < 1e-5);
    assert(std::abs(C[2] - 7.0f) < 1e-5);
    assert(std::abs(C[3] - 8.0f) < 1e-5);
    std::cout << "PASSED" << std::endl;
}

void test_pingala_sutras() {
    std::cout << "[Test] Running Pingala Combinatorics Test... ";
    assert(PingalaChandaSutras::getBinaryCombinatorics(5, 2) == 10);
    assert(PingalaChandaSutras::getBinaryCombinatorics(10, 0) == 1);
    assert(PingalaChandaSutras::getBinaryCombinatorics(10, 10) == 1);
    std::cout << "PASSED" << std::endl;
}

void test_panini_nlp() {
    std::cout << "[Test] Running Panini Hashing Test... ";
    std::string input = "Veda";
    uint32_t hash1 = PaniniAshtadhyayi::applySutra(input);
    uint32_t hash2 = PaniniAshtadhyayi::applySutra(input);
    assert(hash1 == hash2);
    std::cout << "PASSED" << std::endl;
}

int main() {
    std::cout << "--- VEDIC KERNEL UNIT TEST SUITE ---\n" << std::endl;
    test_vedic_alu();
    test_pingala_sutras();
    test_panini_nlp();
    std::cout << "\n[Final Result] All tests passed successfully!" << std::endl;
    return 0;
}