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
    Add Employee
    -----------------------------------------
    */

    void addEmployee(const Employee& employee);

    /*
    -----------------------------------------
    Display Methods
    -----------------------------------------
    */

    void displayUsingAuto() const;

    void displayUsingAutoReference();

    void displayUsingConstAutoReference() const;

    /*
    -----------------------------------------
    Getter
    -----------------------------------------
    */

    std::vector<Employee>& getEmployees();

    const std::vector<Employee>& getEmployees() const;
};

#endif