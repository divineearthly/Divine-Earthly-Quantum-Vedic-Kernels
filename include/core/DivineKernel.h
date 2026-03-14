#ifndef DIVINEKERNEL_H
#define DIVINEKERNEL_H

#include <memory>
#include "ThreeGunas.h"
#include "SriYantraArchitecture.h"

class DivineKernel {
public:
    DivineKernel() : 
        gunaController(std::make_unique<GunaEngine>()),
        sriYantra(std::make_unique<SriYantra>()) {}

    void initialize() {
        if(gunaController) gunaController->reportState();
        if(sriYantra) sriYantra->projectHolographic();
    }

private:
    std::unique_ptr<GunaEngine> gunaController;
    std::unique_ptr<SriYantra> sriYantra;
};

#endif