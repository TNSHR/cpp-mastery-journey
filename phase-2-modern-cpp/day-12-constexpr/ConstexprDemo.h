#ifndef CONSTEXPR_DEMO_H
#define CONSTEXPR_DEMO_H

#include <iostream>
#include <type_traits>

class ConstexprDemo
{
public:

    static constexpr int MAX_BUFFER_SIZE = 256;

    static constexpr int square(int value)
    {
        return value * value;
    }

    static constexpr int factorial(int value)
    {
        int result = 1;

        for (int i = 1; i <= value; ++i)
        {
            result *= i;
        }

        return result;
    }

    static constexpr bool isEven(int value)
    {
        return value % 2 == 0;
    }

    static constexpr int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    template<typename T>
    static void describeType(const T&)
    {
        if constexpr (std::is_integral_v<T>)
        {
            std::cout << "Integral type\n";
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            std::cout << "Floating-point type\n";
        }
        else
        {
            std::cout << "Other type\n";
        }
    }
};

#endif