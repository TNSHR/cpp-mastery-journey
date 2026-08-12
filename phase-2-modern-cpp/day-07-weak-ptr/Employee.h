#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee{

    private:
         int id;
         std::string name;
         double salary;
    public:
        //default constructor
        Employee();
        //parameterized constructor
        Employee(int id, std::string name, double salary);
        //destructor
        ~Employee();
        //setters
        void setId(int id);
        void setName(std::string name);
        void setSalary(double salary);

        //getters 
        int getId() const;
        std::string getName() const;
        double getSalary() const;

        //display employee details
        void display() const;


};

#endif