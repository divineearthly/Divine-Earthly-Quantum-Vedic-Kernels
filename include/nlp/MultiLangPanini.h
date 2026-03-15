#ifndef MULTI_LANG_PANINI_H
#define MULTI_LANG_PANINI_H

#include <string>
#include <vector>
#include <map>
#include "PaniniAshtadhyayi.h"

namespace DivineEarthlyKernels::NLP {

enum class VachType { SANSKRIT, ENGLISH, HINDI, LATIN };

class MultiLangPanini : public PaniniAshtadhyayi {
public:
    // Map tokens to roots based on specific language phonetic sutras
    static void processMultilingual(const std::vector<std::string>& tokens, 
                                    std::vector<uint32_t>& roots, 
                                    VachType lang) {
        for (const auto& token : tokens) {
            // Apply a language-specific salt or transformation before hashing
            uint32_t baseRoot = applySutra(token);
            uint32_t langRoot = baseRoot ^ static_cast<uint32_t>(lang);
            roots.push_back(langRoot);
        }
    }
};

}
#endif
