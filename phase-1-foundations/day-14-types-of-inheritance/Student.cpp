#include<iostream>
#include "Student.h"

using namespace std;

Student::Student(string n, int a, int r): Person(n,a){
    rollNumber = r;
    cout << "Student Constructor\n";
};

void Student::display(){
    Person::display();
    cout << "Roll Number :" << rollNumber << endl;
};