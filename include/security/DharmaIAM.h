#ifndef DHARMA_IAM_H
#define DHARMA_IAM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace DivineEarthlyKernels {
namespace Security {

// Level 30: Dharma Shastras (The Access Control & Governance Framework)
// Structure: Comprehensive codes of conduct, laws, and governance protocols for maintaining societal order.
// Application: Identity and Access Management (IAM), Access Control Lists (ACL), and defining strict sandbox permissions 
// for mobile-first deployments to prevent unauthorized system calls and ensure the AI remains sovereign and secure.
class DharmaIAM {
public:
    // Represents a conceptual user or entity with roles.
    struct User {
        std::string userId;
        std::vector<std::string> roles;

        bool hasRole(const std::string& role) const {
            for (const auto& r : roles) {
                if (r == role) return true;
            }
            return false;
        }
    };

    // Represents a conceptual resource that needs access control.
    struct Resource {
        std::string resourceId;
        std::map<std::string, std::vector<std::string>> permissions; // role -> list of actions

        bool isPermitted(const std::string& role, const std::string& action) const {
            if (permissions.count(role)) {
                for (const auto& act : permissions.at(role)) {
                    if (act == action) return true;
                }
            }
            return false;
        }
    };

    // Checks if a user has permission to perform an action on a resource.
    static bool checkAccess(const User& user, const Resource& resource, const std::string& action) {
        std::cout << "[Dharma] Checking access for User '" << user.userId << "' on Resource '" << resource.resourceId << "' for action '" << action << "'.\n";
        for (const auto& role : user.roles) {
            if (resource.isPermitted(role, action)) {
                std::cout << "  - Access GRANTED (Role: " << role << ").\n";
                return true;
            }
        }
        std::cout << "  - Access DENIED.\n";
        return false;
    }

    // Defines a sandbox policy for a process or module.
    static void applySandboxPolicy(const std::string& module_name, const std::vector<std::string>& allowed_system_calls) {
        std::cout << "[Dharma] Applying sandbox policy to module '" << module_name << "'.\n";
        std::cout << "  - Allowed system calls: ";
        for (const auto& call : allowed_system_calls) {
            std::cout << call << " ";
        }
        std::cout << ".\n";
        // In a real system, this would configure OS-level security features like seccomp or namespaces.
    }

    static void demonstrate() {
        std::cout << "\n--- Demonstrating Level 30: Dharma Shastras (Access Control & Governance) ---\n";

        User adminUser = {"admin_001", {"admin", "developer"}};
        User regularUser = {"user_101", {"viewer"}};

        Resource kernelConfig = {"kernel_config", {
            {"admin", {"read", "write", "delete"}},
            {"developer", {"read", "write"}}
        }};

        Resource logFiles = {"system_logs", {
            {"admin", {"read", "delete"}},
            {"viewer", {"read"}}
        }};

        checkAccess(adminUser, kernelConfig, "write");
        checkAccess(regularUser, kernelConfig, "read");
        checkAccess(regularUser, kernelConfig, "delete");
        checkAccess(regularUser, logFiles, "read");

        applySandboxPolicy("Untrusted_Plugin", {"read_file", "write_log"});
        applySandboxPolicy("Critical_Service", {"all"});
    }
};

} // namespace Security
} // namespace DivineEarthlyKernels

#endif // DHARMA_IAM_H
