#include<iostream>
using namespace std;

void update(int& x){
    x = x + 10;
}
int main(){
    int a = 20;
    cout << "Value of a before update:" << a << endl;
    update(a);
    cout << "Value of a after update:" << a << endl;

    //Task 1: Create a reference variable for a and print its value
    int a = 10;
    int& r = a;
    r = 20;
    //Now what is the value of a?
    cout << "Value of a after modifying reference r:" << a << endl;

    //Task 2: call function and print value
    void change(int& x){
        x = 200;
    }
    //call the function and print the value
    change(a);
    cout << "Value of a after calling change function:" << a << endl;
    //Task 3
    int a = 50;
    int& r = a;
    int& r2 = r; // Reference to reference
    r2 = 100; // Modifying through r2 will modify a
    cout << "Value of a after modifying through r2:" << a << endl;
    //Task 4
    //int& r; // This will cause a compilation error because reference must be initialized

    return 0;

}