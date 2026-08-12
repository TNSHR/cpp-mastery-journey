#include <iostream>
#include <memory>

#include "Employee.h"
#include "EmployeeManager.h"

int main()
{
    std::cout
        << "==========================================" << std::endl;

    std::cout
        << " Modern C++ - std::weak_ptr" << std::endl;

    std::cout
        << "==========================================" << std::endl;


    // -----------------------------------------
    // Create Employee Manager
    // -----------------------------------------

    EmployeeManager manager;


    // -----------------------------------------
    // Create Employee
    // -----------------------------------------

    auto employee =
        std::make_shared<Employee>(
            101,
            "Shrinath",
            50000
        );

    std::cout
        << "\nAfter Employee creation:"
        << std::endl;

    std::cout
        << "use_count = "
        << employee.use_count()
        << std::endl;


    // -----------------------------------------
    // Add Employee to Manager
    // -----------------------------------------

    manager.addEmployee(employee);

    std::cout
        << "\nAfter adding Employee to Manager:"
        << std::endl;

    std::cout
        << "use_count = "
        << employee.use_count()
        << std::endl;


    // -----------------------------------------
    // Create weak_ptr observer
    // -----------------------------------------

    std::weak_ptr<Employee> observer = employee;

    std::cout
        << "\nAfter creating weak_ptr:"
        << std::endl;

    std::cout
        << "use_count = "
        << employee.use_count()
        << std::endl;


    // -----------------------------------------
    // Check whether weak_ptr is expired
    // -----------------------------------------

    if(observer.expired())
    {
        std::cout
            << "Observer: Employee no longer exists"
            << std::endl;
    }
    else
    {
        std::cout
            << "Observer: Employee is still alive"
            << std::endl;
    }


    // -----------------------------------------
    // Access Employee using lock()
    // -----------------------------------------

    if(auto lockedEmployee = observer.lock())
    {
        std::cout
            << "\nEmployee accessed through weak_ptr:"
            << std::endl;

        lockedEmployee->display();

        std::cout
            << "use_count while locked = "
            << lockedEmployee.use_count()
            << std::endl;
    }
    else
    {
        std::cout
            << "\nEmployee is no longer available"
            << std::endl;
    }


    // -----------------------------------------
    // Find Employee through Manager
    // -----------------------------------------

    auto foundEmployee =
        manager.findEmployeeById(101);

    std::cout
        << "\nAfter findEmployeeById():"
        << std::endl;

    std::cout
        << "use_count = "
        << employee.use_count()
        << std::endl;


    // -----------------------------------------
    // Release foundEmployee
    // -----------------------------------------

    foundEmployee.reset();

    std::cout
        << "\nAfter foundEmployee.reset():"
        << std::endl;

    std::cout
        << "use_count = "
        << employee.use_count()
        << std::endl;


    // -----------------------------------------
    // Release original Employee owner
    // -----------------------------------------

    employee.reset();

    std::cout
        << "\nAfter employee.reset():"
        << std::endl;


    // -----------------------------------------
    // Check weak_ptr after owner disappears
    // -----------------------------------------

    if(observer.expired())
    {
        std::cout
            << "Observer: Employee no longer exists"
            << std::endl;
    }
    else
    {
        std::cout
            << "Observer: Employee is still alive"
            << std::endl;
    }


    // -----------------------------------------
    // Try lock() again
    // -----------------------------------------

    if(auto lockedEmployee = observer.lock())
    {
        std::cout
            << "\nEmployee is still available:"
            << std::endl;

        lockedEmployee->display();
    }
    else
    {
        std::cout
            << "\nlock() failed: Employee was destroyed"
            << std::endl;
    }


    // -----------------------------------------
    // Program Ending
    // -----------------------------------------

    std::cout
        << "\nProgram Ending..."
        << std::endl;


    return 0;
}