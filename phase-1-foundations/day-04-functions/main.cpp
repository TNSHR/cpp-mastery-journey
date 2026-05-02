#include<iostream>
using namespace std;

void byValue(int x){
    x = 50;
}
void byReference(int& x){
    x = 100;
}
int main(){
    int a = 10;
    byValue(a);
    cout << "Value of a after byValue function:" << a << endl; 
    byReference(a);
    cout << "Value of a after byReference function:" << a << endl;

    //Task 1: int squre(int x)
    // int square(int x){
    //     return x * x;
    // }
    // //call the function and print the value
    // int num = 5;
    // cout << "Square of " << num << " is: " << square(num) << endl;
    return 0;
}