#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
private:

    int id;
    std::string name;
    double salary;

public:

    /*
    -----------------------------------------
    Constructors
    -----------------------------------------
    */

    Employee();

    Employee(
        int id,
        const std::string& name,
        double salary
    );

    /*
    -----------------------------------------
    Destructor
    -----------------------------------------
    */

    ~Employee();

    /*
    -----------------------------------------
    Setter Functions
    -----------------------------------------
    */

    void setId(int id);

    void setName(const std::string& name);

    void setSalary(double salary);

    /*
    -----------------------------------------
    Getter Functions
    -----------------------------------------
    */

    int getId() const;

    std::string getName() const;

    double getSalary() const;

    /*
    -----------------------------------------
    Display Function
    -----------------------------------------
    */

    void display() const;
};

#endif