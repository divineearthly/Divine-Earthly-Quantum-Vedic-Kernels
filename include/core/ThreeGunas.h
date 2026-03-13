#ifndef THREE_GUNAS_H
#define THREE_GUNAS_H

#include <iostream>
#include <string>

enum class SystemGuna { SATTVA, RAJAS, TAMAS };

/**
 * @brief Level 51 - The Three Gunas: Dynamic State Manager
 * Sattva: Optimal Compute | Rajas: Active I/O | Tamas: Low Power/Idle
 */
class ThreeGunas {
private:
    SystemGuna currentState;
public:
    ThreeGunas() : currentState(SystemGuna::TAMAS) {}

    void transitionTo(SystemGuna newState) {
        currentState = newState;
        std::cout << "[ThreeGunas] Transitioned to " << getGunaName() << " state.\n";
    }

    std::string getGunaName() {
        switch(currentState) {
            case SystemGuna::SATTVA: return "SATTVA (HPC Mode)";
            case SystemGuna::RAJAS:  return "RAJAS (I/O Mode)";
            case SystemGuna::TAMAS:  return "TAMAS (Idle Mode)";
            default: return "Unknown";
        }
    }
};
#endif
