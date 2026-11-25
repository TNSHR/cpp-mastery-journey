#ifndef INHERITING_CONSTRUCTOR_DEMO_H
#define INHERITING_CONSTRUCTOR_DEMO_H

#include <iostream>
#include <string>

// =====================================================
// Base Class
// =====================================================

class Person
{
protected:

    std::string name;
    int age;

public:

    Person();

    Person(
        const std::string& personName,
        int personAge
    );

    void printPerson() const;
};


// =====================================================
// Derived Class
// =====================================================

class Student : public Person
{
private:

    int rollNumber{};

public:

    // Inherit constructors from Person
    using Person::Person;

    Student(
        const std::string& studentName,
        int studentAge,
        int studentRollNumber
    );

    void printStudent() const;
};

#endif
