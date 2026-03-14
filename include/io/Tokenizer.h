
#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include <cstdint>

class Tokenizer {
public:
    void tokenizeSentence(const std::string& sentence, std::vector<uint32_t>& tokens);
};

#endif
