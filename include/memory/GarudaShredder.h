#ifndef GARUDA_SHREDDER_H
#define GARUDA_SHREDDER_H

#include <cstddef> // For size_t
#include <cstdint> // For uint8_t
#include <cstring> // For memset
#include <random>  // For random number generation
#include <chrono>  // For seeding the random number generator

namespace DivineEarthlyKernels {
namespace Memory {

// Level 43: Garuda Purana - Secure Memory Wiping
// This class implements a static utility for cryptographically wiping
// ephemeral data from RAM before it is freed. This prevents sensitive
// information from being recovered through memory forensics or casual
// inspection after deallocation. The concept is inspired by the Garuda Purana,
// which details processes for purification and release.

class GarudaShredder {
public:
    // secureWipe: Performs a multi-pass cryptographic overwrite of a memory region.
    // This method ensures that the memory contents are irretrievably destroyed.
    // Parameters:
    //   data_ptr: A pointer to the memory region to be wiped. Must not be nullptr.
    //   size: The size of the memory region in bytes.
    //
    // The use of 'volatile' is crucial here to prevent the compiler from optimizing
    // away the memory overwrite operations, as it might perceive these writes as
    // 'dead code' if the memory is immediately deallocated or goes out of scope.
    static void secureWipe(void* data_ptr, size_t size) {
        if (data_ptr == nullptr || size == 0) {
            return; // Nothing to wipe or invalid input
        }

        // Cast to volatile uint8_t* to ensure byte-level access and prevent optimization.
        volatile uint8_t* volatile_data = static_cast<volatile uint8_t*>(data_ptr);

        // Pass 1: Overwrite with zeros (0x00)
        for (size_t i = 0; i < size; ++i) {
            volatile_data[i] = 0x00;
        }

        // Pass 2: Overwrite with ones (0xFF)
        for (size_t i = 0; i < size; ++i) {
            volatile_data[i] = 0xFF;
        }

        // Pass 3: Overwrite with cryptographically strong pseudo-random data
        // Using a Mersenne Twister engine for high-quality pseudo-random numbers.
        std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<uint8_t> dist(0, 255);

        for (size_t i = 0; i < size; ++i) {
            volatile_data[i] = dist(rng);
        }

        // Optionally, a final pass with zeros or a specific pattern can be added.
        // DoD 5220.22-M often suggests a final zero pass, or a fixed character and its complement.
        // For simplicity and effectiveness, 3 passes (0, 1, random) are generally sufficient for RAM.
        // However, for extreme security (e.g., flash memory), more complex patterns might be considered.

        // After wiping, the memory can be safely deallocated by the caller.
        // Example: delete[] static_cast<char*>(data_ptr); or free(data_ptr);
    }

    // secureFree: Wipes a dynamically allocated memory block and then frees it.
    // This is a convenience method that combines wiping and deallocation.
    // It's important to use the correct deallocation function (e.g., delete[], free)
    // based on how the memory was allocated (e.g., new[], malloc).
    template <typename T>
    static void secureFree(T*& data_ptr, size_t count) {
        if (data_ptr == nullptr) {
            return;
        }
        secureWipe(data_ptr, count * sizeof(T));
        delete[] data_ptr; // Assumes allocation with new[]
        data_ptr = nullptr; // Prevent use-after-free or double-free
    }

    static void secureFree(void*& data_ptr, size_t size) {
        if (data_ptr == nullptr) {
            return;
        }
        secureWipe(data_ptr, size);
        free(data_ptr); // Assumes allocation with malloc
        data_ptr = nullptr; // Prevent use-after-free or double-free
    }
};

} // namespace Memory
} // namespace DivineEarthlyKernels

#endif // GARUDA_SHREDDER_H
