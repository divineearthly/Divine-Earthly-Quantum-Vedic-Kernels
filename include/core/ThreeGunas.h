#ifndef THREE_GUNAS_H
#define THREE_GUNAS_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace DivineEarthlyKernels {
namespace Core {

// Forward declaration for our compute kernel interface
class IVedicKernel {
public:
    virtual ~IVedicKernel() = default;
    virtual const char* getName() const = 0;
    virtual void initialize() = 0;
    virtual void execute() = 0;
    virtual void shutdown() = 0;
};

// The states of the system, aligned with the Three Gunas
enum class SystemGuna { 
    SATTVA, // Balance: Idle, low-power, ready state
    RAJAS,  // Action: Active, high-performance, computational state
    TAMAS   // Inertia: Shutdown, sleep, or error-handling state
};

// Level 28: The Three Gunas - Central State & Power Management
class ThreeGunas {
private:
    SystemGuna currentState;
    std::vector<std::shared_ptr<IVedicKernel>> managedKernels;

public:
    ThreeGunas() : currentState(SystemGuna::TAMAS) {
        std::cout << "[ThreeGunas] System initialized in TAMAS (Shutdown) state.\n";
    }

    void registerKernel(std::shared_ptr<IVedicKernel> kernel) {
        managedKernels.push_back(kernel);
        std::cout << "[ThreeGunas] Registered kernel: " << kernel->getName() << ".\n";
    }

    void transitionTo(SystemGuna newState) {
        if (newState == currentState) return;

        std::cout << "[ThreeGunas] Transitioning from " << getGunaName(currentState) 
                  << " to " << getGunaName(newState) << "...\n";
        currentState = newState;

        switch (currentState) {
            case SystemGuna::SATTVA: // Transition to Idle/Ready
                for (auto& kernel : managedKernels) {
                    kernel->initialize();
                }
                break;
            case SystemGuna::RAJAS:  // Transition to Active/Compute
                for (auto& kernel : managedKernels) {
                    kernel->execute();
                }
                break;
            case SystemGuna::TAMAS:  // Transition to Shutdown/Sleep
                for (auto& kernel : managedKernels) {
                    kernel->shutdown();
                }
                break;
        }
    }

    static std::string getGunaName(SystemGuna guna) {
        switch(guna) {
            case SystemGuna::SATTVA: return "SATTVA (Balanced/Idle)";
            case SystemGuna::RAJAS:  return "RAJAS (Active/Compute)";
            case SystemGuna::TAMAS:  return "TAMAS (Inertia/Shutdown)";
            default: return "Unknown";
        }
    }
};

} // namespace Core
} // namespace DivineEarthlyKernels

#endif // THREE_GUNAS_H
