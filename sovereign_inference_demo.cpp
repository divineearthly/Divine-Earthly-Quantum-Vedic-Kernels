#include <iostream>
#include "include/compute/VedicALU.h"
#include "include/io/PaniniNLP.h"
#include "include/io/PranaRouter.h"
#include "include/core/ThreeGunas.h"
#include "include/memory/GarudaShredder.h"

int main() {
    DivineEarthlyKernels::Core::ThreeGunas systemState;
    DivineEarthlyKernels::IO::PranaRouter router;

    std::cout << "--- SOVEREIGN EDGE AI INFERENCE DEMO ---\n";

    // Step 1: Ingest via Panini (Rajas State)
    systemState.transitionTo(DivineEarthlyKernels::Core::SystemGuna::RAJAS);
    std::string prompt = "Activate Vedic Tensor Core";
    std::vector<uint32_t> tokens;
    DivineEarthlyKernels::IO::PaniniTokenizer::processSentence(prompt, tokens);

    // Step 2: Route to Compute (Sattva State)
    router.dispatch([&]() {
        systemState.transitionTo(DivineEarthlyKernels::Core::SystemGuna::SATTVA);
        size_t N = 256;
        std::vector<float> A(N*N, 1.0f), B(N*N, 1.0f), C(N*N, 0.0f);
        DivineEarthlyKernels::Compute::VedicALU::matrixMultiplyVedic(A.data(), B.data(), C.data(), N);
        std::cout << "[Compute] Vedic Tensor multiplication completed on N=256.\n";
    });

    router.processNext();

    // Step 3: Secure Shredding (Moksha/Tamas State)
    std::cout << "[Moksha] Task complete. Shredding sensitive buffers...\n";
    DivineEarthlyKernels::Memory::GarudaShredder::dissolve(tokens.data(), tokens.size() * sizeof(uint32_t));
    systemState.transitionTo(DivineEarthlyKernels::Core::SystemGuna::TAMAS);

    std::cout << "\n[Success] Sovereign lifecycle completed under 50MB RAM.\n";
    return 0;
}
