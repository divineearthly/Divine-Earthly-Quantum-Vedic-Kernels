#ifndef NIRUKTA_H
#define NIRUKTA_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cmath> // For std::sqrt and std::pow

namespace DivineEarthlyKernels {
namespace NLP {

// Level 29: Nirukta (The Semantic & Vector Embedding Framework)
// Author: Yaska
// Structure: The ancient science of etymology, defining how words derive their deep meaning from root sounds and contextual usage.
// Application: Semantic search, Vector Databases, and Word Embeddings (like Word2Vec). Essential for building the RAG 
// (Retrieval-Augmented Generation) pipeline so the AI understands the deep context of prompts rather than just surface-level text.
class Nirukta {
public:
    // Represents a conceptual word embedding (vector).
    using Embedding = std::vector<double>;

    // Simple function to create a conceptual vector embedding for a word.
    // In a real system, this would come from a pre-trained model.
    static Embedding createWordEmbedding(const std::string& word) {
        Embedding embedding;
        // A very simplistic way to generate an embedding for demonstration
        // Sum of ASCII values, character length, and a 'prime' based on first char
        double sum_ascii = 0;
        for (char c : word) {
            sum_ascii += static_cast<double>(c);
        }
        embedding.push_back(sum_ascii / 100.0); // Normalize conceptually
        embedding.push_back(static_cast<double>(word.length()) * 0.1);
        embedding.push_back(static_cast<double>(word.empty() ? 0 : word[0]) / 255.0); // First char as feature
        std::cout << "[Nirukta] Created embedding for '" << word << ": [" << embedding[0] << ", " << embedding[1] << ", " << embedding[2] << "]\n";
        return embedding;
    }

    // Calculates cosine similarity between two embeddings.
    // Higher value means greater semantic similarity.
    static double cosineSimilarity(const Embedding& vec1, const Embedding& vec2) {
        if (vec1.size() != vec2.size() || vec1.empty()) return 0.0;

        double dot_product = 0.0;
        double norm1 = 0.0;
        double norm2 = 0.0;

        for (size_t i = 0; i < vec1.size(); ++i) {
            dot_product += vec1[i] * vec2[i];
            norm1 += vec1[i] * vec1[i];
            norm2 += vec2[i] * vec2[i];
        }

        if (norm1 == 0.0 || norm2 == 0.0) return 0.0; // Avoid division by zero

        double similarity = dot_product / (std::sqrt(norm1) * std::sqrt(norm2));
        std::cout << "[Nirukta] Cosine Similarity: " << similarity << "\n";
        return similarity;
    }

    // Simulates a semantic search in a conceptual vector database.
    static std::string semanticSearch(const std::string& query, const std::map<std::string, Embedding>& vector_db) {
        std::cout << "[Nirukta] Performing semantic search for query: '" << query << "'\n";
        Embedding query_embedding = createWordEmbedding(query);

        double max_similarity = -1.0;
        std::string best_match_key = "No match found.";

        for (const auto& entry : vector_db) {
            double similarity = cosineSimilarity(query_embedding, entry.second);
            if (similarity > max_similarity) {
                max_similarity = similarity;
                best_match_key = entry.first;
            }
        }
        std::cout << "[Nirukta] Best semantic match: '" << best_match_key << "' (Similarity: " << max_similarity << ")\n";
        return best_match_key;
    }

    static void demonstrate() {
        std::cout << "\n--- Demonstrating Level 29: Nirukta (Semantic & Vector Embedding Framework) ---\n";

        // Conceptual Vector Database
        std::map<std::string, Embedding> vector_db;
        vector_db["apple_fruit"] = createWordEmbedding("apple");
        vector_db["red_fruit"] = createWordEmbedding("red");
        vector_db["tasty_food"] = createWordEmbedding("tasty");
        vector_db["car_vehicle"] = createWordEmbedding("car");
        vector_db["banana_fruit"] = createWordEmbedding("banana");

        semanticSearch("fruit", vector_db);
        semanticSearch("automobile", vector_db);
    }
};

} // namespace NLP
} // namespace DivineEarthlyKernels

#endif // NIRUKTA_H
