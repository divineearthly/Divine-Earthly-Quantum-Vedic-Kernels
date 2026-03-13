#include "../include/compute/YogaAttention.h"
#include "../include/compute/VedicALU.h" // Necessary for VedicALU::vectorizedNikhilam
#include <iostream>
#include <vector>

void YogaAttention::applyAttention(
    const std::vector<uint32_t>& tokenStream,
    const uint32_t* __restrict__ attentionWeights,
    uint32_t* __restrict__ resultMatrix,
    size_t size)
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
