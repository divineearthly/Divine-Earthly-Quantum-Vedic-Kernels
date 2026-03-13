#ifndef SHAKTI_PEETHAS_H
#define SHAKTI_PEETHAS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> // For std::sort, std::max

namespace DivineEarthlyKernels {
namespace Core {

// Level 62: Shakti-Peethas (Distributed Power & Node Logic)
// Structure: Specific geographical locations where cosmic power is concentrated.
// Application: The blueprint for decentralized edge computing. It provides the logic for placing high-compute nodes across a network to ensure zero latency and maximum power.
class ShaktiPeethas {
public:
    // Represents a conceptual compute node in the distributed network.
    struct ComputeNode {
        std::string id;
        std::string location; // Geographical or logical location
        double compute_capacity_gflops; // Theoretical GFLOPS (Giga Floating-point Operations Per Second)
        double current_load_percent; // Current utilization
        double energy_efficiency_factor; // Higher is better

        ComputeNode(std::string i, std::string l, double cc, double eef) 
            : id(i), location(l), compute_capacity_gflops(cc), current_load_percent(0.0), energy_efficiency_factor(eef) {}
    };

    // Simulates placing a high-compute node in an optimal location.
    static void deployHighComputeNode(std::vector<ComputeNode>& network_nodes, const ComputeNode& new_node) {
        network_nodes.push_back(new_node);
        std::cout << "[ShaktiPeethas] Deployed high-compute node '" << new_node.id 
                  << "' at location '" << new_node.location 
                  << "' with capacity " << new_node.compute_capacity_gflops << " GFLOPS.\n";
    }

    // Identifies the optimal node (Shakti-Peetha) for a given task based on load and capacity.
    static std::string findOptimalNode(const std::vector<ComputeNode>& network_nodes, double required_gflops) {
        std::cout << "[ShaktiPeethas] Searching for optimal node for a task requiring " << required_gflops << " GFLOPS...\n";
        if (network_nodes.empty()) {
            return "No nodes available.";
        }

        std::string best_node_id = "";
        double min_normalized_cost = -1.0; // Combines load, efficiency, and capacity

        for (const auto& node : network_nodes) {
            if (node.compute_capacity_gflops * (1.0 - node.current_load_percent) >= required_gflops) {
                // Calculate a conceptual cost/score: lower is better
                // Prioritize lower load and higher efficiency
                double normalized_cost = (node.current_load_percent / node.compute_capacity_gflops) / node.energy_efficiency_factor;
                
                if (best_node_id == "" || normalized_cost < min_normalized_cost) {
                    min_normalized_cost = normalized_cost;
                    best_node_id = node.id;
                }
            }
        }

        if (best_node_id != "") {
            std::cout << "  - Optimal node found: '" << best_node_id << "'.\n";
        } else {
            std::cout << "  - No suitable node found with required capacity.\n";
        }
        return best_node_id;
    }

    // Simulates dynamic load balancing across nodes.
    static void balanceLoad(std::vector<ComputeNode>& network_nodes) {
        std::cout << "[ShaktiPeethas] Initiating dynamic load balancing across network nodes.\n";
        // Very simplistic: sort by load and redistribute (conceptual)
        std::sort(network_nodes.begin(), network_nodes.end(), [](const ComputeNode& a, const ComputeNode& b) {
            return a.current_load_percent < b.current_load_percent;
        });

        if (network_nodes.size() > 1) {
            double total_load = 0.0;
            for(const auto& node : network_nodes) total_load += node.current_load_percent;
            double avg_load = total_load / network_nodes.size();

            for(auto& node : network_nodes) {
                node.current_load_percent = avg_max(avg_load, 0.0, 1.0); // Conceptual smoothing
            }
            std::cout << "  - Load balanced. Average load is now " << (avg_load * 100) << "%.\n";
        } else {
            std::cout << "  - Not enough nodes to balance load.\n";
        }
    }

private:
    // Helper function to keep load within 0-1 range for simulation
    static double avg_max(double val, double min_val, double max_val) {
        return std::max(min_val, std::min(val, max_val));
    }

public:
    static void demonstrate() {
        std::cout << "\n--- Demonstrating Level 62: Shakti-Peethas (Distributed Power & Node Logic) ---\n";

        std::vector<ComputeNode> distributed_network;
        deployHighComputeNode(distributed_network, {"Edge_Processor_A", "Data Center West", 1000.0, 0.9});
        deployHighComputeNode(distributed_network, {"Cloud_GPU_Cluster_B", "Cloud East", 5000.0, 0.95});
        deployHighComputeNode(distributed_network, {"Mobile_NPU_C", "User Device", 50.0, 0.8});
        deployHighComputeNode(distributed_network, {"Edge_Processor_D", "Data Center West", 1200.0, 0.85});

        distributed_network[0].current_load_percent = 0.8;
        distributed_network[1].current_load_percent = 0.2;
        distributed_network[2].current_load_percent = 0.95;
        distributed_network[3].current_load_percent = 0.6;

        findOptimalNode(distributed_network, 300.0);
        findOptimalNode(distributed_network, 4000.0);
        findOptimalNode(distributed_network, 2000.0);

        balanceLoad(distributed_network);
    }
};

} // namespace Core
} // namespace DivineEarthlyKernels

#endif // SHAKTI_PEETHAS_H
