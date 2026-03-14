#include "include/core/TheYugas.h"
#include "include/core/ThreeGunas.h"
#include "include/compute/VedicKernels.h"
#include "include/memory/YogaSutras.h"
#include "include/memory/Puranas.h"
#include "include/memory/AkashicRecords.h"
#include "include/memory/ChittaBuffer.h"
#include <memory>

// Using declarations for the core components
using DivineEarthlyKernels::Core::TheYugas;
using DivineEarthlyKernels::Core::ThreeGunas;
using DivineEarthlyKernels::Core::SystemGuna;

int main() {
    // 1. Initialize the Core State & Power Manager
    ThreeGunas stateManager;

    // 2. Register the Vedic Compute Kernels with the State Manager
    stateManager.registerKernel(std::make_shared<UrdhvaTiryagbhyamKernel>());
    stateManager.registerKernel(std::make_shared<NikhilamKernel>());

    // 3. Initialize the System Scheduler (The Yugas)
    // The scheduler is linked to the state manager to control its state.
    TheYugas scheduler(stateManager);

    // 4. Start the scheduler to begin the cyclical operation of the system.
    scheduler.startScheduler();

    std::cout << "\n--- System has completed its scheduled operational cycles ---\n";

    // 5. Demonstrate the memory components
    DivineEarthlyKernels::Memory::YogaSutras::demonstrate();
    DivineEarthlyKernels::Memory::Puranas::demonstrate();
    
    //The other files are not demonstrable and are not included

    return 0;
}
