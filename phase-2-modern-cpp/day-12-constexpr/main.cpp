#include <iostream>

#include "ConstexprDemo.h"

int main()
{
    std::cout
        << "====================================\n";

    std::cout
        << "      C++ constexpr Demo\n";

    std::cout
        << "====================================\n";


    // =========================================
    // 1. constexpr variable
    // =========================================

    constexpr int size = 10;

    //int data[size];

    std::cout
        << "\nArray size: "
        << size
        << '\n';


    // =========================================
    // 2. Compile-time square
    // =========================================

    constexpr int square =
        ConstexprDemo::square(10);

    std::cout
        << "Square: "
        << square
        << '\n';


    // =========================================
    // 3. Compile-time factorial
    // =========================================

    constexpr int factorial =
        ConstexprDemo::factorial(5);

    std::cout
        << "Factorial: "
        << factorial
        << '\n';


    // =========================================
    // 4. Compile-time even check
    // =========================================

    constexpr bool even =
        ConstexprDemo::isEven(20);

    std::cout
        << "20 is even: "
        << std::boolalpha
        << even
        << '\n';


    // =========================================
    // 5. Compile-time max
    // =========================================

    constexpr int maximum =
        ConstexprDemo::max(
            100,
            200
        );

    std::cout
        << "Maximum: "
        << maximum
        << '\n';


    // =========================================
    // 6. Runtime constexpr function
    // =========================================

    int runtimeValue;

    std::cout
        << "\nEnter a number: ";

    std::cin
        >> runtimeValue;

    int runtimeSquare =
        ConstexprDemo::square(
            runtimeValue
        );

    std::cout
        << "Runtime square: "
        << runtimeSquare
        << '\n';


    // =========================================
    // 7. if constexpr
    // =========================================

    std::cout
        << "\nType information:\n";

    ConstexprDemo::describeType(10);

    ConstexprDemo::describeType(3.14);

    ConstexprDemo::describeType("C++");


    // =========================================
    // 8. End
    // =========================================

    std::cout
        << "\nProgram completed.\n";

    return 0;
}