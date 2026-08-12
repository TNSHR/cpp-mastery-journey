#include <iostream>

#include "Employee.h"
#include "EmployeeManager.h"

using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << " Modern C++ - nullptr Demonstration" << endl;
    cout << "==========================================" << endl;

    /*
    -----------------------------------------
    Create Employee Pointers
    -----------------------------------------
    */

    Employee* employee1 = nullptr;
    Employee* employee2 = nullptr;
    Employee* employee3 = nullptr;

    cout << "\nPointers Initialized Successfully.\n";

    /*
    -----------------------------------------
    Allocate Heap Memory
    -----------------------------------------
    */

    employee1 = new Employee(101, "Shrinath", 50000);

    employee2 = new Employee(102, "Rahul", 60000);

    employee3 = new Employee(103, "Priya", 70000);

    /*
    -----------------------------------------
    Create Manager
    -----------------------------------------
    */

    EmployeeManager manager;

    manager.addEmployee(employee1);
    manager.addEmployee(employee2);
    manager.addEmployee(employee3);

    /*
    -----------------------------------------
    Display Employees
    -----------------------------------------
    */

    manager.displayEmployees();

    /*
    -----------------------------------------
    nullptr Safety Check
    -----------------------------------------
    */

    Employee* employee4 = nullptr;

    manager.addEmployee(employee4);

    /*
    -----------------------------------------
    Display Using Pointer Vector
    -----------------------------------------
    */

    cout << "\n==============================" << endl;
    cout << "Using Raw Pointer Vector" << endl;
    cout << "==============================" << endl;

    auto& employees = manager.getEmployees();

    for (const auto employee : employees)
    {
        if (employee != nullptr)
        {
            cout << employee->getId()
                 << " "
                 << employee->getName()
                 << endl;
        }
    }

    cout << "\nEnd of main()" << endl;

    return 0;
}