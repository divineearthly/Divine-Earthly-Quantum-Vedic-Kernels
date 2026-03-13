#include <iostream>
extern void registerBatch1();
extern void registerBatch2();
extern void registerBatch3();
extern void registerBatch4();
extern void registerBatch5();
extern void registerBatch6();

void registerAllBatches() {
    std::cout << "[System] Initializing Global Sutra Registry...\n";
    registerBatch1(); registerBatch2(); registerBatch3();
    registerBatch4(); registerBatch5(); registerBatch6();
}
