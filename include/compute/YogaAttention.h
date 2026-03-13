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
        size_t size) // size of the token stream / weights
    {
        if (tokenStream.empty() || attentionWeights == nullptr || resultMatrix == nullptr || size == 0) {
            std::cerr << "[YogaAttention] Error: Invalid input parameters.\n";
            return;
        }

        std::cout << "[YogaAttention] Initiating Dharana (Attention Mechanism) for " << size << " tokens.\n";

        // The tokenStream.data() provides a raw pointer to the underlying array.
        // We use it directly as a raw C++ matrix (vector) for the VedicALU.
        VedicALU::vectorizedNikhilam(tokenStream.data(), attentionWeights, resultMatrix, size);

        std::cout << "[YogaAttention] Attention weights applied. Output ready for further processing.\n";
    }
};

#endif
