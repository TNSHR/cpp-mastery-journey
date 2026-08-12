#include <iostream>

#include "Employee.h"
#include "EmployeeManager.h"

using namespace std;

int main()
{
    cout << "============================================" << endl;
    cout << " Modern C++ - Lambda Expressions" << endl;
    cout << "============================================" << endl;

    /*
    -----------------------------------------
    Create Employees
    -----------------------------------------
    */

    Employee employee1(101, "Shrinath", 50000);

    Employee employee2(102, "Rahul", 70000);

    Employee employee3(103, "Priya", 60000);

    Employee employee4(104, "Amit", 80000);

    /*
    -----------------------------------------
    Create Manager
    -----------------------------------------
    */

    EmployeeManager manager;

    manager.addEmployee(employee1);
    manager.addEmployee(employee2);
    manager.addEmployee(employee3);
    manager.addEmployee(employee4);

    /*
    -----------------------------------------
    Display All Employees
    -----------------------------------------
    */

    manager.displayEmployees();

    /*
    -----------------------------------------
    STL for_each()
    -----------------------------------------
    */

    manager.displayUsingForEach();

    /*
    -----------------------------------------
    STL find_if()
    -----------------------------------------
    */

    manager.findHighSalaryEmployee(65000);

    /*
    -----------------------------------------
    STL count_if()
    -----------------------------------------
    */

    manager.countHighSalaryEmployees(55000);

    /*
    -----------------------------------------
    STL sort()
    -----------------------------------------
    */

    manager.sortEmployeesBySalary();

    /*
    -----------------------------------------
    Display Sorted Employees
    -----------------------------------------
    */

    manager.displayEmployees();

    cout << "\nProgram Finished Successfully."
         << endl;

    return 0;
}