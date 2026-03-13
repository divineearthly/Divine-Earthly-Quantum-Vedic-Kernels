#ifndef PANINI_ASHTADHYAYI_H
#define PANINI_ASHTADHYAYI_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream> // For stringstream
#include <map>     // For grammar rules

namespace DivineEarthlyKernels {
namespace NLP {

// Level 6: Panini’s Ashtadhyayi (The NLP & Generative AI Framework)
// Structure: 3,959 sutras defining the ultimate generative grammar of Sanskrit.
// Application: The absolute foundation of formal language theory. Essential for Natural Language Processing (NLP),
// tokenization logic, and optimizing how an LLM parses human prompts.
class PaniniAshtadhyayi {
public:
    // Tokenization: Breaks down a sentence into fundamental linguistic units (tokens).
    // This simulates the initial parsing step, identifying individual words or 'morphemes'.
    static std::vector<std::string> tokenize(const std::string& text) {
        std::vector<std::string> tokens;
        std::stringstream ss(text);
        std::string token;
        while (ss >> token) {
            // Simple tokenization: remove punctuation for cleaner tokens
            std::string cleaned_token;
            for (char c : token) {
                if (std::isalnum(static_cast<unsigned char>(c))) {
                    cleaned_token += c;
                }
            }
            if (!cleaned_token.empty()) {
                tokens.push_back(cleaned_token);
            }
        }
        std::cout << "[Panini] Tokenized input: '" << text << "' into " << tokens.size() << " tokens.\n";
        return tokens;
    }

    // Apply a simple grammatical rule (conceptual).
    // This method demonstrates how a 'sutra' can transform or validate a sequence of tokens.
    // For instance, a rule for verb conjugation or noun declension.
    // In a real system, this would be far more complex, involving parse trees and deep linguistic analysis.
    static std::string applyGrammarRule(const std::vector<std::string>& tokens, const std::string& rule_name) {
        std::string result = "";
        if (tokens.empty()) return "";

        if (rule_name == "subject-verb_agreement") {
            if (tokens.size() >= 2) {
                // Conceptual rule: If first token is 'I' and second is 'am', it's valid.
                // If first token is 'He'/'She'/'It' and second is 'is', it's valid.
                if ((tokens[0] == "I" && tokens[1] == "am") ||
                    ((tokens[0] == "He" || tokens[0] == "She" || tokens[0] == "It") && tokens[1] == "is")) {
                    result = "[Panini] Grammar rule '" + rule_name + "' applied: Valid subject-verb agreement.";
                } else {
                    result = "[Panini] Grammar rule '" + rule_name + "' applied: Potential subject-verb disagreement.";
                }
            } else {
                result = "[Panini] Grammar rule '" + rule_name + "' applied: Insufficient tokens for rule.";
            }
        } else {
            result = "[Panini] Unknown grammar rule '" + rule_name + "'. Tokens: ";
            for (const auto& t : tokens) result += t + " ";
        }
        std::cout << result << "\n";
        return result;
    }

    // A simplified example of combining tokens based on a rule (e.g., compounding).
    static std::string combineTokens(const std::vector<std::string>& tokens, const std::string& conjunction = "") {
        std::string combined_text = "";
        for (size_t i = 0; i < tokens.size(); ++i) {
            combined_text += tokens[i];
            if (i < tokens.size() - 1 && !conjunction.empty()) {
                combined_text += conjunction;
            } else if (i < tokens.size() - 1) {
                combined_text += " ";
            }
        }
        std::cout << "[Panini] Combined tokens with '" << conjunction << "': " << combined_text << "\n";
        return combined_text;
    }
};

} // namespace NLP
} // namespace DivineEarthlyKernels

#endif // PANINI_ASHTADHYAYI_H
