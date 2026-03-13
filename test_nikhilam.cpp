#include <iostream>
#include "include/compute/NikhilamMath.h"

int main() {
    std::cout << "--- NIKHILAM SUTRA (BASE MULTIPLICATION) TEST ---\n";
    
    // Multiplying 98 * 97 using Base 100
    uint64_t a = 98, b = 97, base = 100;
    uint64_t result = NikhilamMath::multiply(a, b, base);

    std::cout << "Input: " << a << " * " << b << " (Base " << base << ")\n";
    std::cout << "Result via Nikhilam: " << result << "\n";
    
    if (result == (a * b)) {
        std::cout << "[Success] Sutra verification complete.\n";
    } else {
        std::cout << "[Error] Sutra logic mismatch.\n";
    }

    return 0;
}
