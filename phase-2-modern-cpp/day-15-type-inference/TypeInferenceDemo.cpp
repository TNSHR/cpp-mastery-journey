#include "TypeInferenceDemo.h"

void TypeInferenceDemo::basicAuto()
{
    auto number = 42;
    auto decimal = 3.14;
    auto message = std::string("Hello C++");

    std::cout
        << "number: "
        << number
        << '\n';

    std::cout
        << "decimal: "
        << decimal
        << '\n';

    std::cout
        << "message: "
        << message
        << '\n';
}


void TypeInferenceDemo::autoWithContainers()
{
    std::vector<int> numbers =
    {
        10,
        20,
        30,
        40
    };

    std::cout
        << "\nVector values:\n";

    for (auto value : numbers)
    {
        std::cout
            << value
            << ' ';
    }

    std::cout << '\n';
}


void TypeInferenceDemo::referenceDeduction()
{
    int value = 100;

    auto copy = value;

    auto& reference = value;

    reference = 200;

    std::cout
        << "\nOriginal value: "
        << value
        << '\n';

    std::cout
        << "Copy: "
        << copy
        << '\n';

    std::cout
        << "Reference: "
        << reference
        << '\n';
}


void TypeInferenceDemo::constDeduction()
{
    const int value = 500;

    auto copy = value;

    const auto constCopy = value;

    std::cout
        << "\nOriginal const value: "
        << value
        << '\n';

    std::cout
        << "auto copy: "
        << copy
        << '\n';

    std::cout
        << "const auto copy: "
        << constCopy
        << '\n';
}


void TypeInferenceDemo::demonstrateDecltype()
{
    int number = 10;

    decltype(number) anotherNumber = 20;

    std::cout
        << "\ndecltype value: "
        << anotherNumber
        << '\n';
}