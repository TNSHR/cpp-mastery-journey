#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>

class Employee{
    private:
        int id;
        std::string name;
        double salary;
    public:
        Employee();
        Employee(int id, std::string name, double salary);
        void setId(int id);
        int getId() const;
        void setName(std::string name);
        void setSalary(double salary);
        std::string getName() const;
        double getSalary() const;
        void displayEmployee() const;
};

#endif