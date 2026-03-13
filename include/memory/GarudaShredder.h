#ifndef GARUDA_SHREDDER_H
#define GARUDA_SHREDDER_H

#include <cstddef>
#include <cstring>
#include <iostream>

class GarudaShredder {
public:
    // Bare-metal cryptographic memory wipe - Declaration only
    static void dissolve(void* ptr, size_t size);
};

#endif
