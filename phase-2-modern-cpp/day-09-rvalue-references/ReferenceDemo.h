#ifndef REFERENCE_DEMO_H
#define REFERENCE_DEMO_H

#include <string>

class ReferenceDemo
{
public:

    // Integer lvalue
    static void process(int& value);

    // Integer rvalue
    static void process(int&& value);

    // String lvalue
    static void process(const std::string& value);

    // String rvalue
    static void process(std::string&& value);

    // Demonstrate named rvalue reference
    static void demonstrateNamedRvalue();

    // Demonstrate std::move
    static void demonstrateMove();
};

#endif