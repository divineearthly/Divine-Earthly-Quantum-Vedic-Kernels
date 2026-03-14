#include "include/memory/ChittaBuffer.h"

namespace DivineEarthlyKernels::Memory {

ChittaBuffer::ChittaBuffer(size_t size) : capacity(size) {
    secureData = new uint8_t[capacity];
    std::cout << "[Chitta] Secure buffer created. Capacity: " << capacity << " bytes.\n";
}

ChittaBuffer::~ChittaBuffer() {
    GarudaShredder::dissolve(secureData, capacity);
    delete[] secureData;
    std::cout << "[Chitta] Secure buffer destroyed.\n";
}

void ChittaBuffer::loadData(const std::vector<uint8_t>& input) {
    size_t to_copy = std::min(input.size(), capacity);
    std::copy(input.begin(), input.begin() + to_copy, secureData);
    std::cout << "[Chitta] Loaded " << to_copy << " bytes into buffer.\n";
}

} // namespace DivineEarthlyKernels::Memory
