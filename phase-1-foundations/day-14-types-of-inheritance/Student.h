#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{
    protected:
      int rollNumber;

    public:
      Student(string n, int a, int r);

      void display();
};

#endif