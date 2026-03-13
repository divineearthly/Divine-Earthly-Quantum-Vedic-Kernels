#include <iostream>
#include <vector>
#include "include/compute/ParavartyaLogic.h"
#include "include/compute/ShunyamAnyat.h"

int main() {
    std::cout << "--- TREMENDOUS SYSTEM INTEGRATION TEST (PHASE 2) ---\n";
    
    std::vector<float> neurons = {10.5f, 0.001f, 5.2f, 0.0002f, 8.9f};
    std::cout << "[Initial] Neurons: ";
    for(float n : neurons) std::cout << n << " ";
    
    ShunyamAnyat::applyPruning(neurons, 0.01f);
    std::cout << "\n[Shunyam] After Pruning (< 0.01): ";
    for(float n : neurons) std::cout << n << " ";

    ParavartyaLogic::normalize(neurons, 10.0f);
    std::cout << "\n[Paravartya] After Normalization (Factor 10): ";
    for(float n : neurons) std::cout << n << " ";

    std::cout << "\n\n[Success] Tremendous integration phase 2 complete.\n";
    return 0;
}
