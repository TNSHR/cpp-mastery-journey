// #include "VariadicDemo.h"

// void Logger::logLine(const std::string& line) {
//     std::cout << "[LOG] " << line << "\n";
// }

#include "VariadicDemo.h"

// ==========================================
// Recursive base case
// ==========================================

void VariadicDemo::recursivePrint()
{
    std::cout
        << '\n';
}


// ==========================================
// Perfect forwarding base case
// ==========================================

void VariadicDemo::printForwarded()
{
    std::cout
        << '\n';
}
