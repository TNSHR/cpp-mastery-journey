#include "Employee.h"
#include <iostream>

//Default constructor

Employee::Employee():id(0), name(""), salary(0.0){
    std::cout << "Employee Default Constructor called" << std::endl;
}
//Parameterized constructor
Employee::Employee(int id, std::string name, double salary): id(id), name(name), salary(salary){
    std::cout << "Employee Parameterized constructor called" << this->name << std::endl;
}

//Destructor
Employee::~Employee(){
    std::cout << "Employee Destructor called for " << name << std::endl;
};

//Setters
void Employee::setId(int id){
    this->id = id;
};

void Employee::setName(std::string name){
    this->name = name;
};

void Employee::setSalary(double salary){
    this->salary = salary;
};

//getters

int Employee::getId() const{
    return id;
};

std::string Employee::getName() const
{
    return name;
};

double Employee::getSalary() const
{
    return salary;
};

//Display

void Employee::display() const
{
    std::cout << "ID" << id << std::endl;
    std::cout << "Name" << name << std::endl;
    std::cout << "Salary" << salary << std:: endl;
};