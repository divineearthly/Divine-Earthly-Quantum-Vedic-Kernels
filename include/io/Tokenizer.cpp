
#include "Tokenizer.h"
#include <sstream>

void Tokenizer::tokenizeSentence(const std::string& sentence, std::vector<uint32_t>& tokens) {
    tokens.clear();
    std::stringstream ss(sentence);
    std::string word;
    while (ss >> word) {
        // In a real scenario, you would have a vocabulary and map words to IDs.
        // Here, we'll just use a simple hash as a stand-in.
        tokens.push_back(static_cast<uint32_t>(std::hash<std::string>{}(word)));
    }
}
