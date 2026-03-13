#include <iostream>
#include "include/compute/VedicALU.h"
#include "include/compute/Ekadhikena.h"
#include "include/core/AntahkaranaEngine.h"

int main() {
    std::cout << "--- TREMENDOUS SYSTEM INTEGRATION TEST ---\n";
    AntahkaranaEngine engine;
    std::cout << "[Engine] Initialized with " << engine.getThreadCount() << " hardware threads.\n";

    std::vector<float> weights;
    Ekadhikena::generateSeries(weights, 10, 1.0f);
    std::cout << "[Ekadhikena] Generated weight series: ";
    for(float f : weights) std::cout << f << " ";
    std::cout << "\n";

    std::cout << "[Success] Tremendous integration phase 1 complete.\n";
    return 0;
}
