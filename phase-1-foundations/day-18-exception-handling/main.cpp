#include <iostream>

#include "Calculator.h"
#include "InvalidAgeException.h"

using namespace std;

void validateAge(int age)
{
    if (age < 18)
    {
        throw InvalidAgeException();
    }

    cout << "Age is valid." << endl;
}

int main()
{
    cout << "========== Calculator ==========\n";

    try
    {
        cout << "Addition       : "
             << Calculator::add(10, 20)
             << endl;

        cout << "Subtraction    : "
             << Calculator::subtract(20, 5)
             << endl;

        cout << "Multiplication : "
             << Calculator::multiply(8, 4)
             << endl;

        cout << "Division       : "
             << Calculator::divide(20, 5)
             << endl;

        cout << "\nTrying Division by Zero...\n";

        cout << Calculator::divide(20, 0)
             << endl;
    }
    catch (const exception &e)
    {
        cout << "Calculator Error : "
             << e.what()
             << endl;
    }

    cout << "\n========== Age Validation ==========\n";

    try
    {
        validateAge(15);
    }
    catch (const InvalidAgeException &e)
    {
        cout << "Age Error : "
             << e.what()
             << endl;
    }

    cout << "\nProgram Finished Successfully."
         << endl;

    return 0;
}