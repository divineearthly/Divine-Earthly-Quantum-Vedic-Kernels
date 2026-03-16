#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

class Tokenizer {
public:
    Tokenizer();
    std::vector<std::string> tokenize(const std::string& text);
};

#endif // TOKENIZER_H
