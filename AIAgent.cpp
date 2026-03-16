#include "AIAgent.h"
#include <iostream>

AIAgent::AIAgent() {}

std::string AIAgent::process(const std::string& input) {
    std::vector<std::string> tokens = tokenizer.tokenize(input);
    std::string response = "Received tokens: ";
    for (const auto& token : tokens) {
        response += token + " ";
    }
    return response;
}
