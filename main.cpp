
#include "AIAgent.h"

int main() {
    // Initialize the AI Agent
    AIAgent agent;

    // Process a user prompt
    std::string prompt = "This is a test prompt for the AI agent.";
    std::cout << "Processing prompt: \"" << prompt << "\"" << std::endl;
    agent.processPrompt(prompt);

    return 0;
}
