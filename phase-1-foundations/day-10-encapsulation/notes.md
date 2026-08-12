# Day 10 – Encapsulation

## Encapsulation
Combining data and methods into a class while protecting the data from direct access.

## Access Specifiers

public
- Accessible everywhere.

private
- Accessible only inside the class.

protected
- Accessible inside the class and derived classes.

## Getter
Returns private data.

## Setter
Updates private data after validation.

## Benefits

- Data Hiding
- Validation
- Security
- Better Design
- Easier Maintenance



1. What is Encapsulation?
Answer

Encapsulation is the process of combining data (variables) and the methods (functions) that operate on that data into a single unit called a class, while restricting direct access to the data.

It protects the internal state of an object from unauthorized or invalid modifications.

Example
class Student
{
private:
    int marks;

public:
    void setMarks(int m);
    int getMarks();
};

The variable marks is hidden from outside code.

2. Why do we use Encapsulation?
Answer

Encapsulation is used to:

Protect data from accidental modification.
Ensure data is always valid.
Hide implementation details.
Improve code security.
Make programs easier to maintain.
Reduce bugs caused by invalid data.
Real-Life Example

An ATM lets you:

Withdraw money
Deposit money
Check balance

But it doesn't let you directly modify the bank's database.

This is encapsulation.

3. What is Data Hiding?
Answer

Data hiding means making important data inaccessible from outside the class by declaring it as private.

Only selected member functions can access or modify that data.

Example
private:
    double salary;

Outside code cannot do:

emp.salary = 50000;

Instead:

emp.setSalary(50000);
4. What is the difference between public, private, and protected?
Access Specifier	Same Class	Outside Class	Derived Class
public	✅ Yes	✅ Yes	✅ Yes
private	✅ Yes	❌ No	❌ No
protected	✅ Yes	❌ No	✅ Yes
Explanation
Public

Anyone can access it.

Example:

public:
    string name;

Outside:

student.name = "Rahul";

Works.

Private

Only the class itself can access it.

Example:

private:
    int marks;

Outside:

student.marks = 90;

Compilation Error.

Protected

Works like private, but derived classes (through inheritance) can access it.

We'll study this in detail when we learn Inheritance.

5. Why are Getters and Setters useful?
Answer

Getters and setters provide controlled access to private data.

Getter

Returns data.

Example

int getMarks()
{
    return marks;
}
Setter

Updates data after checking whether it is valid.

Example

void setMarks(int m)
{
    if(m >= 0 && m <= 100)
        marks = m;
}

Benefits:

Validation
Security
Controlled access
Easier maintenance
6. Why is Validation important?
Answer

Validation ensures that only correct and meaningful values are stored in an object.

Without validation:

salary = -50000;

This is logically incorrect.

With validation:

if(salary >= 0)

Invalid values are rejected.

Validation prevents bugs and keeps objects in a valid state.

7. Can private members be accessed directly from outside the class?
Answer

No.

Private members cannot be accessed directly from outside the class.

Example

class Employee
{
private:
    int salary;
};

This will produce an error:

Employee emp;

emp.salary = 50000;

Correct approach:

emp.setSalary(50000);
⭐ Quick Revision
Concept	Key Point
Encapsulation	Combining data and methods while restricting direct access to data.
Data Hiding	Protecting data using private.
Getter	Returns private data.
Setter	Updates private data with validation.
Validation	Prevents invalid values from being stored.
Public	Accessible from anywhere.
Private	Accessible only inside the class.
Protected	Accessible inside the class and derived classes.