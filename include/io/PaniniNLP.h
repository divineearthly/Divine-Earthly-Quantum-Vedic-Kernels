#ifndef PANINI_NLP_H
#define PANINI_NLP_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdint>

class PaniniTokenizer {
public:
    // FNV-1a Hash Algorithm: Extremely fast, low-collision string hashing.
    static constexpr uint32_t hashWord(const char* str, uint32_t h = 2166136261) {
        return !*str ? h : hashWord(str + 1, (h ^ *str) * 16777619);
    }

    static uint32_t tokenizeWord(const std::string& word);
    static void processSentence(const std::string& input, std::vector<uint32_t>& tokenStream);
};

#endif
