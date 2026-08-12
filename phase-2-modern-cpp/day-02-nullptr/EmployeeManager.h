#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H
#include "Employee.h"
#include <vector>

class EmployeeManager{
    private:
        std::vector<Employee*> employees;
    public:
        EmployeeManager();
        ~EmployeeManager();
        void addEmployee(Employee* employee);

        void displayEmployees() const;

        std::vector<Employee*>& getEmployees();
};
#endif // EMPLOYEEMANAGER_H