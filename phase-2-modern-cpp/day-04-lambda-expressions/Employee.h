#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {

    private:
        int id;
        std::string name;
        double salary;
    public:
        Employee();
        Employee(int id, std::string name, double salary);


/*Getters*/
    int getId() const;
    std::string getName() const;
    double getSalary() const;


    /*Setters*/
    void setId(int id);
    void setName(std::string name);
    void setSalary(double salary);

    /*Display*/
    void display() const;

};

#endif
