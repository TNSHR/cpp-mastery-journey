#include <iostream>
#include <memory>

#include "Employee.h"
#include "EmployeeManager.h"

int main()
{
    std::cout
        << "==========================================" << std::endl;

    std::cout
        << " Modern C++ - std::shared_ptr" << std::endl;

    std::cout
        << "==========================================" << std::endl;


    // -----------------------------------------
    // Create Employee Manager
    // -----------------------------------------

    EmployeeManager manager;


    // -----------------------------------------
    // Create Employee using make_shared()
    // -----------------------------------------

    auto employee1 =
        std::make_shared<Employee>(
            101,
            "Shrinath",
            50000
        );


    std::cout
        << "\nAfter employee1 creation:"
        << std::endl;

    std::cout
        << "use_count = "
        << employee1.use_count()
        << std::endl;


    // -----------------------------------------
    // Create another shared_ptr
    // -----------------------------------------

    auto employee2 = employee1;


    std::cout
        << "\nAfter employee2 = employee1:"
        << std::endl;

    std::cout
        << "employee1 use_count = "
        << employee1.use_count()
        << std::endl;

    std::cout
        << "employee2 use_count = "
        << employee2.use_count()
        << std::endl;


    // -----------------------------------------
    // Add Employee to Manager
    // -----------------------------------------

    manager.addEmployee(employee1);


    std::cout
        << "\nAfter adding employee1 to manager:"
        << std::endl;

    std::cout
        << "employee1 use_count = "
        << employee1.use_count()
        << std::endl;


    // -----------------------------------------
    // Display Employees
    // -----------------------------------------

    manager.displayEmployees();


    // -----------------------------------------
    // Reset employee2
    // -----------------------------------------

    employee2.reset();


    std::cout
        << "\nAfter employee2.reset():"
        << std::endl;

    std::cout
        << "employee1 use_count = "
        << employee1.use_count()
        << std::endl;


    // -----------------------------------------
    // Find Employee
    // -----------------------------------------

    auto foundEmployee =
        manager.findEmployeeById(101);


    std::cout
        << "\nAfter findEmployeeById():"
        << std::endl;

    std::cout
        << "employee1 use_count = "
        << employee1.use_count()
        << std::endl;

    std::cout
        << "foundEmployee use_count = "
        << foundEmployee.use_count()
        << std::endl;


    // -----------------------------------------
    // Display Found Employee
    // -----------------------------------------

    if(foundEmployee)
    {
        std::cout
            << "\nEmployee Found"
            << std::endl;

        foundEmployee->display();
    }
    else
    {
        std::cout
            << "\nEmployee Not Found"
            << std::endl;
    }


    // -----------------------------------------
    // Reset foundEmployee
    // -----------------------------------------

    foundEmployee.reset();


    std::cout
        << "\nAfter foundEmployee.reset():"
        << std::endl;

    std::cout
        << "employee1 use_count = "
        << employee1.use_count()
        << std::endl;


    // -----------------------------------------
    // Display Employees Again
    // -----------------------------------------

    manager.displayEmployees();


    std::cout
        << "\nProgram Ending..."
        << std::endl;


    return 0;
}