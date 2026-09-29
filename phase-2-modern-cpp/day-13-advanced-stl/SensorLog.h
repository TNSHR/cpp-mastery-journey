#pragma once

#include "RingBuffer.h"
#include <cstddef>

// ============================================================
// SensorLog — a concrete, non-template wrapper around
// RingBuffer<double, 5>. Declaration only; defined in
// SensorLog.cpp (same .h/.cpp split as Day 09/10/11).
// Fixes T=double, Capacity=5 for a realistic "last 5 readings" log.
// ============================================================
class SensorLog {
public:
    void record(double value);
    double latestAverage() const;
    std::size_t count() const;

    RingBuffer<double, 5>::Iterator begin() const;
    RingBuffer<double, 5>::Iterator end() const;

private:
    RingBuffer<double, 5> buffer_;
};
