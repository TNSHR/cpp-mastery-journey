#include<iostream>

using namespace std;

class Student
{
public:

    string name;

    int marks;

    Student()
    {
        cout<<"Constructor Called"<<endl;
    }

    ~Student()
    {
        cout<<"Destructor Called"<<endl;
    }
};

int main()
{
    Student s1;

    cout<<"Program Running"<<endl;

    return 0;
}