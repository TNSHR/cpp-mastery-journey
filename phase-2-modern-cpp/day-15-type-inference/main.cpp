#include <iostream>

#include "TypeInferenceDemo.h"

int main()
{
    std::cout
        << "====================================\n"
        << "      C++ Type Inference Demo\n"
        << "====================================\n";


    // =========================================
    // 1. Basic auto
    // =========================================

    TypeInferenceDemo::basicAuto();


    // =========================================
    // 2. auto with containers
    // =========================================

    TypeInferenceDemo::autoWithContainers();


    // =========================================
    // 3. References
    // =========================================

    TypeInferenceDemo::referenceDeduction();


    // =========================================
    // 4. const
    // =========================================

    TypeInferenceDemo::constDeduction();


    // =========================================
    // 5. decltype
    // =========================================

    TypeInferenceDemo::demonstrateDecltype();


    std::cout
        << "\nProgram completed.\n";

    return 0;
}