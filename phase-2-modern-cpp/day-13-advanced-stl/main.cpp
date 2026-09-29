#include "SensorLog.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    SensorLog log;

    std::cout << "=== 1. Push 3 readings (buffer capacity 5) ===\n";
    log.record(10.0);
    log.record(20.0);
    log.record(30.0);
    std::cout << "  count = " << log.count() << ", average = " << log.latestAverage() << "\n";

    std::cout << "\n=== 2. std::for_each over the custom iterator ===\n";
    std::for_each(log.begin(), log.end(), [](double v) { std::cout << "  reading: " << v << "\n"; });

    std::cout << "\n=== 3. std::distance using iterator_traits ===\n";
    std::cout << "  distance(begin, end) = " << std::distance(log.begin(), log.end()) << "\n";

    std::cout << "\n=== 4. Overflow the buffer (push 4 more, capacity=5) ===\n";
    log.record(40.0);
    log.record(50.0);
    log.record(60.0);
    log.record(70.0);
    std::for_each(log.begin(), log.end(), [](double v) { std::cout << "  reading: " << v << "\n"; });
    std::cout << "  average = " << log.latestAverage() << "\n";

    std::cout << "\n=== 5. std::copy the custom iterator range into a vector ===\n";
    std::vector<double> snapshot;
    std::copy(log.begin(), log.end(), std::back_inserter(snapshot));
    std::cout << "  snapshot size = " << snapshot.size() << "\n";

    return 0;
}
