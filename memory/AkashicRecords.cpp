#include "../include/memory/AkashicRecords.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono>

void AkashicRecords::recordState(const uint32_t* data, size_t size, const std::string& filename) {
    if (data == nullptr || size == 0) {
        std::cerr << "[AkashicRecords] Error: No data to record or invalid size.\n";
        return;
    }

    std::ofstream outFile(filename, std::ios_base::app); // Open in append mode
    if (!outFile.is_open()) {
        std::cerr << "[AkashicRecords] Error: Could not open file '" << filename << "' for logging.\n";
        return;
    }

    // Get current time for timestamp
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    outFile << "[AkashicRecords] Log Entry - Timestamp: " << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << " - Data Size: " << size << "\n";
    outFile << "[ ";
    for (size_t i = 0; i < size; ++i) {
        outFile << "0x" << std::hex << std::setw(8) << std::setfill('0') << data[i];
        if (i < size - 1) {
            outFile << ", ";
        }
    }
    outFile << " ]\n\n";

    outFile.close();
    std::cout << "[AkashicRecords] State recorded to '" << filename << "'.\n";
}
