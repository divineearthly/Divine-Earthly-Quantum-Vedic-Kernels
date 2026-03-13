#ifndef NATYA_SHASTRA_H
#define NATYA_SHASTRA_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm> // For std::transform

namespace DivineEarthlyKernels {
namespace NLP {

// Level 13: Natya Shastra / Rasa Sutras (The Sentiment Analysis Framework)
// Author: Bharata Muni
// Structure: Codifies human emotions (Rasas) and their corresponding triggers/responses into a deterministic, algorithmic matrix.
// Application: Building advanced sentiment analysis engines for LLMs, designing empathetic human-computer interaction (HCI),
// and interpreting complex emotional nuances in user prompts.
class NatyaShastra {
public:
    // Represents the nine primary Rasas (sentiments/emotions)
    enum Rasa {
        SHRINGARA, // Love, Beauty
        HASYA,     // Mirth, Humor
        KARUNA,    // Compassion, Sorrow
        RAUDRA,    // Anger, Fury
        VEERA,     // Heroism, Courage
        BHAYANAKA, // Fear, Terror
        BIBHATSA,  // Disgust, Aversion
        ADBUTA,    // Wonder, Amazement
        SHANTA     // Peace, Tranquility
    };

    // Helper to get string name of a Rasa
    static std::string getRasaName(Rasa rasa) {
        switch (rasa) {
            case SHRINGARA: return "SHRINGARA (Love)";
            case HASYA: return "HASYA (Humor)";
            case KARUNA: return "KARUNA (Sorrow)";
            case RAUDRA: return "RAUDRA (Anger)";
            case VEERA: return "VEERA (Heroism)";
            case BHAYANAKA: return "BHAYANAKA (Fear)";
            case BIBHATSA: return "BIBHATSA (Disgust)";
            case ADBUTA: return "ADBUTA (Wonder)";
            case SHANTA: return "SHANTA (Peace)";
            default: return "UNKNOWN";
        }
    }

    // A simplified sentiment analysis function based on keywords.
    // In a real LLM, this would involve complex vector embeddings and neural networks.
    static Rasa analyzeSentiment(const std::string& text) {
        std::string lower_text = text;
        std::transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);

        if (lower_text.find("love") != std::string::npos || lower_text.find("beautiful") != std::string::npos) {
            return SHRINGARA;
        } else if (lower_text.find("happy") != std::string::npos || lower_text.find("funny") != std::string::npos) {
            return HASYA;
        } else if (lower_text.find("sad") != std::string::npos || lower_text.find("sorry") != std::string::npos) {
            return KARUNA;
        } else if (lower_text.find("angry") != std::string::npos || lower_text.find("frustrating") != std::string::npos) {
            return RAUDRA;
        } else if (lower_text.find("brave") != std::string::npos || lower_text.find("hero") != std::string::npos) {
            return VEERA;
        } else if (lower_text.find("fear") != std::string::npos || lower_text.find("scared") != std::string::npos) {
            return BHAYANAKA;
        } else if (lower_text.find("disgust") != std::string::npos || lower_text.find("gross") != std::string::npos) {
            return BIBHATSA;
        } else if (lower_text.find("amazing") != std::string::npos || lower_text.find("wonder") != std::string::npos) {
            return ADBUTA;
        } else if (lower_text.find("peace") != std::string::npos || lower_text.find("calm") != std::string::npos) {
            return SHANTA;
        }
        return SHANTA; // Default or neutral
    }

    // Adjusts AI's response tone based on detected Rasa.
    static void adjustResponseTone(Rasa detected_rasa, const std::string& prompt_id) {
        std::cout << "[Natya] Adjusting AI response tone for prompt '" << prompt_id << "' based on detected Rasa: " << getRasaName(detected_rasa) << ".\n";
        // In a real system, this would modify response generation parameters, UI elements, etc.
        if (detected_rasa == RAUDRA) {
            std::cout << "  --> Employing calming and reassuring language protocols.\n";
        } else if (detected_rasa == HASYA) {
            std::cout << "  --> Engaging with lighthearted and engaging tone.\n";
        } else if (detected_rasa == KARUNA) {
            std::cout << "  --> Responding with empathy and supportive guidance.\n";
        }
    }

    static void demonstrate() {
        std::cout << "\n--- Demonstrating Level 13: Natya Shastra / Rasa Sutras (Sentiment Analysis) ---\n";

        std::string user_prompt1 = "I love this new feature, it's amazing!";
        Rasa rasa1 = analyzeSentiment(user_prompt1);
        adjustResponseTone(rasa1, "Prompt_001");

        std::string user_prompt2 = "I am very angry with the system's performance.";
        Rasa rasa2 = analyzeSentiment(user_prompt2);
        adjustResponseTone(rasa2, "Prompt_002");

        std::string user_prompt3 = "Please provide a peaceful resolution to this issue.";
        Rasa rasa3 = analyzeSentiment(user_prompt3);
        adjustResponseTone(rasa3, "Prompt_003");
    }
};

} // namespace NLP
} // namespace DivineEarthlyKernels

#endif // NATYA_SHASTRA_H
