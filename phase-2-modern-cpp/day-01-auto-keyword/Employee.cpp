#include "Employee.h"
#include <iostream>

/* Default constructor*/

Employee::Employee(){
    id = 0;
    name = "";
    salary = 0.0;
};

/* Parameterized constructor */
Employee::Employee(int id, const std::string& name, double salary){
    this->id = id;
    this->name = name;
    this->salary = salary;
};

/* Setter methods */

void Employee::setId(int id){
    this->id = id;
};

void Employee::setName(const std::string& name){
    this->name = name;
};

void Employee::setSalary(double salary){
    this->salary = salary;
};

/* Getter methods */

int Employee::getId() const{
    return id;
};

std::string Employee::getName() const{
    return name;
};
double Employee::getSalary() const{
    return salary;
}

/*Display method*/

void Employee::display() const{
    std::cout << "Employee ID:"
              << id
              << std::endl;
    std::cout << "Employee Name:"
              << name
              << std::endl;
    std::cout << "Employee Salary:"
              << salary
              << std::endl;
};