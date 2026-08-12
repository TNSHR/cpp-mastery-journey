#include "Employee.h"
#include <iostream>

//Default constructor
Employee::Employee(): id(0), name(""), salary(0.0){
    std::cout << "Default constructor called " << std::endl;
}

//Parameterized constructor
Employee::Employee(int id, const std::string name, double salary):id(id),name(name),salary(salary){
    std::cout << "Employee Created:" << name << std::endl;

}

//Destructor
Employee::~Employee(){
    std::cout << "Employee Destroyed:" << name << std::endl;
}

//Setters
void Employee::setId(int id){
    this-> id = id;

};

void Employee::setName(const std::string& name){
    this->name = name;
};

void Employee::setSalary(double salary){
    this->salary = salary;
}

//Getters
int Employee::getId() const{
    return id;
}   
std::string Employee::getName() const{
    return name;
}
double Employee::getSalary() const{
    return salary;
}

//Display employee details
void Employee::display() const{
    std::cout << "Employee ID: " << id << std::endl;                    
    std::cout << "Employee Name: " << name << std::endl;
    std::cout << "Employee Salary: " << salary << std::endl;
}