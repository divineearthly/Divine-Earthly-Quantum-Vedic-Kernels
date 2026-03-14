#ifndef THE_YUGAS_H
#define THE_YUGAS_H

#include "ThreeGunas.h"
#include <iostream>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::seconds

namespace DivineEarthlyKernels {
namespace Core {

// Level 27: The Yugas (Cyclical Time & System Scheduler)
// Structure: A scheduler that governs the operational tempo of the system.
// Application: It dictates the transitions of the ThreeGunas state manager based on workload, system needs, or a simple heartbeat, creating a rhythmic operational cycle.
class TheYugas {
private:
    ThreeGunas& gunaManager; // A reference to the state manager it controls
    bool isRunning = false;

public:
    // TheYugas needs a reference to the ThreeGunas manager to control it.
    TheYugas(ThreeGunas& manager) : gunaManager(manager) {
        std::cout << "[Yugas] System Scheduler initialized. Linked to ThreeGunas state manager.\n";
    }

    // Starts the main scheduler loop.
    void startScheduler() {
        isRunning = true;
        std::cout << "[Yugas] Scheduler starting the grand cycle...\n";
        schedulerLoop();
    }

    // Stops the scheduler.
    void stopScheduler() {
        isRunning = false;
        std::cout << "[Yugas] Scheduler stopping the grand cycle.\n";
    }

private:
    // The core loop that simulates the cyclical nature of the Yugas.
    void schedulerLoop() {
        int cycleCount = 0;
        while (isRunning && cycleCount < 2) { // Run for 2 full cycles for demonstration
            std::cout << "\n--- Cycle " << cycleCount + 1 << " ---\n";

            // 1. Awaken to SATTVA (Balanced/Idle)
            gunaManager.transitionTo(SystemGuna::SATTVA);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            // 2. Perform work in RAJAS (Active/Compute)
            gunaManager.transitionTo(SystemGuna::RAJAS);
            std::this_thread::sleep_for(std::chrono::seconds(2));

            // 3. Return to SATTVA (Balanced/Idle)
            gunaManager.transitionTo(SystemGuna::SATTVA);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            // 4. Rest in TAMAS (Inertia/Shutdown)
            gunaManager.transitionTo(SystemGuna::TAMAS);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            cycleCount++;
        }
        stopScheduler();
    }
};

} // namespace Core
} // namespace DivineEarthlyKernels

#endif // THE_YUGAS_H
