#ifndef YOGA_ATTENTION_H
#define YOGA_ATTENTION_H

#include <cstdint>
#include <cstddef>
#include <iostream>
#include <vector>
#include "VedicALU.h" // For VedicALU::vectorizedNikhilam

class YogaAttention {
public:
    // Simulates attention weight multiplication using VedicALU::vectorizedNikhilam
    // Input: token stream from PaniniNLP, attention weights (raw pointer for bare-metal focus)
    // Output: result matrix (raw pointer) after attention calculation
    static void applyAttention(
        const std::vector<uint32_t>& tokenStream,
        const uint32_t* __restrict__ attentionWeights,
        uint32_t* __restrict__ resultMatrix,
        size_t size); // size of the token stream / weights
};

#endif
