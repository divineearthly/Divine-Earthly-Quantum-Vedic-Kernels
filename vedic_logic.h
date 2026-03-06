#ifndef VEDIC_LOGIC_H
#define VEDIC_LOGIC_H

#include <string>

/**
 * @brief Enterprise-Ready 32-Sutra Vedic Logic Framework
 * @details This header defines the universal bridge for the 16 Main (Ganita) 
 *          and 16 Sub (Upasutra) Vedic logic kernels.
 */

/**
 * @brief Processes a Vedic Sutra request and returns a Gemini-compatible JSON string.
 * 
 * @param sutra_name The name of the specific Sutra logic to execute 
 *                   (e.g., "MainSutra_1" through "MainSutra_16", 
 *                    "SubSutra_1" through "SubSutra_16").
 * @param input_data_json A JSON string containing the numeric values and 
 *                        scaling factors required for the calculation.
 * @return std::string A structured JSON string containing "status", "sutra", 
 *                     "computed_value", and metadata.
 */
std::string processVedicSutra(const std::string& sutra_name, const std::string& input_data_json);

// --- Main Sutra Logic Gates (1-16) ---
// 1. Ekadhikena Purvena
// 2. Nikhilam Navatashcaramam Dashatah
// 3. Urdhva Tiryakbhyam
// ... (Add additional signatures as implemented)

// --- Sub-Sutra Logic Gates (1-16) ---
// 1. Anurupyena
// 2. Sisyate Shesasamjnah
// ... (Add additional signatures as implemented)

#endif // VEDIC_LOGIC_H
