#ifndef SHIKSHA_H
#define SHIKSHA_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype> // For std::isspace

namespace DivineEarthlyKernels {
namespace NLP {

// Level 37: Shiksha (The Lexing & Tokenization Framework)
// Structure: The first Vedanga, focused strictly on phonetics, syllables, and the raw character stream of sounds before they become structured words.
// Application: The Lexical Analyzer (Lexer) in a compiler or NLP model. It governs the exact algorithms for converting raw input text/audio into the fundamental tokens that the deeper Paninian syntax engines will later process.
class Shiksha {
public:
    // Represents a conceptual token with its type and value.
    struct Token {
        enum Type {
            WORD, PUNCTUATION, NUMBER, WHITESPACE, UNKNOWN
        };

        Type type;
        std::string value;

        std::string getTypeString() const {
            switch (type) {
                case WORD: return "WORD";
                case PUNCTUATION: return "PUNCTUATION";
                case NUMBER: return "NUMBER";
                case WHITESPACE: return "WHITESPACE";
                default: return "UNKNOWN";
            }
        }
    };

    // Performs lexical analysis to break raw input into a stream of tokens.
    static std::vector<Token> lex(const std::string& raw_input) {
        std::vector<Token> tokens;
        std::string current_lexeme;
        Token::Type current_type = Token::UNKNOWN;

        std::cout << "[Shiksha] Performing lexical analysis on: '" << raw_input << "'\n";

        for (char c : raw_input) {
            Token::Type next_type;
            if (std::isspace(c)) {
                next_type = Token::WHITESPACE;
            } else if (std::isdigit(c)) {
                next_type = Token::NUMBER;
            } else if (std::isalpha(c)) {
                next_type = Token::WORD;
            } else if (std::ispunct(c)) {
                next_type = Token::PUNCTUATION;
            } else {
                next_type = Token::UNKNOWN;
            }

            if (next_type != current_type && !current_lexeme.empty()) {
                tokens.push_back({current_type, current_lexeme});
                current_lexeme = "";
            }
            current_lexeme += c;
            current_type = next_type;
        }

        if (!current_lexeme.empty()) {
            tokens.push_back({current_type, current_lexeme});
        }

        std::cout << "  - Generated " << tokens.size() << " tokens.\n";
        return tokens;
    }

    // Tokenizes a string by splitting on whitespace, similar to basic NLP tokenization.
    static std::vector<std::string> simpleTokenize(const std::string& text) {
        std::vector<std::string> result;
        std::string current_word;
        std::cout << "[Shiksha] Simple tokenizing: '" << text << "'\n";
        for (char c : text) {
            if (std::isspace(c)) {
                if (!current_word.empty()) {
                    result.push_back(current_word);
                    current_word = "";
                }
            } else {
                current_word += c;
            }
        }
        if (!current_word.empty()) {
            result.push_back(current_word);
        }
        std::cout << "  - Found " << result.size() << " words.\n";
        return result;
    }

    static void demonstrate() {
        std::cout << "\n--- Demonstrating Level 37: Shiksha (Lexing & Tokenization Framework) ---\n";

        std::string sentence1 = "Hello, world! This is AI-Kernel v1.0.";
        std::vector<Token> lexed_tokens = lex(sentence1);
        for (const auto& token : lexed_tokens) {
            std::cout << "  [Token] Type: " << token.getTypeString() << ", Value: '" << token.value << "'\n";
        }

        std::string sentence2 = "The quick brown fox jumps over the lazy dog.";
        std::vector<std::string> words = simpleTokenize(sentence2);
        std::cout << "  Words: ";
        for (const auto& word : words) {
            std::cout << "'" << word << "' ";
        }
        std::cout << "\n";
    }
};

} // namespace NLP
} // namespace DivineEarthlyKernels

#endif // SHIKSHA_H
