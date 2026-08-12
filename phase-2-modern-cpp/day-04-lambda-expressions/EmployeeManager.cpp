#include "EmployeeManager.h"

#include <iostream>
#include <algorithm>

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
Display Employees
-----------------------------------------
*/

void EmployeeManager::displayEmployees() const
{
    std::cout << "\n========== Employee List ==========\n";

    for(const auto& employee : employees)
    {
        employee.display();
        std::cout << "--------------------------\n";
    }
}

/*
-----------------------------------------
std::for_each + Lambda
-----------------------------------------
*/

void EmployeeManager::displayUsingForEach() const
{
    std::cout << "\n========== Using std::for_each ==========\n";

    std::for_each(

        employees.begin(),

        employees.end(),

        [](const Employee& employee)
        {
            employee.display();

            std::cout
            << "--------------------------"
            << std::endl;
        }

    );
}

/*
-----------------------------------------
std::find_if + Lambda
-----------------------------------------
*/

void EmployeeManager::findHighSalaryEmployee(
double salary) const
{
    auto iterator = std::find_if(

        employees.begin(),

        employees.end(),

        [salary](const Employee& employee)
        {
            return employee.getSalary() > salary;
        }

    );

    if(iterator != employees.end())
    {
        std::cout
        << "\nEmployee Found\n";

        iterator->display();
    }
    else
    {
        std::cout
        << "\nNo Employee Found\n";
    }
}

/*
-----------------------------------------
std::count_if + Lambda
-----------------------------------------
*/

void EmployeeManager::countHighSalaryEmployees(
double salary) const
{
    int count = std::count_if(

        employees.begin(),

        employees.end(),

        [salary](const Employee& employee)
        {
            return employee.getSalary() > salary;
        }

    );

    std::cout
    << "\nEmployees with salary greater than "
    << salary
    << " = "
    << count
    << std::endl;
}

/*
-----------------------------------------
std::sort + Lambda
-----------------------------------------
*/

void EmployeeManager::sortEmployeesBySalary()
{
    std::sort(

        employees.begin(),

        employees.end(),

        [](const Employee& first,
           const Employee& second)
        {
            return first.getSalary()
                 < second.getSalary();
        }

    );

    std::cout
    << "\nEmployees Sorted Successfully.\n";
}

/*
-----------------------------------------
Getter
-----------------------------------------
*/

const std::vector<Employee>&
EmployeeManager::getEmployees() const
{
    return employees;
}