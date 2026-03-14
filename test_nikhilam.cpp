#include <iostream>
#include "include/compute/NikhilamMath.h"

int main() {
    uint64_t a = 100;
    uint64_t b = 37;

    uint64_t result = NikhilamMath::subtract(a, b);

    std::cout << "--- Nikhilam Subtraction Test ---" << std::endl;
    std::cout << a << " - " << b << " = " << result << std::endl;

    return 0;
}
