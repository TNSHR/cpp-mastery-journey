#include<iostream>
#include "Employee.h"
#include "EmployeeManager.h"

using namespace std;

int main(){
    cout << "==================================="<<endl;
    cout << "Morden C++ - Auto Keyword Example"<<endl;
    cout << "==================================="<<endl;

    //Traditiona object creation
    Employee employee1(1,"John Doe", 50000);
    auto employee2 = Employee(102,"Rahul",600000);
    auto employee3 = Employee(103,"Priya", 70000);

    //Create Emloyee Manager
    EmployeeManager manager;

    manager.addEmployee(employee1);
    manager.addEmployee(employee2);
    manager.addEmployee(employee3);
    cout << "\nDisplaying Employees using Employee Manager\n"<<endl;
    manager.displayEmployees();
    
    cout << "\nDisplaying Employees using auto keyword\n"<<endl;
    cout << "==================" << endl;

    auto& employees = manager.getEmployees();

    for(auto& employee: employees){
        cout << employee.getName()
        << "earns"
        << employee.getSalary()
        << endl;
    }

     cout << "\n===============================" << endl;
    cout << "Using auto Iterator" << endl;
    cout << "===============================" << endl;

    for (auto it = employees.begin();
         it != employees.end();
         ++it)
    {
        cout << it->getId()
             << " "
             << it->getName()
             << endl;
    }

    cout << "\nProgram Finished Successfully."
         << endl;

    return 0;
}