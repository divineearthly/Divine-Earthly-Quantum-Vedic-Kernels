#ifndef VEDIC_KERNELS_H
#define VEDIC_KERNELS_H

#include "../core/ThreeGunas.h"
#include <iostream>

// Mock implementation of the Urdhva Tiryagbhyam multiplication kernel
class UrdhvaTiryagbhyamKernel : public DivineEarthlyKernels::Core::IVedicKernel {
public:
    const char* getName() const override { return "UrdhvaTiryagbhyam (Multiplication)"; }
    void initialize() override { std::cout << "  [Urdhva] Kernel initialized and ready (Sattva).\n"; }
    void execute() override { std::cout << "  [Urdhva] Kernel now performing high-speed multiplication (Rajas).\n"; }
    void shutdown() override { std::cout << "  [Urdhva] Kernel shutting down (Tamas).\n"; }
};

// Mock implementation of the Nikhilam subtraction kernel
class NikhilamKernel : public DivineEarthlyKernels::Core::IVedicKernel {
public:
    const char* getName() const override { return "Nikhilam (Subtraction)"; }
    void initialize() override { std::cout << "  [Nikhilam] Kernel initialized and ready (Sattva).\n"; }
    void execute() override { std::cout << "  [Nikhilam] Kernel now performing high-speed subtraction (Rajas).\n"; }
    void shutdown() override { std::cout << "  [Nikhilam] Kernel shutting down (Tamas).\n"; }
};

#endif // VEDIC_KERNELS_H
