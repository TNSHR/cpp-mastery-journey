#include "PerfectForwardingDemo.h"

#include <iostream>

// ==========================================
// Integer lvalue overload
// ==========================================

void PerfectForwardingDemo::process(int& value)
{
    std::cout
        << "process(int&) -> LVALUE"
        << " | value = "
        << value
        << std::endl;
}


// ==========================================
// Integer rvalue overload
// ==========================================

void PerfectForwardingDemo::process(int&& value)
{
    std::cout
        << "process(int&&) -> RVALUE"
        << " | value = "
        << value
        << std::endl;
}


// ==========================================
// String lvalue overload
// ==========================================

void PerfectForwardingDemo::process(
    const std::string& value)
{
    std::cout
        << "process(const std::string&) "
        << "-> LVALUE STRING"
        << " | value = "
        << value
        << std::endl;
}


// ==========================================
// String rvalue overload
// ==========================================

void PerfectForwardingDemo::process(
    std::string&& value)
{
    std::cout
        << "process(std::string&&) "
        << "-> RVALUE STRING"
        << " | value = "
        << value
        << std::endl;
}