#include "SensorLog.h"
#include <numeric>

void SensorLog::record(double value) { buffer_.push(value); }

double SensorLog::latestAverage() const {
    if (buffer_.size() == 0) return 0.0;
    double total = std::accumulate(buffer_.begin(), buffer_.end(), 0.0);
    return total / static_cast<double>(buffer_.size());
}

std::size_t SensorLog::count() const { return buffer_.size(); }

RingBuffer<double, 5>::Iterator SensorLog::begin() const { return buffer_.begin(); }
RingBuffer<double, 5>::Iterator SensorLog::end() const { return buffer_.end(); }
