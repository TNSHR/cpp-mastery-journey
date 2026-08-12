#include "EmployeeManager.h"

#include <iostream>

/*
-----------------------------------------
Constructor
-----------------------------------------
*/

EmployeeManager::EmployeeManager()
{
    std::cout << "Employee Manager Created"
              << std::endl;
}

/*
-----------------------------------------
Add Employee
-----------------------------------------
*/

void EmployeeManager::addEmployee(
    const Employee& employee)
{
    employees.push_back(employee);
}

/*
-----------------------------------------
Display Using auto
-----------------------------------------
*/

void EmployeeManager::displayUsingAuto() const
{
    std::cout << "\n=============================="
              << std::endl;

    std::cout << "Using auto (Copy)"
              << std::endl;

    std::cout << "=============================="
              << std::endl;

    for (auto employee : employees)
    {
        employee.display();
    }
}

/*
-----------------------------------------
Display Using auto&
-----------------------------------------
*/

void EmployeeManager::displayUsingAutoReference()
{
    std::cout << "\n=============================="
              << std::endl;

    std::cout << "Using auto& (Reference)"
              << std::endl;

    std::cout << "=============================="
              << std::endl;

    for (auto& employee : employees)
    {
        employee.setSalary(
            employee.getSalary() + 5000);

        employee.display();
    }
}

/*
-----------------------------------------
Display Using const auto&
-----------------------------------------
*/

void EmployeeManager::displayUsingConstAutoReference() const
{
    std::cout << "\n=============================="
              << std::endl;

    std::cout << "Using const auto&"
              << std::endl;

    std::cout << "=============================="
              << std::endl;

    for (const auto& employee : employees)
    {
        employee.display();
    }
}

/*
-----------------------------------------
Getter
-----------------------------------------
*/

std::vector<Employee>&
EmployeeManager::getEmployees()
{
    return employees;
}

const std::vector<Employee>&
EmployeeManager::getEmployees() const
{
    return employees;
}