#include <iostream>

#include "DelegatingConstructorDemo.h"

int main()
{
    std::cout
        << "========================================\n"
        << "     Delegating Constructor Demo\n"
        << "========================================\n";


    // =========================================
    // 1. Default constructor
    // =========================================

    std::cout
        << "\n1. Default Constructor\n";

    DelegatingConstructorDemo student1;

    student1.print();


    // =========================================
    // 2. ID constructor
    // =========================================

    std::cout
        << "\n2. ID Constructor\n";

    DelegatingConstructorDemo student2(101);

    student2.print();


    // =========================================
    // 3. Full constructor
    // =========================================

    std::cout
        << "\n3. Full Constructor\n";

    DelegatingConstructorDemo student3(
        102,
        "Rahul",
        87.5
    );

    student3.print();


    std::cout
        << "\nProgram completed.\n";

    return 0;
}