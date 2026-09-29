#include "SensorPipeline.h"
#include <algorithm>
#include <numeric>
#include <iterator>
#include <type_traits>

SensorStatus classify(double value) noexcept {
    if (value >= kFaultThreshold)   return SensorStatus::Fault;
    if (value >= kWarningThreshold) return SensorStatus::Warning;
    return SensorStatus::Ok;
}

std::vector<SensorReading> classifyReadings(
    const std::vector<std::pair<std::string, double>>& raw) {
    std::vector<SensorReading> out;
    out.reserve(raw.size());

    std::transform(raw.begin(), raw.end(), std::back_inserter(out),
        [](const auto& r) {
            return SensorReading{r.first, r.second, classify(r.second)};
        });

    return out;
}

std::optional<double> average(const std::vector<SensorReading>& readings) {
    if (readings.empty()) return std::nullopt;

    double total = std::accumulate(readings.begin(), readings.end(), 0.0,
        [](double acc, const SensorReading& r) { return acc + r.value; });

    return total / static_cast<double>(readings.size());
}

std::tuple<double, double> minMax(const std::vector<SensorReading>& readings) {
    auto [minIt, maxIt] = std::minmax_element(
        readings.begin(), readings.end(),
        [](const SensorReading& a, const SensorReading& b) {
            return a.value < b.value;
        });
    return {minIt->value, maxIt->value};
}

std::string describePayload(const SensorPayload& payload) {
    return std::visit([](auto&& v) -> std::string {
        using T = std::decay_t<decltype(v)>;
        if constexpr (std::is_same_v<T, int>)
            return "int reading: " + std::to_string(v);
        else if constexpr (std::is_same_v<T, double>)
            return "double reading: " + std::to_string(v);
        else
            return "string reading: " + v;
    }, payload);
}
