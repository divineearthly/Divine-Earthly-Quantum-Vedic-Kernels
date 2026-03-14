#include "include/compute/VedicUpaSutras.h"
#include <numeric>

namespace DivineEarthlyKernels {
namespace Compute {

// Upa-Sutra: Adyamadyenantyamantyena - "First by first and last by last"
void VedicUpaSutras::processArrayBoundaries(const std::vector<int>& arr) {
    if (arr.size() < 2) return;
    int first_by_first = arr.front() * arr.front();
    int last_by_last = arr.back() * arr.back();
    std::cout << "[Upa-Sutra] Adyamadyena: First*First = " << first_by_first 
              << ", Last*Last = " << last_by_last << std::endl;
}

// Upa-Sutra: Lopanasthapanabhyam - "By alternate elimination and retention"
std::vector<int> VedicUpaSutras::filterAlternating(const std::vector<int>& data) {
    std::vector<int> result;
    for (size_t i = 0; i < data.size(); ++i) {
        if (i % 2 == 0) { // Retain
            result.push_back(data[i]);
        }
        // Else: Eliminate
    }
    std::cout << "[Upa-Sutra] Lopanasthapanabhyam: Filtered vector size from " << data.size() 
              << " to " << result.size() << std::endl;
    return result;
}

void VedicUpaSutras::demonstrate() {
    std::cout << "\n--- Vedic Upa-Sutras Demonstration ---\n";
    squareEndingIn5(65);
    nikhilamMultiply(65530, 65535);
    
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    processArrayBoundaries(data);
    filterAlternating(data);
    std::cout << "--- End Upa-Sutras Demonstration ---\n";
}

} // namespace Compute
} // namespace DivineEarthlyKernels
