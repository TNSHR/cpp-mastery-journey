// #include "VariadicDemo.h"
// #include <iostream>

// int main() {
//     std::cout << "=== 1. Recursive variadic unpacking ===\n";
//     printAll(1, "sensors online:", 3.14, 'x');

//     std::cout << "\n=== 2. Fold expression sum ===\n";
//     std::cout << "sum(1,2,3,4,5) = " << sum(1, 2, 3, 4, 5) << "\n";

//     std::cout << "\n=== 3. Fold expression + Logger (combines Day 10 forwarding) ===\n";
//     Logger logger;
//     logAll(logger, "Widget count:", 4, "avg temp:", 36.6);

//     std::cout << "\n=== 4. sizeof... at compile time ===\n";
//     reportPackSize(1, 2, 3);
//     reportPackSize();
//     reportPackSize("only one");

//     return 0;
// }

#include <iostream>
#include <string>

#include "VariadicDemo.h"

void separator()
{
    std::cout
        << "\n=========================================="
        << std::endl;
}

int main()
{
    std::cout
        << "=========================================="
        << std::endl;

    std::cout
        << "   Modern C++ - Variadic Templates"
        << std::endl;

    std::cout
        << "=========================================="
        << std::endl;


    // ==================================================
    // 1. Print multiple arguments
    // ==================================================

    separator();

    std::cout
        << "1. Print Multiple Arguments"
        << std::endl;

    VariadicDemo::printAll(
        10,
        20,
        30,
        40
    );


    // ==================================================
    // 2. Different types
    // ==================================================

    separator();

    std::cout
        << "2. Different Types"
        << std::endl;

    VariadicDemo::printAll(
        "C++",
        10,
        3.14,
        'A'
    );


    // ==================================================
    // 3. Count arguments
    // ==================================================

    separator();

    std::cout
        << "3. Count Arguments"
        << std::endl;

    std::cout
        << "Number of arguments: "
        << VariadicDemo::countArgs(
            10,
            20,
            30,
            40,
            50
        )
        << std::endl;


    // ==================================================
    // 4. Sum
    // ==================================================

    separator();

    std::cout
        << "4. Sum"
        << std::endl;

    std::cout
        << "Sum = "
        << VariadicDemo::sum(
            10,
            20,
            30
        )
        << std::endl;


    // ==================================================
    // 5. Safe sum
    // ==================================================

    separator();

    std::cout
        << "5. Safe Sum"
        << std::endl;

    std::cout
        << "Sum = "
        << VariadicDemo::sumSafe(
            1,
            2,
            3,
            4
        )
        << std::endl;


    // ==================================================
    // 6. Product
    // ==================================================

    separator();

    std::cout
        << "6. Product"
        << std::endl;

    std::cout
        << "Product = "
        << VariadicDemo::product(
            2,
            3,
            4
        )
        << std::endl;


    // ==================================================
    // 7. Recursive processing
    // ==================================================

    separator();

    std::cout
        << "7. Recursive Variadic Processing"
        << std::endl;

    VariadicDemo::recursivePrint(
        10,
        20,
        30,
        40
    );


    // ==================================================
    // 8. Empty pack
    // ==================================================

    separator();

    std::cout
        << "8. Empty Pack"
        << std::endl;

    std::cout
        << "Argument count: "
        << VariadicDemo::countArgs()
        << std::endl;


    // ==================================================
    // 9. Perfect forwarding
    // ==================================================

    separator();

    std::cout
        << "9. Variadic Perfect Forwarding"
        << std::endl;

    std::string name = "Shrinath";

    VariadicDemo::forwardAll(
        name,
        std::string("Modern C++"),
        100
    );


    // ==================================================
    // 10. End
    // ==================================================

    separator();

    std::cout
        << "Program Ending..."
        << std::endl;

    return 0;
}