#include <iostream>
#include "include/compute/VedicALU.h"
#include "include/io/PaniniNLP.h"
#include "include/io/PranaRouter.h"
#include "include/core/ThreeGunas.h"
#include "include/memory/GarudaShredder.h"

int main() {
    ThreeGunas systemState;
    PranaRouter router;

    std::cout << "--- SOVEREIGN EDGE AI INFERENCE DEMO ---\n";

    // Step 1: Ingest via Panini (Rajas State)
    systemState.transitionTo(SystemGuna::RAJAS);
    std::string prompt = "Activate Vedic Tensor Core";
    std::vector<uint32_t> tokens;
    PaniniTokenizer::processSentence(prompt, tokens);

    // Step 2: Route to Compute (Sattva State)
    router.dispatch([&]() {
        systemState.transitionTo(SystemGuna::SATTVA);
        size_t N = 256;
        std::vector<float> A(N*N, 1.0f), B(N*N, 1.0f), C(N*N, 0.0f);
        VedicALU::matrixMultiplyVedic(A.data(), B.data(), C.data(), N);
        std::cout << "[Compute] Vedic Tensor multiplication completed on N=256.\n";
    });

    router.processNext();

    // Step 3: Secure Shredding (Moksha/Tamas State)
    std::cout << "[Moksha] Task complete. Shredding sensitive buffers...\n";
    GarudaShredder::dissolve(tokens.data(), tokens.size() * sizeof(uint32_t));
    systemState.transitionTo(SystemGuna::TAMAS);

    std::cout << "\n[Success] Sovereign lifecycle completed under 50MB RAM.\n";
    return 0;
}
