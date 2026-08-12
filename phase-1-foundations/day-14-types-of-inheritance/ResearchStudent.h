#ifndef RESEARCHSTUDENT_H
#define RESEARCHSTUDENT_H

#include "Student.h"

class ResearchStudent : public Student
{
    private:
       string topic;
    public:
      ResearchStudent(string n, int a, int r, string t);
      
      void display();
};

#endif