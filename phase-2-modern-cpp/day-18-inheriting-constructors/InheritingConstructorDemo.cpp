#include "InheritingConstructorDemo.h"

// =====================================================
// Person Default Constructor
// =====================================================

Person::Person()
    : name("Unknown"),
      age(0)
{
}


// =====================================================
// Person Parameterized Constructor
// =====================================================

Person::Person(
    const std::string& personName,
    int personAge
)
    : name(personName),
      age(personAge)
{
}


// =====================================================
// Person Print
// =====================================================

void Person::printPerson() const
{
    std::cout
        << "Name: "
        << name
        << '\n';

    std::cout
        << "Age: "
        << age
        << '\n';
}


// =====================================================
// Student Constructor
// =====================================================

Student::Student(
    const std::string& studentName,
    int studentAge,
    int studentRollNumber
)
    : Person(studentName, studentAge),
      rollNumber(studentRollNumber)
{
}


// =====================================================
// Student Print
// =====================================================

void Student::printStudent() const
{
    std::cout
        << "Name: "
        << name
        << '\n';

    std::cout
        << "Age: "
        << age
        << '\n';

    std::cout
        << "Roll Number: "
        << rollNumber
        << '\n';
}