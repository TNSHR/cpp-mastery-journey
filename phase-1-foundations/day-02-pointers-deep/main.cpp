#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int* p = &a;
    //Pointer to pointer
    int** pp = &p;

    cout << "Value of a:" << a << endl;
    cout << "Value of a using pointer p:" << *p << endl;
    cout << "Value of a using pointer to pointer pp:" << **pp << endl;

    //Modifying using pointer to pointer
    **pp = 50;
    cout << "Value of a after modification using pointer to pointer pp:" << a << endl;

    //Dynamic memory 
    int* dynamicMemory = new int(100);
    cout << "Value in dynamic memory:" << *dynamicMemory << endl;

    delete dynamicMemory; // Free the allocated memory
    dynamicMemory = nullptr; // Good practice to set pointer to nullptr after deletion
    //Null pointer
    int* nullPointer = nullptr;
    if(nullPointer == nullptr){
        cout << "Null pointer is indeed null." << endl;
    }
    return 0;
}