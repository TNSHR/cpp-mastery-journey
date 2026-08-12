#include <iostream>
#include "Teacher.h"

using namespace std;

Teacher :: Teacher(string n, int a, double s) : Person(n,a)
{
    salary = s;
};

void Teacher::display()
{
    Person::display();
    cout << "Salary: " << salary << endl;
};