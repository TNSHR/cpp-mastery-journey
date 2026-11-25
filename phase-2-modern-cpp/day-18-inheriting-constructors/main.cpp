#include <iostream>

#include "InheritingConstructorDemo.h"

int main()
{
    std::cout
        << "========================================\n"
        << "      Inheriting Constructors Demo\n"
        << "========================================\n";


    // =================================================
    // 1. Base class constructor
    // =================================================

    std::cout
        << "\n1. Person Object\n";

    Person person(
        "Amit",
        35
    );

    person.printPerson();


    // =================================================
    // 2. Derived class using inherited constructor
    // =================================================

    std::cout
        << "\n2. Student Using Inherited Constructor\n";

    Student student(
        "Rahul",
        20
    );

    student.printStudent();


    // =================================================
    // 3. Student's own constructor
    // =================================================

    std::cout
        << "\n3. Student Using Own Constructor\n";

    Student student2(
        "Priya",
        21,
        101
    );

    student2.printStudent();


    std::cout
        << "\nProgram completed.\n";

    return 0;
}