#include <iostream>
#include <string>

#include "NoexceptDemo.h"

void separator()
{
    std::cout
        << "\n====================================\n";
}

int main()
{
    std::cout
        << "====================================\n"
        << "       C++ noexcept Demo\n"
        << "====================================\n";


    // =========================================
    // 1. noexcept function
    // =========================================

    separator();

    NoexceptDemo::safeFunction();


    // =========================================
    // 2. Check noexcept status
    // =========================================

    separator();

    std::cout
        << std::boolalpha
        << "safeFunction is noexcept: "
        << noexcept(
            NoexceptDemo::safeFunction()
        )
        << '\n';

    std::cout
        << "riskyFunction is noexcept: "
        << noexcept(
            NoexceptDemo::riskyFunction()
        )
        << '\n';


    // =========================================
    // 3. Exception handling
    // =========================================

    separator();

    try
    {
        NoexceptDemo::riskyFunction();
    }
    catch (const std::exception& e)
    {
        std::cout
            << "Caught exception: "
            << e.what()
            << '\n';
    }


    // =========================================
    // 4. Conditional noexcept
    // =========================================

    separator();

    int number = 10;

    NoexceptDemo::process(number);

    std::string text = "C++";

    NoexceptDemo::process(text);


    // =========================================
    // 5. Compile-time noexcept check
    // =========================================

    separator();

    constexpr bool safe =
        noexcept(
            NoexceptDemo::safeFunction()
        );

    std::cout
        << "Compile-time noexcept check: "
        << safe
        << '\n';


    // =========================================
    // 6. End
    // =========================================

    separator();

    std::cout
        << "Program completed.\n";

    return 0;
}