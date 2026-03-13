#ifndef PANINI_ASHTADHYAYI_H
#define PANINI_ASHTADHYAYI_H

#include <string>
#include <vector>
#include <cstdint>

namespace DivineEarthlyKernels::NLP {

class PaniniAshtadhyayi {
public:
    static uint32_t applySutra(const std::string& input);
    static void processSequence(const std::vector<std::string>& tokens, std::vector<uint32_t>& roots);
};

}
#endif