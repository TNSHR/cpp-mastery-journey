#include "EmployeeManager.h"
#include <iostream>

/*Add employee*/

void EmployeeManager::addEmployee(const Employee& employee){
    employees.push_back(employee);
}

/*Display employees*/

void EmployeeManager::displayEmployees() const{
    std::cout << "\n========Employee List:=======\n" << std::endl;
    for(const auto& employee : employees){
        employee.display();
        std::cout << "---------------"<<std::endl;
    }
}

/*return employees vector*/

std::vector<Employee>& EmployeeManager::getEmployees(){
    return employees;
}