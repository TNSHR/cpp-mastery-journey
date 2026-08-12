#include <iostream>
#include <memory>

#include "Employee.h"
#include "EmployeeManager.h"

using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << " Modern C++ - std::unique_ptr" << endl;
    cout << "==========================================" << endl;

    /*
    -----------------------------------------
    Create Employee Manager
    -----------------------------------------
    */

    EmployeeManager manager;

    /*
    -----------------------------------------
    Create Employees
    -----------------------------------------
    */

    auto employee1 =
        make_unique<Employee>(
            101,
            "Shrinath",
            50000);

    auto employee2 =
        make_unique<Employee>(
            102,
            "Rahul",
            70000);

    auto employee3 =
        make_unique<Employee>(
            103,
            "Priya",
            60000);

    /*
    -----------------------------------------
    Transfer Ownership
    -----------------------------------------
    */

    manager.addEmployee(std::move(employee1));

    manager.addEmployee(std::move(employee2));

    manager.addEmployee(std::move(employee3));

    /*
    -----------------------------------------
    Check Ownership
    -----------------------------------------
    */

    if(employee1 == nullptr)
    {
        cout << "\nEmployee1 Ownership Transferred"
             << endl;
    }

    /*
    -----------------------------------------
    Display Employees
    -----------------------------------------
    */

    manager.displayEmployees();

    /*
    -----------------------------------------
    Search Employee
    -----------------------------------------
    */

    Employee* employee =
        manager.findEmployeeById(102);

    if(employee != nullptr)
    {
        cout << "\nEmployee Found\n"
             << endl;

        employee->display();
    }
    else
    {
        cout << "\nEmployee Not Found"
             << endl;
    }

    cout << "\nProgram Ending..."
         << endl;

    return 0;
}