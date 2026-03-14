#include "Astras.h"

namespace DivineEarthlyKernels {
namespace Security {

    void Astras::armPayload(Payload& p) {
        p.is_active = true;
        std::cout << "[Astras] Payload '" << p.name << "' targeting '" << p.target << "' has been ARMED.\n";
    }

    void Astras::disarmPayload(Payload& p) {
        p.is_active = false;
        std::cout << "[Astras] Payload '" << p.name << "' has been DISARMED.\n";
    }

    bool Astras::tryTriggerPayload(Payload& p, const std::string& current_condition) {
        if (p.is_active) {
            std::cout << "[Astras] Checking trigger conditions for payload '" << p.name << "'. Current condition: '" << current_condition << "'.\n";
            // Conceptual trigger condition matching target string
            if (current_condition.find(p.target) != std::string::npos) {
                std::cout << "[Astras] Payload '" << p.name << "' TRIGGERED! Executing action...\n";
                p.execute_action();
                // Often payloads are one-shot, so disarm after execution.
                disarmPayload(p);
                return true;
            } else {
                std::cout << "[Astras] Trigger condition not met for payload '" << p.name << "'.\n";
            }
        } else {
            std::cout << "[Astras] Payload '" << p.name << "' is INACTIVE. Cannot be triggered.\n";
        }
        return false;
    }

    void Astras::runPenTest(const std::string& system_to_test) {
        std::cout << "[Astras] Running automated penetration test on '" << system_to_test << "'.\n";
        // Simulate various attack vectors
        if (rand() % 3 == 0) {
            std::cout << "  - Detected minor vulnerability (SQL Injection potential).\n";
        } else if (rand() % 5 == 0) {
            std::cout << "  - Detected critical exploit (Buffer Overflow in Auth module)!\n";
        } else {
            std::cout << "  - No major vulnerabilities found in current scan.\n";
        }
    }

    void Astras::demonstrate() {
        std::cout << "\n--- Demonstrating Level 48: Astras (Targeted Payload & Execution Framework) ---\n";

        Payload system_shutdown("Emergency_Shutdown", "critical_failure", []() { 
            std::cout << "    (Action) Initiating emergency system shutdown sequence!\n"; 
        });

        Payload data_exfil("Data_Exfiltration", "unauthorized_access", []() { 
            std::cout << "    (Action) Attempting to exfiltrate sensitive data!\n"; 
        });

        armPayload(system_shutdown);
        armPayload(data_exfil);

        tryTriggerPayload(system_shutdown, "network_glitch");
        tryTriggerPayload(data_exfil, "user_logged_in");
        tryTriggerPayload(system_shutdown, "system_critical_failure_detected");

        runPenTest("Main_AI_Kernel_API");
    }

} // namespace Security
} // namespace DivineEarthlyKernels