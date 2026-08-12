#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include <vector>

class EmployeeManager{
    private:
        std::vector<Employee> employees;
    public:
        void addEmployee(const Employee& employee);
        void displayEmployees() const;
        std::vector<Employee>& getEmployees();
};

#endif // EMPLOYEEMANAGER_H