#include "SensorPipeline.h"
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::pair<std::string, double>> raw = {
        {"temp-1", 45.0},
        {"temp-2", 72.5},
        {"temp-3", 95.0},
        {"temp-4", 60.0},
        {"temp-5", 91.2},
    };

    auto readings = classifyReadings(raw);

    std::cout << "=== 1. Classified readings ===\n";
    for (const auto& r : readings) {
        std::cout << "  " << r.id << " = " << r.value << " -> "
                  << (r.status == SensorStatus::Ok ? "OK" :
                      r.status == SensorStatus::Warning ? "WARNING" : "FAULT")
                  << "\n";
    }

    std::cout << "\n=== 2. std::sort by value, descending ===\n";
    std::sort(readings.begin(), readings.end(),
        [](const auto& a, const auto& b) { return a.value > b.value; });
    for (const auto& r : readings) std::cout << "  " << r.id << " = " << r.value << "\n";

    std::cout << "\n=== 3. std::count_if — how many FAULT? ===\n";
    auto faultCount = std::count_if(readings.begin(), readings.end(),
        [](const auto& r) { return r.status == SensorStatus::Fault; });
    std::cout << "  Fault count: " << faultCount << "\n";

    std::cout << "\n=== 4. std::find_if — first FAULT reading ===\n";
    auto it = std::find_if(readings.begin(), readings.end(),
        [](const auto& r) { return r.status == SensorStatus::Fault; });
    if (it != readings.end()) std::cout << "  First fault: " << it->id << "\n";

    std::cout << "\n=== 5. std::optional average ===\n";
    if (auto avg = average(readings)) {
        std::cout << "  Average = " << *avg << "\n";
    }

    std::cout << "\n=== 6. std::tuple + structured bindings for min/max ===\n";
    auto [minVal, maxVal] = minMax(readings);
    std::cout << "  min = " << minVal << ", max = " << maxVal << "\n";

    std::cout << "\n=== 7. std::variant + std::visit ===\n";
    std::vector<SensorPayload> payloads = {42, 3.14, std::string("calibration-ok")};
    for (const auto& p : payloads) std::cout << "  " << describePayload(p) << "\n";

    std::cout << "\n=== 8. erase-remove idiom — drop OK readings, keep issues only ===\n";
    readings.erase(
        std::remove_if(readings.begin(), readings.end(),
            [](const auto& r) { return r.status == SensorStatus::Ok; }),
        readings.end());
    for (const auto& r : readings) std::cout << "  issue: " << r.id << "\n";

    return 0;
}
