#include <iostream>

#include "EnumClassDemo.h"

int main()
{
    std::cout
        << "====================================\n"
        << "        C++ enum class Demo\n"
        << "====================================\n";


    // =========================================
    // 1. Create enum class values
    // =========================================

    EnumClassDemo::Status status =
        EnumClassDemo::Status::Pending;

    EnumClassDemo::Priority priority =
        EnumClassDemo::Priority::High;


    // =========================================
    // 2. Print values
    // =========================================

    EnumClassDemo::printStatus(status);

    EnumClassDemo::printPriority(priority);


    // =========================================
    // 3. Change status
    // =========================================

    status =
        EnumClassDemo::Status::Processing;

    EnumClassDemo::printStatus(status);


    // =========================================
    // 4. switch with enum class
    // =========================================

    switch (status)
    {
        case EnumClassDemo::Status::Pending:
            std::cout << "Waiting for processing\n";
            break;

        case EnumClassDemo::Status::Processing:
            std::cout << "Currently processing\n";
            break;

        case EnumClassDemo::Status::Completed:
            std::cout << "Processing completed\n";
            break;

        case EnumClassDemo::Status::Failed:
            std::cout << "Processing failed\n";
            break;
    }


    // =========================================
    // 5. Comparison
    // =========================================

    if (status == EnumClassDemo::Status::Processing)
    {
        std::cout
            << "Status is Processing\n";
    }


    std::cout
        << "Program completed.\n";

    return 0;
}