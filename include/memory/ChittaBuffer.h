#ifndef CHITTA_BUFFER_H
#define CHITTA_BUFFER_H

#include <vector>
#include <iostream>
#include <cstdint>
#include "include/memory/GarudaShredder.h"

namespace DivineEarthlyKernels::Memory {

class ChittaBuffer {
private:
    uint8_t* secureData;
    size_t capacity;

public:
    ChittaBuffer(size_t size);
    ~ChittaBuffer();

    void loadData(const std::vector<uint8_t>& input);
};

} // namespace DivineEarthlyKernels::Memory

#endif
