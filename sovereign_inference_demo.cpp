
#include <iostream>
#include <vector>
#include <functional>
#include <fstream>
#include "include/compute/VedicALU.h"
#include "include/io/PaniniNLP.h"
#include "include/io/PranaRouter.h"
#include "include/core/ThreeGunas.h"
#include "include/memory/GarudaShredder.h"
#include "include/core/BhagavadGita.h"

// Helper function to convert Action enum to string
std::string actionToString(DivineEarthlyKernels::Core::BhagavadGita::Action action) {
    switch (action) {
        case DivineEarthlyKernels::Core::BhagavadGita::ACTION_A: return "ACTION_A";
        case DivineEarthlyKernels::Core::BhagavadGita::ACTION_B: return "ACTION_B";
        case DivineEarthlyKernels::Core::BhagavadGita::ACTION_C: return "ACTION_C";
        case DivineEarthlyKernels::Core::BhagavadGita::ACTION_D: return "ACTION_D";
        default: return "UNKNOWN_ACTION";
    }
}

void createDummyFile(const std::string& filename) {
    std::ofstream outfile(filename);
    outfile << "This is a temporary file for deletion demonstration.";
    outfile.close();
}

int main() {
    DivineEarthlyKernels::Core::ThreeGunas systemState;
    PranaRouter router;

    std::cout << "--- SOVEREIGN EDGE AI INFERENCE DEMO ---" << std::endl;

    // Step 1: Ingest via Panini (Rajas State)
    systemState.transitionTo(DivineEarthlyKernels::Core::SystemGuna::RAJAS);
    std::string prompt = "Run a compute task and then deploy the model";
    std::vector<uint32_t> tokens;
    PaniniTokenizer::processSentence(prompt, tokens);

    // Step 2: Decide on an action using Bhagavad Gita
    systemState.transitionTo(DivineEarthlyKernels::Core::SystemGuna::SATTVA);
    int num_actions = 4; // ACTION_A, B, C, D
    int action_index = tokens.size() % num_actions;
    DivineEarthlyKernels::Core::BhagavadGita::Action chosen_action = static_cast<DivineEarthlyKernels::Core::BhagavadGita::Action>(action_index);
    std::cout << "[Gita] Based on token count (" << tokens.size() << "), chose Action: " << actionToString(chosen_action) << std::endl;

    // Step 3: Execute the chosen action
    systemState.transitionTo(DivineEarthlyKernels::Core::SystemGuna::RAJAS);
    switch (chosen_action) {
        case DivineEarthlyKernels::Core::BhagavadGita::ACTION_A: {
            std::cout << "[Executor] ACTION_A: Running Vedic ALU computation." << std::endl;
            const size_t N = 4; // Small 4x4 matrix for demo
            std::vector<float> A(N * N, 2.0f), B(N * N, 3.0f), C(N * N, 0.0f);
            VedicALU::matrixMultiplyVedic(A.data(), B.data(), C.data(), N);
            std::cout << "[VedicALU] 4x4 Matrix multiplication complete." << std::endl;
            break;
        }
        case DivineEarthlyKernels::Core::BhagavadGita::ACTION_B: {
            std::cout << "[Executor] ACTION_B: Dispatching a task via PranaRouter." << std::endl;
            router.dispatch([]() { std::cout << "[PranaRouter] Executing dispatched task!\n"; });
            router.processNext(); // Process immediately for demo
            break;
        }
        case DivineEarthlyKernels::Core::BhagavadGita::ACTION_C: {
            std::cout << "[Executor] ACTION_C: Securely deleting a temporary file." << std::endl;
            std::string temp_file = "temp_for_deletion.txt";
            createDummyFile(temp_file);
            // Read the file into a buffer
            std::ifstream file(temp_file, std::ios::binary | std::ios::ate);
            std::streamsize size = file.tellg();
            file.seekg(0, std::ios::beg);
            std::vector<char> buffer(size);
            if (file.read(buffer.data(), size)) {
                // Shred the buffer
                 GarudaShredder::dissolve(buffer.data(), size);
                std::cout << "[GarudaShredder] File content shredded from memory." << std::endl;
            }
            // Delete the file
            std::remove(temp_file.c_str());
            break;
        }
        case DivineEarthlyKernels::Core::BhagavadGita::ACTION_D: {
            std::cout << "[Executor] ACTION_D: Simulating model deployment." << std::endl;
            std::cout << "[Deployer] Model deployment hooks initiated... done." << std::endl;
            break;
        }
    }

    systemState.transitionTo(DivineEarthlyKernels::Core::SystemGuna::TAMAS);
    return 0;
}
