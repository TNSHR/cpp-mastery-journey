#include "ReferenceDemo.h"

#include <iostream>
#include <utility>

// ==========================================
// Integer lvalue
// ==========================================

void ReferenceDemo::process(int& value)
{
    std::cout
        << "process(int&) -> LVALUE"
        << std::endl;

    std::cout
        << "Value: "
        << value
        << std::endl;
}


// ==========================================
// Integer rvalue
// ==========================================

void ReferenceDemo::process(int&& value)
{
    std::cout
        << "process(int&&) -> RVALUE"
        << std::endl;

    std::cout
        << "Value: "
        << value
        << std::endl;
}


// ==========================================
// String lvalue
// ==========================================

void ReferenceDemo::process(
    const std::string& value)
{
    std::cout
        << "process(const std::string&) -> "
        << "CONST LVALUE REFERENCE"
        << std::endl;

    std::cout
        << "Value: "
        << value
        << std::endl;
}


// ==========================================
// String rvalue
// ==========================================

void ReferenceDemo::process(
    std::string&& value)
{
    std::cout
        << "process(std::string&&) -> "
        << "RVALUE"
        << std::endl;

    std::cout
        << "Value: "
        << value
        << std::endl;
}


// ==========================================
// Named Rvalue Reference
// ==========================================

void ReferenceDemo::demonstrateNamedRvalue()
{
    std::cout
        << "\n========== Named Rvalue Reference =========="
        << std::endl;

    int&& reference = 100;

    std::cout
        << "Created int&& reference = 100"
        << std::endl;

    std::cout
        << "\nCalling process(reference):"
        << std::endl;

    process(reference);

    std::cout
        << "\nCalling process(std::move(reference)):"
        << std::endl;

    process(std::move(reference));
}


// ==========================================
// std::move Demonstration
// ==========================================

void ReferenceDemo::demonstrateMove()
{
    std::cout
        << "\n========== std::move Demonstration =========="
        << std::endl;

    int value = 50;

    std::cout
        << "Original value: "
        << value
        << std::endl;

    std::cout
        << "\nCalling process(value):"
        << std::endl;

    process(value);

    std::cout
        << "\nCalling process(std::move(value)):"
        << std::endl;

    process(std::move(value));

    std::cout
        << "\nValue after std::move: "
        << value
        << std::endl;
}