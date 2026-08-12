#include<iostream>
#include "Person.h"

using namespace std;

Person::Person(string n, int a)
{
    name = n;
    age = a;

    cout << "Person constructor called \n";
};

Person::~Person(){
    cout << "Person destructor called \n";
};

void Person::display(){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;


};