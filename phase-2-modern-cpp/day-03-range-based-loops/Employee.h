#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee{
    private:
        std::string name;
        int id;
        double salary;
    public:
        Employee();
        Employee(int id,std::string name, double salary);

    /*Setters Functions*/
    void setId(int id);
    void setName(const std::string& name);
    void setSalary(double salary);

    /*Getters Functions*/
    int getId() const;
    std::string getName() const;
    double getSalary() const;

    /*Display Function*/
    void display() const;


};
#endif