#include "EmployeeManager.h"

#include <iostream>

// -----------------------------------------
// Constructor
// -----------------------------------------

EmployeeManager::EmployeeManager()
{
    std::cout
        << "Employee Manager Created"
        << std::endl;
}

// -----------------------------------------
// Destructor
// -----------------------------------------

EmployeeManager::~EmployeeManager()
{
    std::cout
        << "Employee Manager Destroyed"
        << std::endl;
}

// -----------------------------------------
// Add Employee
// -----------------------------------------

void EmployeeManager::addEmployee(
    std::shared_ptr<Employee> employee)
{
    employees.push_back(employee);

    std::cout
        << "Employee Added Successfully"
        << std::endl;

    std::cout
        << "Current use_count: "
        << employee.use_count()
        << std::endl;
}

// -----------------------------------------
// Display Employees
// -----------------------------------------

void EmployeeManager::displayEmployees() const
{
    std::cout
        << "\n========== Employee List ==========\n";

    for(const auto& employee : employees)
    {
        employee->display();

        std::cout
            << "use_count: "
            << employee.use_count()
            << std::endl;

        std::cout
            << "------------------------"
            << std::endl;
    }
}

// -----------------------------------------
// Find Employee
// -----------------------------------------

std::shared_ptr<Employee>
EmployeeManager::findEmployeeById(int id) const
{
    for(const auto& employee : employees)
    {
        if(employee->getId() == id)
        {
            return employee;
        }
    }

    return nullptr;
}

// -----------------------------------------
// Get Employees
// -----------------------------------------

const std::vector<std::shared_ptr<Employee>>&
EmployeeManager::getEmployees() const
{
    return employees;
}