#include "include/nlp/PaniniAshtadhyayi.h"

namespace DivineEarthlyKernels::NLP {

uint32_t PaniniAshtadhyayi::applySutra(const std::string& input) {
    uint32_t hash = 0x811c9dc5;
    for (char c : input) {
        hash ^= static_cast<uint32_t>(c);
        hash *= 0x01000193;
    }
    return hash;
}

void PaniniAshtadhyayi::processSequence(const std::vector<std::string>& tokens, std::vector<uint32_t>& roots) {
    roots.reserve(tokens.size());
    for (const auto& token : tokens) {
        roots.push_back(applySutra(token));
    }
}

}