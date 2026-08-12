#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(string n, int a, int r) : Person(n, a) {
    rollNumber = r;
}

void Student::displayStudent() {
    displayPerson();
    cout << "Roll Number: " << rollNumber << endl;
}