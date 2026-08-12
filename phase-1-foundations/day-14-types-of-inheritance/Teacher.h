#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"

class Teacher : public Person
{
    private:
       double salary;
    public:
        Teacher(string n, int a, double s);

        void display();
};

#endif