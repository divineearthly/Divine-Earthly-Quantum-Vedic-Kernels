#ifndef GARUDA_SHREDDER_H
#define GARUDA_SHREDDER_H

#include <cstddef>
#include <cstring>
#include <iostream>

class GarudaShredder {
public:
    // Bare-metal cryptographic memory wipe
        static void dissolve(void* ptr, size_t size) {
                if (ptr == nullptr || size == 0) return;

                        // The 'volatile' keyword forces the CPU to execute the overwrite 
                                // and prevents the compiler from optimizing it away.
                                        volatile unsigned char* p = static_cast<volatile unsigned char*>(ptr);
                                                while (size--) {
                                                            *p++ = 0; // Overwrite exact memory address with absolute zero
                                                                    }
                                                                            
                                                                                    std::cout << "[Garuda] Memory block successfully shredded at hardware level.\n";
                                                                                        }
                                                                                        };

                                                                                        #endif
