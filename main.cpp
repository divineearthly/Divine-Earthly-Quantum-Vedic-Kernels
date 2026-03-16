#include <iostream>
#include "AIAgent.h"

int main() {
    AIAgent agent;
    std::string input;
    std::cout << "Enter text: ";
    std::getline(std::cin, input);
    std::string response = agent.process(input);
    std::cout << "Response: " << response << std::endl;
    return 0;
}
