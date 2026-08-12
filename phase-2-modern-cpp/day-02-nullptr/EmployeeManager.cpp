#include "EmployeeManager.h"
#include <iostream>

/*Constructor*/

EmployeeManager::EmployeeManager(){
    std::cout << "Employee Manager created" << std::endl;
};

/*Destructor*/
EmployeeManager::~EmployeeManager(){
    std::cout << "\nCleaning up Heap Memory ..." << std::endl;
    for(auto employee:employees){
        delete employee;
        employee = nullptr;
    }
    employees.clear();
    std::cout << "All Employee objects deleted from Heap Memory" << std::endl;
    std::cout << "Employee Manager destroyed" << std::endl;
}

/*Add Employee*/

void EmployeeManager::addEmployee(Employee* employee){
    if(employee == nullptr){
        std::cout
        << "Error: Cannot add a null employee to the manager."
        << std::endl;
        return;
    }
    employees.push_back(employee);
};

/*Display Employees*/

void EmployeeManager::displayEmployees() const{
    std::cout << "Displaying Employees: " << std::endl;
    for(auto employee: employees){
        if(employee != nullptr){
            employee->displayEmployee();
            std::cout << "------------------------" << std::endl;
        } else {
            std::cout << "Error: Null employee pointer encountered." << std::endl;
        }
    }
};

/*Return Employees*/

std::vector<Employee*>& EmployeeManager::getEmployees(){
    return employees;
}