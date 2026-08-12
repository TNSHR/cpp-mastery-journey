#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <vector>

#include "Employee.h"

class EmployeeManager
{
private:

    std::vector<Employee> employees;

public:

    /*
    -----------------------------------------
    Constructor
    -----------------------------------------
    */

    EmployeeManager();

    /*
    -----------------------------------------
    Employee Operations
    -----------------------------------------
    */

    void addEmployee(const Employee& employee);

    /*
    -----------------------------------------
    Display Functions
    -----------------------------------------
    */

    void displayEmployees() const;

    /*
    -----------------------------------------
    Lambda + STL Algorithms
    -----------------------------------------
    */

    void displayUsingForEach() const;

    void findHighSalaryEmployee(double salary) const;

    void countHighSalaryEmployees(double salary) const;

    void sortEmployeesBySalary();

    /*
    -----------------------------------------
    Getter
    -----------------------------------------
    */

    const std::vector<Employee>& getEmployees() const;
};

#endif