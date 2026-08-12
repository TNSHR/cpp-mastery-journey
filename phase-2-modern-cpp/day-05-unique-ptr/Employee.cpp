#include "Employee.h"

#include <iostream>

/*
-----------------------------------------
Default Constructor
-----------------------------------------
*/

Employee::Employee()
{
    id = 0;
    name = "";
    salary = 0.0;

    std::cout
        << "Default Constructor Called"
        << std::endl;
}

/*
-----------------------------------------
Parameterized Constructor
-----------------------------------------
*/

Employee::Employee(
    int id,
    const std::string& name,
    double salary)
{
    this->id = id;
    this->name = name;
    this->salary = salary;

    std::cout
        << "Employee Created : "
        << this->name
        << std::endl;
}

/*
-----------------------------------------
Destructor
-----------------------------------------
*/

Employee::~Employee()
{
    std::cout
        << "Employee Destroyed : "
        << name
        << std::endl;
}

/*
-----------------------------------------
Setter Functions
-----------------------------------------
*/

void Employee::setId(int id)
{
    this->id = id;
}

void Employee::setName(const std::string& name)
{
    this->name = name;
}

void Employee::setSalary(double salary)
{
    this->salary = salary;
}

/*
-----------------------------------------
Getter Functions
-----------------------------------------
*/

int Employee::getId() const
{
    return id;
}

std::string Employee::getName() const
{
    return name;
}

double Employee::getSalary() const
{
    return salary;
}

/*
-----------------------------------------
Display Function
-----------------------------------------
*/

void Employee::display() const
{
    std::cout
        << "ID      : "
        << id
        << std::endl;

    std::cout
        << "Name    : "
        << name
        << std::endl;

    std::cout
        << "Salary  : "
        << salary
        << std::endl;
}