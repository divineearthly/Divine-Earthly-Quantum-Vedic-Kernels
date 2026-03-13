#ifndef RASA_THEORY_H
#define RASA_THEORY_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> // For std::transform

namespace DivineEarthlyKernels {
namespace Core {

// Level 58: Rasa Theory (The Affective Computing & UX Framework)
// Structure: The science of aesthetic "flavors" (Rasas) like Love, Heroism, Wonder, and Peace that evoke specific emotional responses in the observer.
// Application: Affective Computing and Human-AI Interaction. The AI analyzes the user's input to detect the emotional "flavor" and adjusts its response tone, UI color schemes, and processing speed to match the user's psychological state.
class RasaTheory {
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
            case SHRINGARA: return "SHRINGARA (Love/Beauty)";
            case HASYA: return "HASYA (Mirth/Humor)";
            case KARUNA: return "KARUNA (Compassion/Sorrow)";
            case RAUDRA: return "RAUDRA (Anger/Fury)";
            case VEERA: return "VEERA (Heroism/Courage)";
            case BHAYANAKA: return "BHAYANAKA (Fear/Terror)";
            case BIBHATSA: return "BIBHATSA (Disgust/Aversion)";
            case ADBUTA: return "ADBUTA (Wonder/Amazement)";
            case SHANTA: return "SHANTA (Peace/Tranquility)";
            default: return "UNKNOWN";
        }
    }

    // A simplified sentiment analysis function based on keywords to detect Rasa.
    static Rasa detectRasa(const std::string& text) {
        std::string lower_text = text;
        std::transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);

        if (lower_text.find("love") != std::string::npos || lower_text.find("beautiful") != std::string::npos || lower_text.find("joy") != std::string::npos) {
            return SHRINGARA;
        } else if (lower_text.find("funny") != std::string::npos || lower_text.find("laughter") != std::string::npos || lower_text.find("happy") != std::string::npos) {
            return HASYA;
        } else if (lower_text.find("sad") != std::string::npos || lower_text.find("sorry") != std::string::npos || lower_text.find("grief") != std::string::npos) {
            return KARUNA;
        } else if (lower_text.find("angry") != std::string::npos || lower_text.find("furious") != std::string::npos || lower_text.find("rage") != std::string::npos) {
            return RAUDRA;
        } else if (lower_text.find("brave") != std::string::npos || lower_text.find("courage") != std::string::npos || lower_text.find("hero") != std::string::npos) {
            return VEERA;
        } else if (lower_text.find("fear") != std::string::npos || lower_text.find("scared") != std::string::npos || lower_text.find("terror") != std::string::npos) {
            return BHAYANAKA;
        } else if (lower_text.find("disgust") != std::string::npos || lower_text.find("gross") != std::string::npos || lower_text.find("revolt") != std::string::npos) {
            return BIBHATSA;
        } else if (lower_text.find("wonder") != std::string::npos || lower_text.find("amazing") != std::string::npos || lower_text.find("awe") != std::string::npos) {
            return ADBUTA;
        }
        return SHANTA; // Default or neutral, aiming for peace
    }

    // Adjusts AI's response tone, UI, or processing based on detected Rasa.
    static void adjustAIResponse(Rasa detected_rasa, const std::string& user_id) {
        std::cout << "[RasaTheory] Adjusting AI response for user '" << user_id << "' based on detected Rasa: " << getRasaName(detected_rasa) << ".\n";
        switch (detected_rasa) {
            case SHRINGARA: std::cout << 
