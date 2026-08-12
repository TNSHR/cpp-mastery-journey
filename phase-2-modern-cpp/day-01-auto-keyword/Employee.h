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
       Employee(int id, const std::string& name, double salary);

    void setId(int id);
    void setName(const std::string& name);
    void setSalary(double salary);
    int getId() const;
    std::string getName() const;
    double getSalary() const;
    void display() const;
};

#endif // EMPLOYEE_H