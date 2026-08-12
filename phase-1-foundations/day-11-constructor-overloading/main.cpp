#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int marks;

public:

    Student()
    {
        name = "Unknown";
        marks = 0;
    }

    Student(string n)
    {
        name = n;
        marks = 0;
    }

    Student(string n,int m)
    {
        name = n;
        marks = m;
    }

    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << endl;
    }
};

int main()
{
    Student s1;

    Student s2("Shrinath");

    Student s3("Rahul",95);

    s1.display();

    s2.display();

    s3.display();
}


//copy constructor
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int marks;

public:

    Student(string n,int m)
    {
        name = n;
        marks = m;
    }

    Student(const Student& other)
    {
        name = other.name;
        marks = other.marks;

        cout << "Copy Constructor Called" << endl;
    }

    void display()
    {
        cout << name << " " << marks << endl;
    }
};

int main()
{
    Student s1("Shrinath",98);

    Student s2(s1);

    s2.display();
}