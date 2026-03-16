#ifndef AI_AGENT_H
#define AI_AGENT_H

#include <string>
#include <vector>
#include "Tokenizer.h"

class AIAgent {
public:
    AIAgent();
    std::string process(const std::string& input);

private:
    Tokenizer tokenizer;
};

#endif // AI_AGENT_H
