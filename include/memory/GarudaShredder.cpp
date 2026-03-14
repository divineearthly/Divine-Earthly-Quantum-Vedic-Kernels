#include "include/memory/GarudaShredder.h"
#include <cstring> // For memset
#include <cstdint>
#include <iostream>

// A less secure, but portable, implementation of a memory wipe.
void GarudaShredder::dissolve(void* ptr, size_t size) {
    std::cout << "[Garuda] Dissolving memory region (less secure method).\n";
    // Simple XOR wipe with a pattern
    volatile uint8_t* p = static_cast<volatile uint8_t*>(ptr);
    const uint8_t pattern = 0xDE;
    for (size_t i = 0; i < size; ++i) {
        p[i] ^= pattern;
    }
    // Overwrite with zeros
    memset(ptr, 0, size);
}
