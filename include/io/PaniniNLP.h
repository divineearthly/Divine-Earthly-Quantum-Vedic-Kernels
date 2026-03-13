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
        // Acts as our "Sutra" to convert syllables/words directly into numerical tokens.
            static constexpr uint32_t hashWord(const char* str, uint32_t h = 2166136261) {
                    return !*str ? h : hashWord(str + 1, (h ^ *str) * 16777619);
                        }

                            // Helper wrapper for std::string
                                static uint32_t tokenizeWord(const std::string& word) {
                                        return hashWord(word.c_str());
                                            }

                                                // Process a full sentence into a Vector of SIMD-ready integers
                                                    static void processSentence(const std::string& input, std::vector<uint32_t>& tokenStream) {
                                                            std::istringstream stream(input);
                                                                    std::string word;
                                                                            
                                                                                    std::cout << "[Panini] Parsing syntax and generating numerical roots...\n";
                                                                                            
                                                                                                    while (stream >> word) {
                                                                                                                uint32_t token = tokenizeWord(word);
                                                                                                                            tokenStream.push_back(token);
                                                                                                                                    }
                                                                                                                                        }
                                                                                                                                        };

                                                                                                                                        #endif
                                                                                                                                        
