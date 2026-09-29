#pragma once

#include <string>
#include <vector>
#include <optional>
#include <variant>
#include <tuple>

// ============================================================
// enum class — scoped, doesn't leak names into surrounding scope,
// doesn't implicitly convert to int. Prefer this over plain `enum`
// in all new code (Day 14 topic).
// ============================================================
enum class SensorStatus { Ok, Warning, Fault };

// ============================================================
// constexpr — evaluated at COMPILE time when possible. These aren't
// "const globals" — the compiler can bake them directly into
// generated code, no runtime memory load at all (Day 12 topic).
// ============================================================
constexpr double kWarningThreshold = 70.0;
constexpr double kFaultThreshold   = 90.0;

struct SensorReading {
    std::string  id;
    double       value;
    SensorStatus status;
};

// noexcept — a promise to the compiler and caller that this function
// will never throw. Enables optimizations (no exception-unwinding
// tables) and affects whether std::vector can MOVE vs. must COPY
// elements during reallocation (Day 13 topic).
SensorStatus classify(double value) noexcept;

std::vector<SensorReading> classifyReadings(
    const std::vector<std::pair<std::string, double>>& raw);

// std::optional<double> — the average is undefined for an empty
// vector. Returning optional makes "no answer" a real, checkable
// state instead of a sentinel like -1 or NaN a caller can misuse
// (Day 21 topic).
std::optional<double> average(const std::vector<SensorReading>& readings);

// std::tuple + structured bindings — return multiple values without
// an out-parameter or a one-off struct (Day 24-25 topics).
std::tuple<double, double> minMax(const std::vector<SensorReading>& readings);

// std::variant — a type-safe union. A SensorPayload is EXACTLY ONE
// of these types at any moment, and the compiler enforces you handle
// every alternative via std::visit rather than trusting a manual tag
// field the way a C-style union would (Day 22 topic).
using SensorPayload = std::variant<int, double, std::string>;
std::string describePayload(const SensorPayload& payload);
