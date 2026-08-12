#include "Employee.h"
#include <iostream>

/*Default Constructor*/
Employee::Employee()
{
    id = 0;
    name = "";
    salary = 0.0;
    std::cout << "Default constructor called "
    << std::endl;
}
/*Parameterized Constructor*/

Employee::Employee(int id, std::string name, double salary)
{
    this->id = id;
    this->name = name;
    this->salary = salary;
    std::cout << "Parameterized constructor called"
    << this->name << std::endl;
}

/*Setters Functions*/

void Employee::setId(int id)
{
    this->id = id;
}
void Employee::setName(const std::string& name){
    this->name = name;
}

void Employee::setSalary(double salary){
    this->salary = salary;
}

/*Getters Functions*/

int Employee::getId() const{
    return id;
}

std::string Employee::getName() const{
    return name;
}

double Employee::getSalary() const{
    return salary;
}

/*Display Function*/

void Employee::display() const{
    std::cout << "Employee ID:"<< id << std::endl;
    std::cout << "Employee name:"<< name << std::endl;
    std::cout << "Employee salary:"<< salary << std::endl;
}