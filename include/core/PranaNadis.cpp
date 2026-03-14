#include "PranaNadis.h"

namespace DivineEarthlyKernels {
namespace Core {

PranaNadis::Nadi::Nadi(std::string n, double v) : name(n), is_active(false), voltage_mv(v) {}

void PranaNadis::activateNadi(Nadi& nadi, double target_voltage_mv) {
    nadi.is_active = true;
    nadi.voltage_mv = target_voltage_mv;
    std::cout << "[PranaNadis] Nadi '" << nadi.name << "' ACTIVATED. Prana flowing at " << nadi.voltage_mv << "mV.\n";
}

void PranaNadis::deactivateNadi(Nadi& nadi) {
    nadi.is_active = false;
    nadi.voltage_mv = 0.0; // Minimal or no voltage
    std::cout << "[PranaNadis] Nadi '" << nadi.name << "' DEACTIVATED. Entering low-power state.\n";
}

void PranaNadis::manageCpuPower(const std::string& core_id, double required_load_percent) {
    std::cout << "[PranaNadis] Managing power for CPU core '" << core_id << "'. Required load: " << required_load_percent * 100 << "%.\n";
    if (required_load_percent > 0.7) {
        std::cout << "  - Boosting Prana (voltage/frequency) to high-performance mode.\n";
    } else if (required_load_percent > 0.3) {
        std::cout << "  - Normal Prana flow. Balanced performance.\n";
    } else if (required_load_percent > 0.0) {
        std::cout << "  - Reducing Prana. Low-power mode for light tasks.\n";
    } else {
        std::cout << "  - Entering deep sleep. Minimal Prana consumption.\n";
    }
}

void PranaNadis::routeData(const std::string& data_packet_id, const std::vector<Nadi*>& active_nadis) {
    std::cout << "[PranaNadis] Routing data packet '" << data_packet_id << "' through active Nadis:\n";
    if (active_nadis.empty()) {
        std::cout << "  - No active Nadis found. Data packet dropped.\n";
        return;
    }
    for (const auto& nadi : active_nadis) {
        if (nadi->is_active) {
            std::cout << "  - Packet '" << data_packet_id << "' flowing through Nadi '" << nadi->name << ".\n";
        }
    }
}

void PranaNadis::demonstrate() {
    std::cout << "\n--- Demonstrating Level 49: Prana & Nadis (Power Management & Data Bus Framework) ---\n";

    Nadi gpu_bus("GPU_Render_Bus", 1.2);
    Nadi sensor_bus("Sensor_Input_Bus", 0.8);
    Nadi network_nadi("Network_Tx_Rx", 1.0);

    activateNadi(gpu_bus, 1.5); // High load, boost voltage
    manageCpuPower("Core_0", 0.9);
    routeData("FrameBuffer_Update_001", {&gpu_bus});

    std::cout << "\n";
    activateNadi(sensor_bus, 0.7);
    manageCpuPower("Core_1", 0.2);
    routeData("Telemetry_Data_123", {&sensor_bus, &network_nadi});

    std::cout << "\n";
    deactivateNadi(gpu_bus);
    deactivateNadi(sensor_bus);
    manageCpuPower("Core_0", 0.0); // Idle
}

} // namespace Core
} // namespace DivineEarthlyKernels
