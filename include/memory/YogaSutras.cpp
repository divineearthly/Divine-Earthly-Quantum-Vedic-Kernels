#include "include/memory/YogaSutras.h"

namespace DivineEarthlyKernels {
namespace Memory {

YogaSutras::Chitta::Chitta(std::string n, size_t cap) : name(n), capacity(cap) {
    std::cout << "[YogaSutras] Chitta memory bank '" << name << "' initialized with capacity for " << capacity << " samskaras.\n";
}

void YogaSutras::Chitta::storeSamskara(const std::string& key, double value) {
    if (samskaras.size() < capacity) {
        samskaras[key] = value;
        std::cout << "[YogaSutras] Stored Samskara '" << key << "' with value " << value << ".\n";
    }
}

double YogaSutras::Chitta::retrieveSamskara(const std::string& key) const {
    auto it = samskaras.find(key);
    if (it != samskaras.end()) {
        return it->second;
    }
    return 0.0; // Return neutral value if not found
}

void YogaSutras::applyDharana(const std::string& target_data_stream, const std::string& attention_weight_key, Chitta& memory) {
    double attention_weight = memory.retrieveSamskara(attention_weight_key);
    std::cout << "[YogaSutras] Applying Dharana (attention) to '" << target_data_stream 
              << "' with attention weight " << attention_weight << ".\n";
}

void YogaSutras::demonstrate() {
    std::cout << "\n--- Yoga Sutras Demonstration ---\n";
    Chitta longTermMemory("LLM_KnowledgeBase", 1000);
    longTermMemory.storeSamskara("attention_to_logic", 0.95);
    applyDharana("user_query_stream", "attention_to_logic", longTermMemory);
    std::cout << "--- End Yoga Sutras Demonstration ---\n";
}

} // namespace Memory
} // namespace DivineEarthlyKernels
