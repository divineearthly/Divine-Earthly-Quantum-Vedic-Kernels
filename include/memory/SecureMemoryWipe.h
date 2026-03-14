#ifndef SECURE_MEMORY_WIPE_H
#define SECURE_MEMORY_WIPE_H

#include <cstddef>
#include <cstring>
#include <iostream>

class SecureMemoryWipe {
public:
    // Bare-metal cryptographic memory wipe
    static void wipe(void* ptr, size_t size);
};

#endif
