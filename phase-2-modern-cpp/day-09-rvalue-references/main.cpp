#include <iostream>
#include <string>
#include <utility>

#include "ReferenceDemo.h"

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
        << "   Modern C++ - Rvalue References"
        << std::endl;

    std::cout
        << "=========================================="
        << std::endl;


    // ==================================================
    // 1. Integer lvalue
    // ==================================================

    separator();

    std::cout
        << "1. Integer Lvalue"
        << std::endl;

    int number = 10;

    std::cout
        << "Calling process(number):"
        << std::endl;

    ReferenceDemo::process(number);


    // ==================================================
    // 2. Integer rvalue
    // ==================================================

    separator();

    std::cout
        << "2. Integer Rvalue"
        << std::endl;

    std::cout
        << "Calling process(100):"
        << std::endl;

    ReferenceDemo::process(100);


    // ==================================================
    // 3. std::move()
    // ==================================================

    separator();

    std::cout
        << "3. std::move()"
        << std::endl;

    std::cout
        << "Calling process(std::move(number)):"
        << std::endl;

    ReferenceDemo::process(
        std::move(number)
    );


    // ==================================================
    // 4. Check original integer
    // ==================================================

    separator();

    std::cout
        << "4. Original Integer After std::move"
        << std::endl;

    std::cout
        << "number = "
        << number
        << std::endl;


    // ==================================================
    // 5. Named rvalue reference
    // ==================================================

    separator();

    std::cout
        << "5. Named Rvalue Reference"
        << std::endl;

    ReferenceDemo::demonstrateNamedRvalue();


    // ==================================================
    // 6. String lvalue
    // ==================================================

    separator();

    std::cout
        << "6. String Lvalue"
        << std::endl;

    std::string name = "Shrinath";

    std::cout
        << "Calling process(name):"
        << std::endl;

    ReferenceDemo::process(name);


    // ==================================================
    // 7. Temporary string / rvalue
    // ==================================================

    separator();

    std::cout
        << "7. Temporary String"
        << std::endl;

    std::cout
        << "Calling process(std::string(\"Hello\")):"
        << std::endl;

    ReferenceDemo::process(
        std::string("Hello")
    );


    // ==================================================
    // 8. String + std::move
    // ==================================================

    separator();

    std::cout
        << "8. String with std::move()"
        << std::endl;

    std::cout
        << "Original name: "
        << name
        << std::endl;

    std::cout
        << "\nCalling process(std::move(name)):"
        << std::endl;

    ReferenceDemo::process(
        std::move(name)
    );

    std::cout
        << "\nName after std::move(): "
        << name
        << std::endl;


    // ==================================================
    // 9. Explicit demonstration
    // ==================================================

    separator();

    std::cout
        << "9. std::move Demonstration"
        << std::endl;

    ReferenceDemo::demonstrateMove();


    // ==================================================
    // End
    // ==================================================

    separator();

    std::cout
        << "Program Ending..."
        << std::endl;

    return 0;
}