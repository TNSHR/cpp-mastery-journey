#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string name;
    double salary;

public:

    // Setter for Name
    void setName(string n)
    {
        name = n;
    }

    // Setter for Salary
    void setSalary(double s)
    {
        if (s >= 0)
        {
            salary = s;
        }
        else
        {
            cout << "Invalid Salary! Salary cannot be negative." << endl;
        }
    }

    // Getter for Name
    string getName()
    {
        return name;
    }

    // Getter for Salary
    double getSalary()
    {
        return salary;
    }

    // Display Function
    void display()
    {
        cout << "Employee Details" << endl;
        cout << "----------------" << endl;
        cout << "Name   : " << name << endl;
        cout << "Salary : " << salary << endl;
    }
};

int main()
{
    Employee emp;

    emp.setName("Shrinath Sharma");

    emp.setSalary(60000);

    emp.display();

    cout << endl;

    cout << "Testing Getter Functions" << endl;
    cout << "Name   : " << emp.getName() << endl;
    cout << "Salary : " << emp.getSalary() << endl;

    cout << endl;

    cout << "Testing Validation" << endl;

    emp.setSalary(-5000);

    return 0;
}