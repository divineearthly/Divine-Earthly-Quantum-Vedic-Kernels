#include <iostream>
#include <vector>
#include <chrono>
#include "io/PaniniNLP.h"
#include "memory/GarudaShredder.h"
#include "memory/AkashicRecords.h" // Include AkashicRecords.h

int main() {
    std::cout << "=== DIVINE EARTHLY: NLP TOKENIZATION TEST WITH AKASHIC RECORDS ===\n\n";

    // 1. The Human Input
    std::string prompt = "Execute the Maha Vakyas integration for universal consciousness.";
    std::cout << "[Human] Prompt: \"" << prompt << "\"\n\n";

    // 2. The Panini Tokenizer Buffer
    std::vector<uint32_t> secureTokenBuffer;

    // 3. Benchmark the Tokenization
    auto startNLP = std::chrono::high_resolution_clock::now();

    PaniniTokenizer::processSentence(prompt, secureTokenBuffer);

    auto endNLP = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> timeNLP = endNLP - startNLP;

    // 4. Display the resulting Mathematical Tokens
    std::cout << "\n[Sattva] Token Stream Output (Ready for Vector ALU):\n[ ";
    for(uint32_t token : secureTokenBuffer) {
        std::cout << token << " ";
    }
    std::cout << "]\n";

    std::cout << "\n[Result] Sentence tokenized in: " << timeNLP.count() << " ms\n\n";

    // 5. Record to Akashic Records before shredding
    std::cout << "[AkashicRecords] Recording token stream to persistent memory...\n";
    AkashicRecords::recordState(secureTokenBuffer.data(), secureTokenBuffer.size());

    // 6. Secure Hardware Wipe (Moksha)
    std::cout << "[Moksha] Prompt ingested. Shredding token buffer to prevent memory leaks...\n";
    GarudaShredder::dissolve(secureTokenBuffer.data(), secureTokenBuffer.size() * sizeof(uint32_t));
    secureTokenBuffer.clear();

    std::cout << "[Success] NLP pipeline clear. Awaiting next command.\n";

    return 0;
}
