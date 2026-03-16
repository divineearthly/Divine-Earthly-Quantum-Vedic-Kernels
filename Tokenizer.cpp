#include "Tokenizer.h"
#include <sstream>

Tokenizer::Tokenizer() {}

std::vector<std::string> Tokenizer::tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::stringstream ss(text);
    std::string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}
