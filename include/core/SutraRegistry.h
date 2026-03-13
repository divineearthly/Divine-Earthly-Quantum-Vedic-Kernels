#ifndef SUTRA_REGISTRY_H
#define SUTRA_REGISTRY_H

#include <string>
#include <map>
#include <functional>
#include <iostream>

using SutraKernel = std::function<void()>;

class SutraRegistry {
private:
    static std::map<std::string, SutraKernel>& getRegistry() {
        static std::map<std::string, SutraKernel> instance;
        return instance;
    }
public:
    static void registerSutra(const std::string& id, SutraKernel kernel) {
        getRegistry()[id] = kernel;
        std::cout << "[SutraRegistry] Registered: " << id << std::endl;
    }

    static SutraKernel getSutra(const std::string& id) {
        auto& reg = getRegistry();
        if (reg.find(id) != reg.end()) return reg[id];
        return nullptr;
    }
};
#endif