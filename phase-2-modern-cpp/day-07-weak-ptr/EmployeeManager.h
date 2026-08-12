#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <memory>
#include <vector>

#include "Employee.h"

class EmployeeManager
{
private:

    // EmployeeManager owns the Employees
    std::vector<std::shared_ptr<Employee>> employees;

public:

    // Constructor
    EmployeeManager();

    // Destructor
    ~EmployeeManager();

    // Add Employee
    void addEmployee(
        std::shared_ptr<Employee> employee
    );

    // Display all Employees
    void displayEmployees() const;

    // Find Employee
    std::shared_ptr<Employee>
    findEmployeeById(int id) const;

    // Get Employees
    const std::vector<std::shared_ptr<Employee>>&
    getEmployees() const;
};

#endif