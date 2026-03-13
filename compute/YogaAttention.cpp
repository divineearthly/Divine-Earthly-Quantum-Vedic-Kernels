#include "compute/YogaAttention.h"
#include "compute/VedicALU.h"
#include <vector>

void YogaAttention::applyAttention(const std::vector<uint32_t>& tokenStream, const uint32_t* attentionWeights, uint32_t* resultMatrix, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            resultMatrix[i * size + j] = tokenStream[i] * attentionWeights[j];
        }
    }
}