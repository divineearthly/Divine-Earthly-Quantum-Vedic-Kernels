#include "DharmaIAM.h"
#include <iostream>

namespace DivineEarthlyKernels {
namespace Security {

DharmaIAM::DharmaIAM() {
    // Admin Role (Sattvic Guna - Harmony, Wisdom, Governance)
    // The admin's Dharma is to maintain system balance and has wide-ranging, but not absolute, power.
    roles["Admin"] = {
        {"kernelConfig", {"read", "write", "execute"}},
        {"logFiles", {"read", "delete"}}
    };

    // Regular User Role (Rajasic Guna - Action, Passion, Execution)
    // The user's Dharma is to operate within the system's intended functions.
    roles["User"] = {
        {"kernelConfig", {"read"}},
        {"appData", {"read", "write"}}
    };

    // Auditor Role (Tamasic Guna - Inquiry, Stillness, Observation)
    // The auditor's Dharma is to observe and report, not to change.
    roles["Auditor"] = {
        {"logFiles", {"read"}},
        {"systemMetrics", {"read"}}
    };
}

bool DharmaIAM::checkAccess(const std::string& userRole, const std::string& resource, const std::string& action) {
    std::cout << "Dharma Check: Role '" << userRole << "' requests action '" << action << "' on resource '" << resource << "'." << std::endl;

    if (roles.find(userRole) == roles.end()) {
        logAccessDecision(userRole, resource, action, "Denied - Role does not exist (Adharma).");
        return false;
    }

    const auto& permissions = roles[userRole];

    if (permissions.find(resource) == permissions.end()) {
        logAccessDecision(userRole, resource, action, "Denied - No permissions for resource (Adharma).");
        return false;
    }

    const auto& allowedActions = permissions.at(resource);

    if (allowedActions.find(action) == allowedActions.end()) {
        logAccessDecision(userRole, resource, action, "Denied - Action not permitted (Adharma).");
        return false;
    }

    logAccessDecision(userRole, resource, action, "Granted (Dharma).");
    return true;
}

void DharmaIAM::applySandboxPolicy(const std::string& sandboxName, const std::unordered_set<std::string>& permissions) {
    sandbox_policies[sandboxName] = permissions;
    std::cout << "Sandbox Policy Applied: '" << sandboxName << "' has been granted " << permissions.size() << " permissions." << std::endl;
    if (permissions.count("all")) {
        std::cout << "Warning: Granting 'all' permissions to a sandbox is highly privileged and potentially dangerous." << std::endl;
    }
}

void DharmaIAM::logAccessDecision(const std::string& role, const std::string& resource, const std::string& action, const std::string& decision) {
    std::cout << "LOG [DharmaIAM]: " << "Role=" << role << ", Resource=" << resource << ", Action=" << action << ", Decision=" << decision << std::endl;
}

} // namespace Security
} // namespace DivineEarthlyKernels
