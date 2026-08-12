#include "EmployeeManager.h"

#include <iostream>

/*
-----------------------------------------
Constructor
-----------------------------------------
*/

EmployeeManager::EmployeeManager()
{
    std::cout
        << "Employee Manager Created"
        << std::endl;
}

/*
-----------------------------------------
Destructor
-----------------------------------------
*/

EmployeeManager::~EmployeeManager()
{
    std::cout
        << "Employee Manager Destroyed"
        << std::endl;
}

/*
-----------------------------------------
Add Employee
-----------------------------------------
*/

void EmployeeManager::addEmployee(
    std::unique_ptr<Employee> employee)
{
    employees.push_back(std::move(employee));

    std::cout
        << "Employee Added Successfully"
        << std::endl;
}

/*
-----------------------------------------
Display Employees
-----------------------------------------
*/

void EmployeeManager::displayEmployees() const
{
    std::cout
        << "\n========== Employee List ==========\n";

    for(const auto& employee : employees)
    {
        employee->display();

        std::cout
            << "------------------------"
            << std::endl;
    }
}

/*
-----------------------------------------
Find Employee
-----------------------------------------
*/

Employee* EmployeeManager::findEmployeeById(
    int id) const
{
    for(const auto& employee : employees)
    {
        if(employee->getId() == id)
        {
            return employee.get();
        }
    }

    return nullptr;
}

/*
-----------------------------------------
Getter
-----------------------------------------
*/

const std::vector<std::unique_ptr<Employee>>&
EmployeeManager::getEmployees() const
{
    return employees;
}