#include "Employee.h"
#include <iostream>

Employee::Employee()
{
    id = 0;
    name = "";
    salary = 0.0;
    std::cout << "Default Constructor called for Employee" << std::endl;
};

Employee::Employee(int id, std::string name, double salary)
{
    this->id = id;
    this->name = name;
    this->salary = salary;
    std::cout << "Parameterized Constructor called for Employee" << std::endl;
};

/*Getters*/

int Employee::getId() const
{
    return id;

}

std::string Employee::getName() const
{
    return name;
};

double Employee::getSalary() const
{
    return salary;
}

/*Setters*/
void Employee::setId(int id){
    this->id = id;
};
void Employee::setName(std::string name){
    this->name = name;
};

void Employee::setSalary(double salary){
    this->salary = salary;
}

/*Display*/
void Employee::display() const{
    std::cout << "Employee ID: " << id << std::endl;
    std::cout << "Employee Name: " << name << std::endl;
    std::cout << "Employee Salary: " << salary << std::endl;
};  