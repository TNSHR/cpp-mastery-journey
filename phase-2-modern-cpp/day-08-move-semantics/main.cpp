#include <iostream>
#include <utility>

#include "Resource.h"

void separator()
{
    std::cout
        << "\n==========================================\n";
}

int main()
{
    std::cout
        << "==========================================\n"
        << "   Modern C++ - Move Semantics\n"
        << "==========================================\n";


    // ==================================================
    // 1. Constructor
    // ==================================================

    separator();

    std::cout
        << "1. Creating Resource A"
        << std::endl;

    Resource resourceA(5);

    resourceA.display();


    // ==================================================
    // 2. Copy Constructor
    // ==================================================

    separator();

    std::cout
        << "2. Copy Constructor"
        << std::endl;

    Resource resourceB = resourceA;

    std::cout
        << "\nResource A:"
        << std::endl;

    resourceA.display();

    std::cout
        << "\nResource B:"
        << std::endl;

    resourceB.display();


    // ==================================================
    // 3. Move Constructor
    // ==================================================

    separator();

    std::cout
        << "3. Move Constructor"
        << std::endl;

    Resource resourceC =
        std::move(resourceA);

    std::cout
        << "\nResource A after move:"
        << std::endl;

    resourceA.display();

    std::cout
        << "\nResource C after move:"
        << std::endl;

    resourceC.display();


    // ==================================================
    // 4. Copy Assignment
    // ==================================================

    separator();

    std::cout
        << "4. Copy Assignment"
        << std::endl;

    Resource resourceD(3);

    std::cout
        << "\nResource D before assignment:"
        << std::endl;

    resourceD.display();

    resourceD = resourceB;

    std::cout
        << "\nResource D after copy assignment:"
        << std::endl;

    resourceD.display();


    // ==================================================
    // 5. Move Assignment
    // ==================================================

    separator();

    std::cout
        << "5. Move Assignment"
        << std::endl;

    Resource resourceE(2);

    std::cout
        << "\nResource E before move assignment:"
        << std::endl;

    resourceE.display();

    resourceE = std::move(resourceC);

    std::cout
        << "\nResource C after move:"
        << std::endl;

    resourceC.display();

    std::cout
        << "\nResource E after move assignment:"
        << std::endl;

    resourceE.display();


    // ==================================================
    // 6. Demonstrate std::move with Function
    // ==================================================

    separator();

    std::cout
        << "6. std::move Demonstration"
        << std::endl;

    Resource resourceF(4);

    std::cout
        << "\nBefore move:"
        << std::endl;

    resourceF.display();

    Resource resourceG =
        std::move(resourceF);

    std::cout
        << "\nAfter move:"
        << std::endl;

    std::cout
        << "Resource F:"
        << std::endl;

    resourceF.display();

    std::cout
        << "\nResource G:"
        << std::endl;

    resourceG.display();


    // ==================================================
    // End
    // ==================================================

    separator();

    std::cout
        << "Program Ending..."
        << std::endl;

    return 0;
}