#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
    private:
      int id;
      std::string name;
      double marks;
    public:
      Student();
      Student(int id, const std::string& name, double marks);
      void setId(int id);
      void setName(const std::string& name);
      void setMarks(double marks);
      int getId() const;
      std::string getName() const;
      double getMarks() const;

};
#endif