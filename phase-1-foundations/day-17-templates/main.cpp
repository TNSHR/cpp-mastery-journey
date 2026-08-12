#include <iostream>

#include "Calculator.h"

#include "Pair.h"

using namespace std;

int main()
{
    cout<<"===== Function Templates ====="<<endl;

    cout<<add(10,20)<<endl;

    cout<<add(5.5,7.5)<<endl;

    cout<<multiply(10,5)<<endl;

    cout<<endl;

    cout<<"===== Class Templates ====="<<endl;

    Pair<int,string> student(101,"Shrinath");

    student.display();

    cout<<endl;

    Pair<double,char> result(95.75,'A');

    result.display();

    return 0;
}