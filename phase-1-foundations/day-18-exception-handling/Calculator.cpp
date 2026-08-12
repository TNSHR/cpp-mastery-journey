#include "Calculator.h"

#include <stdexcept>

int Calculator::add(int a, int b)
{
    return a + b;
}

int Calculator::subtract(int a, int b)
{
    return a - b;
}

int Calculator::multiply(int a, int b)
{
    return a * b;
}

int Calculator::divide(int a, int b)
{
    if (b == 0)
    {
        throw std::runtime_error(
            "Division by zero is not allowed."
        );
    }

    return a / b;
}