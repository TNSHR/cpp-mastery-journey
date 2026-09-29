#include <iostream>
#include <string>

#include "InitializerListDemo.h"

int main()
{
    std::cout
        << "====================================\n"
        << "    C++ Initializer List Demo\n"
        << "====================================\n";


    int externalValue = 100;


    // =========================================
    // Create object
    // =========================================

    InitializerListDemo student(
        101,
        "Rahul",
        85.5,
        500,
        externalValue
    );


    // =========================================
    // Print object
    // =========================================

    student.print();


    // =========================================
    // Modify referenced value
    // =========================================

    student.updateReference(250);

    std::cout
        << "\nAfter reference update:\n";

    std::cout
        << "externalValue: "
        << externalValue
        << '\n';


    // =========================================
    // Const member
    // =========================================

    std::cout
        << "\nFixed value: "
        << student.getFixedValue()
        << '\n';


    std::cout
        << "\nProgram completed.\n";

    return 0;
}
