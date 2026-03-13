#ifndef BINDU_COMPUTE_ENGINE_H
#define BINDU_COMPUTE_ENGINE_H

#include <string>
#include "SutraRegistry.h"

class BinduComputeEngine {
public:
    void execute(const std::string& sutraId) {
        auto kernel = SutraRegistry::getSutra(sutraId);
        if (kernel) {
            std::cout << "[BinduComputeEngine] Routing to: " << sutraId << std::endl;
            kernel();
        } else {
            std::cerr << "[Error] Sutra ID " << sutraId << " not found!" << std::endl;
        }
    }
};
#endif