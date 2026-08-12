#include<iostream>
using namespace std;

class Student{

public:
    string name;
    int rollNo;
    int marks;

     void display(){
        cout << "Name:" << name << endl;
        cout << "Roll No:" << rollNo << endl;
        cout << "Marks:" << marks << endl;
    }

};

void displayStudent(const Student& s){
        cout << "Name:" << s.name << endl;
        cout << "Roll No:" << s.rollNo << endl;
        cout << "Marks:" << s.marks << endl;
    }

int main(){
    Student s1;
    s1.name = "John";
    s1.rollNo = 101;
    s1.marks = 85;

   

    s1.display();
    return 0;
}
