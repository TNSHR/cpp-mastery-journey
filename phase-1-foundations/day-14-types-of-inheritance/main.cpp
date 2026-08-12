#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "ResearchStudent.h"

using namespace std;

int main(){
    Student s("Shrinath", 30,101);
    Teacher t("Amit", 40, 75000);
    ResearchStudent rs("Rahul", 24, 501,"Artificial intelligence");

    cout << "\n-----Student------\n";
    s.display();

    cout << "\n-----Teacher-----\n";
    t.display();

    cout << "\n-----Research Student------\n";
    rs.display();
    return 0;
};