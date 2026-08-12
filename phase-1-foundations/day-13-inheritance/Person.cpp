#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(string n, int a){
    name = n;
    age = a;
}

void Person::displayPerson(){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}