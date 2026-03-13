#include <iostream>
#include <vector>
#include <cstring>
#include "memory/GarudaShredder.h"

int main() {
    std::cout << "--- GARUDA SHREDDER: SECURITY VALIDATION TEST ---\n";

    // 1. Initialize 'sensitive' data
    const std::string sensitive_data = "TOP_SECRET_VEDIC_KEY_777";
    size_t size = sensitive_data.size();
    char* buffer = new char[size + 1];
    std::strcpy(buffer, sensitive_data.c_str());

    std::cout << "[Initial] Data in buffer: " << buffer << "\n";

    // 2. Execute Garuda Shredder (Moksha Protocol)
    std::cout << "[Action] Invoking Garuda Shredder dissolution...\n";
    GarudaShredder::dissolve(buffer, size);

    // 3. Post-Shredding Inspection
    bool data_cleared = true;
    for(size_t i = 0; i < size; ++i) {
        if(buffer[i] == sensitive_data[i]) {
            data_cleared = false;
            break;
        }
    }

    if(data_cleared) {
        std::cout << "[Success] Verification: Sensitive data obliterated from memory.\n";
    } else {
        std::cout << "[Failure] Verification: Sensitive remnants detected in buffer.\n";
    }

    delete[] buffer;
    return data_cleared ? 0 : 1;
}
