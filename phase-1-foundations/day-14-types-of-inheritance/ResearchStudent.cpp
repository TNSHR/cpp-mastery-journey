#include <iostream>
#include "ResearchStudent.h"

using namespace std;

ResearchStudent :: ResearchStudent(string n, int a, int r,string t): Student(n,a,r){
    topic = t;
};

void ResearchStudent :: display(){
    Student::display();

    cout << "Research Topic : " << topic << endl;
};