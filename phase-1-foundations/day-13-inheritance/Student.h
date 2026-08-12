#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{
private:
    int rollNumber;

public:
    Student(string n, int a, int r);

    void displayStudent();
};

#endif