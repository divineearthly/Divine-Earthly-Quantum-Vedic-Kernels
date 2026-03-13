#ifndef CHITTA_BUFFER_H
#define CHITTA_BUFFER_H

#include <vector>
#include <iostream>
#include "GarudaShredder.h"

class ChittaBuffer {
private:
    uint8_t* secureData;
        size_t capacity;

        public:
            // Allocate raw memory from the heap
                ChittaBuffer(size_t size) : capacity(size) {
                        secureData = new uint8_t[capacity];
                                std::cout << "[Chitta] Secure memory allocated: " << capacity << " bytes.\n";
                                    }

                                        // Load sensitive token/tensor data
                                            void loadData(const std::vector<uint8_t>& input) {
                                                    size_t limit = (input.size() < capacity) ? input.size() : capacity;
                                                            for(size_t i = 0; i < limit; ++i) {
                                                                        secureData[i] = input[i];
                                                                                }
                                                                                        std::cout << "[Chitta] Data loaded into secure hardware buffer.\n";
                                                                                            }

                                                                                                // The Destructor: When this object is destroyed, Moksha is achieved
                                                                                                    ~ChittaBuffer() {
                                                                                                            std::cout << "[Chitta] Buffer destruction initiated. Calling Garuda...\n";
                                                                                                                    GarudaShredder::dissolve(secureData, capacity);
                                                                                                                            delete[] secureData; // Free the clean memory back to the OS
                                                                                                                                    secureData = nullptr;
                                                                                                                                        }
                                                                                                                                        };

                                                                                                                                        #endif
