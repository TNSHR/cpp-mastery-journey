#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <memory>
#include <vector>

#include "Employee.h"

class EmployeeManager
{
private:

    /*
    -----------------------------------------
    Modern C++ Container
    -----------------------------------------
    */

    std::vector<std::unique_ptr<Employee>> employees;

public:

    /*
    -----------------------------------------
    Constructor
    -----------------------------------------
    */

    EmployeeManager();

    /*
    -----------------------------------------
    Destructor
    -----------------------------------------
    */

    ~EmployeeManager();

    /*
    -----------------------------------------
    Employee Operations
    -----------------------------------------
    */

    void addEmployee(std::unique_ptr<Employee> employee);

    /*
    -----------------------------------------
    Display
    -----------------------------------------
    */

    void displayEmployees() const;

    /*
    -----------------------------------------
    Search
    -----------------------------------------
    */

    Employee* findEmployeeById(int id) const;

    /*
    -----------------------------------------
    Getter
    -----------------------------------------
    */

    const std::vector<std::unique_ptr<Employee>>&
    getEmployees() const;
};

#endif