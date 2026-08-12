#include <iostream>

#include "Employee.h"
#include "EmployeeManager.h"

using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << " Modern C++ - Range Based For Loops" << endl;
    cout << "==========================================" << endl;

    /*
    -----------------------------------------
    Create Employee Objects
    -----------------------------------------
    */

    Employee employee1(101, "Shrinath", 50000);

    Employee employee2(102, "Rahul", 60000);

    Employee employee3(103, "Priya", 70000);

    /*
    -----------------------------------------
    Create Employee Manager
    -----------------------------------------
    */

    EmployeeManager manager;

    manager.addEmployee(employee1);
    manager.addEmployee(employee2);
    manager.addEmployee(employee3);

    /*
    -----------------------------------------
    auto
    -----------------------------------------
    */

    manager.displayUsingAuto();

    /*
    -----------------------------------------
    auto&
    -----------------------------------------
    */

    manager.displayUsingAutoReference();

    /*
    -----------------------------------------
    const auto&
    -----------------------------------------
    */

    manager.displayUsingConstAutoReference();

    /*
    -----------------------------------------
    Direct Range Loop
    -----------------------------------------
    */

    cout << "\n==============================" << endl;
    cout << "Direct Loop in main()" << endl;
    cout << "==============================" << endl;

    const auto& employees = manager.getEmployees();

    for (const auto& employee : employees)
    {
        cout << employee.getId()
             << "  "
             << employee.getName()
             << "  "
             << employee.getSalary()
             << endl;
    }

    cout << "\nProgram Finished Successfully."
         << endl;

    return 0;
}