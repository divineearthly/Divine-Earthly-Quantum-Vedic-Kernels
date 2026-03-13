#include <iostream>
#include "security/PanchaKoshaKernel.h"

using namespace DivineEarthlyKernels::Security;

int main() {
    std::cout << "=== Testing Level 55: Pancha Kosha Security System ===\n";

    // 1. Configure Policies
    PanchaKoshaKernel::configureKoshaPolicy(PanchaKoshaKernel::ANNAMAYA, {"read_thermal", "vibrate"});
    PanchaKoshaKernel::configureKoshaPolicy(PanchaKoshaKernel::MANOMAYA, {"run_inference"});

    // 2. Test Hardware Layer (Annamaya)
    std::cout << "\n[Test 1] Valid Hardware Access:\n";
    PanchaKoshaKernel::performSecurityCheck(PanchaKoshaKernel::ANNAMAYA, "read_thermal", "Temp_Daemon");

    std::cout << "\n[Test 2] Malicious Hardware Tamper:\n";
    PanchaKoshaKernel::performSecurityCheck(PanchaKoshaKernel::ANNAMAYA, "physical_tamper", "Attacker_01");

    // 3. Test Sandbox Layer (Manomaya)
    std::cout << "\n[Test 3] Valid Sandbox Execution:\n";
    PanchaKoshaKernel::performSecurityCheck(PanchaKoshaKernel::MANOMAYA, "run_inference", "AI_Sandbox");

    std::cout << "\n[Test 4] Sandbox Escape Attempt:\n";
    PanchaKoshaKernel::performSecurityCheck(PanchaKoshaKernel::MANOMAYA, "sandbox_escape", "Untrusted_Process");

    // 4. Test Root Layer (Anandamaya)
    std::cout << "\n[Test 5] Unauthorized Root Modification:\n";
    PanchaKoshaKernel::performSecurityCheck(PanchaKoshaKernel::ANANDAMAYA, "modify_root_singularity", "User_App");

    return 0;
}
