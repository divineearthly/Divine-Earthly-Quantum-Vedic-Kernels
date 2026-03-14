#ifndef AGAMA_SHASTRAS_H
#define AGAMA_SHASTRAS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional> // For std::function

namespace DivineEarthlyKernels {
namespace Core {

// Level 22: Agama Shastras (The Protocol & API Framework)
// Structure: The vast manuals detailing the exact rituals, protocols, and architectural specifications for temple construction and deity consecration.
// Application: Designing flawless Application Programming Interfaces (APIs), server-client handshake protocols, and establishing strict data formatting rules for microservices to communicate without corruption.
class AgamaShastras {
public:
    // Represents a conceptual API endpoint or service.
    struct ApiEndpoint {
        std::string name;
        std::string path;
        std::string method; // e.g., GET, POST
        std::function<std::string(const std::map<std::string, std::string>&)> handler;
        bool requiresAuthentication;

        // Default constructor for map compatibility
        ApiEndpoint() : requiresAuthentication(false) {}

        ApiEndpoint(std::string n, std::string p, std::string m, std::function<std::string(const std::map<std::string, std::string>&)> h, bool auth = false)
            : name(n), path(p), method(m), handler(h), requiresAuthentication(auth) {}
    };

    // Simulates an API Gateway registering an endpoint.
    static void registerEndpoint(std::map<std::string, ApiEndpoint>& registry, const ApiEndpoint& endpoint) {
        registry[endpoint.path + "_" + endpoint.method] = endpoint;
        std::cout << "[Agama] Registered API Endpoint: '" << endpoint.name << "' at " << endpoint.method << " " << endpoint.path << ".\n";
    }

    // Simulates a client making a request to an API endpoint.
    static std::string makeRequest(const std::map<std::string, ApiEndpoint>& registry, const std::string& path, const std::string& method, const std::map<std::string, std::string>& params, bool authenticated = false) {
        std::string key = path + "_" + method;
        if (registry.count(key)) {
            const ApiEndpoint& endpoint = registry.at(key);
            std::cout << "[Agama] Client attempting " << method << " request to '" << endpoint.name << "' at " << path << ".\n";

            if (endpoint.requiresAuthentication && !authenticated) {
                std::cout << "[Agama] ERROR: Authentication required for this endpoint. Request denied.\n";
                return "ERROR: Unauthorized";
            }
            return endpoint.handler(params);
        } else {
            std::cout << "[Agama] ERROR: Endpoint " << method << " " << path << " not found.\n";
            return "ERROR: Not Found";
        }
    }

    // Simulates defining a strict data format rule.
    static bool validateDataFormat(const std::map<std::string, std::string>& data, const std::vector<std::string>& required_fields) {
        bool all_present = true;
        std::cout << "[Agama] Validating data format for required fields: ";
        for (const auto& field : required_fields) {
            std::cout << field << " ";
            if (data.find(field) == data.end()) {
                all_present = false;
                std::cout << "(Missing: " << field << ") ";
            }
        }
        std::cout << ".\n";
        if (all_present) {
            std::cout << "[Agama] Data format is valid.\n";
        } else {
            std::cout << "[Agama] Data format is invalid: Missing required fields.\n";
        }
        return all_present;
    }

    static void demonstrate() {
        std::cout << "\n--- Demonstrating Level 22: Agama Shastras (Protocol & API Framework) ---\n";

        std::map<std::string, ApiEndpoint> api_registry;

        // Define a simple GET endpoint
        ApiEndpoint getDataEndpoint(
            "Get_System_Status", "/status", "GET",
            [](const std::map<std::string, std::string>& params) -> std::string {
                return "System Status: Operational. Uptime: 1234s.";
            }
        );
        registerEndpoint(api_registry, getDataEndpoint);

        // Define a POST endpoint requiring authentication
        ApiEndpoint updateConfigEndpoint(
            "Update_Configuration", "/config", "POST",
            [](const std::map<std::string, std::string>& params) -> std::string {
                if (params.count("setting") && params.count("value")) {
                    return "Config updated: " + params.at("setting") + " = " + params.at("value") + ".";
                } else {
                    return std::string("ERROR: Missing setting or value parameters.");
                }
            }, true
        );
        registerEndpoint(api_registry, updateConfigEndpoint);

        // Test requests
        std::cout << makeRequest(api_registry, "/status", "GET", {}) << "\n\n";
        std::cout << makeRequest(api_registry, "/config", "POST", {{"setting", "Log_Level"}, {"value", "DEBUG"}}) << "\n\n"; // Unauthorized
        std::cout << makeRequest(api_registry, "/config", "POST", {{"setting", "Log_Level"}, {"value", "DEBUG"}}, true) << "\n\n"; // Authorized

        // Test data format validation
        std::map<std::string, std::string> valid_data = {{"user_id", "123"}, {"transaction_id", "abc"}};
        std::vector<std::string> required_order_fields = {"user_id", "transaction_id", "amount"};
        validateDataFormat(valid_data, {"user_id", "transaction_id"});
        validateDataFormat(valid_data, required_order_fields);
    }
};

} // namespace Core
} // namespace DivineEarthlyKernels

#endif // AGAMA_SHASTRAS_H
