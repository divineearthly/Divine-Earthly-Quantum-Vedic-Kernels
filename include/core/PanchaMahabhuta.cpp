#include "PanchaMahabhuta.h"
#include <cstdlib>

namespace DivineEarthlyKernels {
namespace Core {

void* PanchaMahabhuta::allocateMahabhutaMemory(MahabhutaType type, size_t size_bytes, const std::string& purpose) {
    void* ptr = nullptr;
    std::string type_name;

    switch (type) {
        case PRITHVI:
            ptr = malloc(size_bytes); // Conceptual static/persistent allocation
            type_name = "PRITHVI (Static/Storage)";
            break;
        case JALA:
            ptr = malloc(size_bytes); // Conceptual fluid/dynamic allocation
            type_name = "JALA (Fluid Streams)";
            break;
        case AGNI:
            // Agni is typically active processing, not direct memory allocation.
            // Here, we allocate temporary buffer for processing.
            ptr = malloc(size_bytes);
            type_name = "AGNI (Processing/Volatile)";
            break;
        case VAYU:
            // Vayu is I/O, might involve network buffers.
            ptr = malloc(size_bytes);
            type_name = "VAYU (I/O/Networking)";
            break;
        case AKASHA:
            // Akasha represents virtual/unallocated space, no physical allocation here.
            type_name = "AKASHA (Unallocated/Virtual)";
            std::cout << "[PanchaMahabhuta] Request for AKASHA: This is virtual space. No physical allocation made for '" << purpose << "'.\n";
            return nullptr;
    }

    if (ptr) {
        std::cout << "[PanchaMahabhuta] Allocated " << size_bytes << " bytes as " << type_name << " for: '" << purpose << "' (Address: " << ptr << ").\n";
    } else {
        std::cerr << "[PanchaMahabhuta] Error: Failed to allocate " << size_bytes << " bytes as " << type_name << " for: '" << purpose << "'.\n";
    }
    return ptr;
}

void PanchaMahabhuta::deallocateMahabhutaMemory(void* ptr, MahabhutaType type, const std::string& purpose) {
    if (ptr) {
        free(ptr);
        std::string type_name;
        switch (type) {
            case PRITHVI: type_name = "PRITHVI"; break;
            case JALA: type_name = "JALA"; break;
            case AGNI: type_name = "AGNI"; break;
            case VAYU: type_name = "VAYU"; break;
            case AKASHA: type_name = "AKASHA"; break; // Should not reach here if ptr is null for Akasha
            default: type_name = "UNKNOWN"; break;
        }
        std::cout << "[PanchaMahabhuta] Deallocated " << type_name << " memory for: '" << purpose << "' (Address: " << ptr << ").\n";
    } else {
        std::cout << "[PanchaMahabhuta] Warning: Attempted to deallocate null pointer for '" << purpose << "'.\n";
    }
}

void PanchaMahabhuta::simulateDataFlow(MahabhutaType source_type, MahabhutaType destination_type, const std::string& data_description) {
    std::string source_name, dest_name;
    switch (source_type) {
        case PRITHVI: source_name = "PRITHVI (Storage)"; break;
        case JALA: source_name = "JALA (Stream)"; break;
        case AGNI: source_name = "AGNI (Processor)"; break;
        case VAYU: source_name = "VAYU (Network)"; break;
        case AKASHA: source_name = "AKASHA (Virtual)"; break;
        default: source_name = "UNKNOWN"; break;
    }
    switch (destination_type) {
        case PRITHVI: dest_name = "PRITHVI (Storage)"; break;
        case JALA: dest_name = "JALA (Stream)"; break;
        case AGNI: dest_name = "AGNI (Processor)"; break;
        case VAYU: dest_name = "VAYU (Network)"; break;
        case AKASHA: dest_name = "AKASHA (Virtual)"; break;
        default: dest_name = "UNKNOWN"; break;
    }
    std::cout << "[PanchaMahabhuta] Data flow: '" << data_description << "' from " << source_name << " to " << dest_name << ".\n";
}

void PanchaMahabhuta::demonstrate() {
    std::cout << "\n--- Demonstrating Level 28: Pancha Mahabhuta (Fundamental Data-Type Framework) ---\n";

    void* static_data = allocateMahabhutaMemory(PRITHVI, 1024, "Persistent Configuration");
    void* stream_buffer = allocateMahabhutaMemory(JALA, 4096, "Streaming Input");
    void* compute_registers = allocateMahabhutaMemory(AGNI, 256, "ALU Registers");
    void* network_packet = allocateMahabhutaMemory(VAYU, 1500, "Network Packet Buffer");
    allocateMahabhutaMemory(AKASHA, 8192, "Virtual Memory Map");

    simulateDataFlow(PRITHVI, JALA, "Load config to stream");
    simulateDataFlow(JALA, AGNI, "Process stream data");
    simulateDataFlow(AGNI, VAYU, "Send results over network");

    deallocateMahabhutaMemory(static_data, PRITHVI, "Persistent Configuration");
    deallocateMahabhutaMemory(stream_buffer, JALA, "Streaming Input");
    deallocateMahabhutaMemory(compute_registers, AGNI, "ALU Registers");
    deallocateMahabhutaMemory(network_packet, VAYU, "Network Packet Buffer");
}

} // namespace Core
} // namespace DivineEarthlyKernels
