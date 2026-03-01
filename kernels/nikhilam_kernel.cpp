
#include <iostream>
#include <vector>
#include <cmath>

class NikhilamKernel {
public:
    // Nikhilam Sutra: Efficient for numbers near a base (e.g., 10, 100, 1000)
    // Formula: (Base + Deficiency1) * (Base + Deficiency2)
    static long nikhilam_multiply(int num1, int num2, int base) {
        int d1 = num1 - base;
        int d2 = num2 - base;

        // Result = (num1 + d2) * base + (d1 * d2)
        long left_part = (long)(num1 + d2) * base; // Cast to long before multiplication
        long right_part = (long)d1 * d2;

        return left_part + right_part;
    }
};

int main() {
    std::cout << "Nikhilam Kernel: 98 * 97 using base 100 = "
              << NikhilamKernel::nikhilam_multiply(98, 97, 100) << std::endl;
    return 0;
}
