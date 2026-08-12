#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee {
    private:
        int id;
        std::string name;
        double salary;
    public:
       //Default constructor
       Employee();
       //Parameterized constructor
       Employee(int id, std::string name, double salary);
       //Destructor
       ~Employee();
       
       //Setters
       void setId(int id);
       void setName(std::string& name);
       void setSalary(double salary);

       //Getters
       int getId() const;
       std::string getName() const;
       double getSalary() const;

       //Display employee details

       void display() const;

};

#endif