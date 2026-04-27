#include<iostream>
using namespace std;

int main(){
    //Step 1: Create a variable
    int a = 10;
    cout << "1. Value of a:" << a << endl;
    //Step 2: Print address of a
    cout << "2. Address of a:" << &a << endl;
    //Step 3 : Create a pointer
    int* p = &a;
    cout << "3. Pointer p (stores address):" << p << endl;
    //Step 4: Dereference the pointer
    cout << "4. Value at address stored in P" << *p << endl;
    //Step 5: Change value using pointer
    *p = 20;
    cout << "5. New value of a after *p=20:" << a << endl;
    //Step 6: Anonther ponter
    int* q = p;
    *q = 100;
    cout << "6. Value of a after *q=100:" << a << endl;

    //Task 1 write program int x = 25 for value, address, and using pointer
    int x = 25;
    cout << "7.Value of x:" << x << endl;
    cout << "8.Address of x:" << &x << endl;
    int* ptr = &x;
    cout << "9.Pointer ptr (stores address of x):" << ptr << endl;
    cout << "10.Value at address stored into ptr:" << *ptr << endl;


    //Task 2:  int a = 10; int* p = &a; *p =99; now print a;
    int a1 = 10;
    int* p1 = &a1;
    *p1 =99;
    cout << "11.Value of a1 after *p1=99:" << a1 << endl;

    //Task 3: int a = 5; int* p = &a; *p = *p + 10; now print output;
    int a2 = 5;
    int* p2 = &a2;
    *p2 = *p2 + 10;
    cout << "12. Value of a2 after *p2 = *p2 + 10:" << a2 << endl;

    //Task 4: int a = 10; int* p = &a; int* q = p; *q = 200; now print a;
    int a3 = 10;
    int* p3 = &a3;
    int* q3 = p3;
    *q3 = 200;
    cout << "13. Value of a3 after *q3=200:" << a3 << endl;
    return 0;
}