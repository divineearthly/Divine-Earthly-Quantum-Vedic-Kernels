#include <iostream>
#include "core/SutraRegistry.h"
#include "nlp/PaniniAshtadhyayi.h"
#include "logic/NyayaSutras.h"

void registerBatch4() {
    SutraRegistry::registerSutra("panini_grammar", []() {
        std::cout << "[Kernel] Running Panini Ashtadhyayi (Linguistic Engine)...\n";
    });
    SutraRegistry::registerSutra("nyaya_inference", []() {
        std::cout << "[Kernel] Running Nyaya Sutras (Inference Engine)...\n";
    });
}