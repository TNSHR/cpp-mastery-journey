#include "Student.h"

/*  
Default constructor
*/
Student::Student()
{
    id = 0;
    name = "";
    marks = 0.0;
}

/* 
Parameterized Constructor     
*/

Student::Student(int id, const std::string& name, double marks){
    this->id=id;
    this->name = name;
    this->marks = marks;
}

/* Setter Function*/

void Student::setId(int id){
    this->id = id;
}

void Student::setName(const std::string& name){
    this->name = name;

}
 void Student::setMarks(double marks){
    this->marks = marks;
 }

 /* Getter Function*/
 int Student::getId() const
 {
    return id;
 }
 std::string Student::getName() const
 {
    return name;
 }

 double Student::getMarks() const
 {
    return marks;
 }