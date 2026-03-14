#include "PanchaKoshaKernel.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace DivineEarthlyKernels {
namespace Security {

    bool PanchaKoshaKernel::performSecurityCheck(KoshaType kosha, const std::string& attempted_action, const std::string& agent_id) {
        std::cout << "[PanchaKosha] Checking '" << attempted_action << "' by agent '" << agent_id << "' at Kosha layer: ";
        switch (kosha) {
            case ANNAMAYA: std::cout << "ANNAMAYA (Hardware/User-land)."; break;
            case PRANAMAYA: std::cout << "PRANAMAYA (I/O Layer)."; break;
            case MANOMAYA: std::cout << "MANOMAYA (Sandbox)."; break;
            case VIJNANAMAYA: std::cout << "VIJNANAMAYA (Kernel)."; break;
            case ANANDAMAYA: std::cout << "ANANDAMAYA (Root Singularity)."; break;
        }

        // Simulate security logic for each layer
        if (kosha == ANNAMAYA && attempted_action == "physical_tamper") { 
            std::cout << " -> ALERT: Physical tampering detected! Access DENIED.\n"; return false; 
        }
        if (kosha == PRANAMAYA && attempted_action == "unauthorized_network_access") { 
            std::cout << " -> ALERT: Unauthorized network access attempt! Access DENIED.\n"; return false; 
        }
        if (kosha == MANOMAYA && attempted_action == "sandbox_escape") { 
            std::cout << " -> ALERT: Sandbox escape attempt! Access DENIED.\n"; return false; 
        }
        if (kosha == VIJNANAMAYA && attempted_action == "kernel_privilege_escalation") { 
            std::cout << " -> ALERT: Kernel privilege escalation attempt! Access DENIED.\n"; return false; 
        }
        if (kosha == ANANDAMAYA && attempted_action == "modify_root_singularity") { 
            std::cout << " -> CRITICAL ALERT: Attempt to modify Root Singularity! Access DENIED.\n"; return false; 
        }

        std::cout << " -> Access GRANTED (Action allowed or benign).\n";
        return true;
    }

    void PanchaKoshaKernel::configureKoshaPolicy(KoshaType kosha, const std::vector<std::string>& allowed_actions) {
        std::cout << "[PanchaKosha] Configuring policy for Kosha layer: ";
        switch (kosha) {
            case ANNAMAYA: std::cout << "ANNAMAYA."; break;
            case PRANAMAYA: std::cout << "PRANAMAYA."; break;
            case MANOMAYA: std::cout << "MANOMAYA."; break;
            case VIJNANAMAYA: std::cout << "VIJNANAMAYA."; break;
            case ANANDAMAYA: std::cout << "ANANDAMAYA."; break;
        }
        std::cout << ". Allowed actions: ";
        for (const auto& action : allowed_actions) {
            std::cout << action << " ";
        }
        std::cout << ".\n";
    }

    void PanchaKoshaKernel::demonstrate() {
        std::cout << "\n--- Demonstrating Level 55: Pancha Kosha (Layered Security & Kernel Architecture) ---\n";

        configureKoshaPolicy(ANNAMAYA, {"read_sensors", "activate_haptics"});
        configureKoshaPolicy(MANOMAYA, {"execute_ai_inference", "access_local_db"});

        performSecurityCheck(ANNAMAYA, "read_sensors", "UserApp_1");
        performSecurityCheck(ANNAMAYA, "physical_tamper", "MaliciousActor_A");

        performSecurityCheck(MANOMAYA, "execute_ai_inference", "LLM_Sandbox_1");
        performSecurityCheck(MANOMAYA, "sandbox_escape", "UntrustedCode_X");

        performSecurityCheck(VIJNANAMAYA, "read_system_status", "AdminAgent");
        performSecurityCheck(ANANDAMAYA, "modify_root_singularity", "SuperUser_Attempt");
    }
} // namespace Security
} // namespace DivineEarthlyKernels
