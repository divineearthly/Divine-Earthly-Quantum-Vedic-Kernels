#include <fstream>
#include <iostream>
#include "AkashicRecords.h"

void AkashicRecords::recordState(const uint32_t* data, size_t size, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app);
    if (outFile.is_open()) {
        outFile << "[Akashic Event] Recording " << size << " tokens: ";
        for (size_t i = 0; i < size; ++i) {
            outFile << data[i] << (i == size - 1 ? "" : ", ");
        }
        outFile << "\n";
        outFile.close();
        std::cout << "[AkashicRecords] State successfully archived to " << filename << ".\n";
    } else {
        std::cerr << "[Error] Failed to access Akashic storage: " << filename << "\n";
    }
}
