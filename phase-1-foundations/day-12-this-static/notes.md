# Day 12 - this Pointer, Static Members & Const Member Functions

---

# Objective

Learn three important concepts of Object-Oriented Programming (OOP):

1. this Pointer
2. Static Data Members & Static Member Functions
3. Const Member Functions

These concepts are widely used in modern C++, Qt Framework, STL, Embedded Systems, and Robotics.

---

# 1. this Pointer

## Definition

The **this pointer** is a hidden pointer automatically passed to every non-static member function.

It points to the object that invoked the member function.

Every object has its own unique `this` pointer while executing member functions.

---

## Why do we need this Pointer?

Suppose a constructor receives a parameter having the same name as a class member.

Example:

```cpp
class Student
{
private:
    string name;

public:

    Student(string name)
    {
        this->name = name;
    }
};
```

Without `this`:

```cpp
name = name;
```

Both refer to the constructor parameter.

The member variable remains unchanged.

Using

```cpp
this->name = name;
```

means

Assign the parameter **name**
to the object's member variable **name**.

---

## Internal Working

When you write

```cpp
Student s1;

s1.display();
```

The compiler internally converts it approximately into

```cpp
display(&s1);
```

Inside display(),

```
this = &s1
```

The this pointer always stores the address of the current object.

---

## Important Points

✔ Every non-static member function has a this pointer.

✔ Static member functions do NOT have a this pointer.

✔ this is a pointer to the current object.

✔ Used to avoid naming conflicts.

---

# 2. Static Data Members

## Definition

A static data member belongs to the class instead of individual objects.

Only one copy exists in memory.

All objects share it.

---

## Why Static?

Normally,

```cpp
Student s1;
Student s2;
Student s3;
```

Each object has

```
name
marks
```

stored separately.

But suppose we want to know

```
How many students have been created?
```

The count should be common for every object.

Static members solve this problem.

---

## Example

```cpp
class Student
{
public:

    static int count;

    Student()
    {
        count++;
    }
};

int Student::count = 0;
```

Usage

```cpp
Student s1;
Student s2;
Student s3;

cout << Student::count;
```

Output

```
3
```

---

## Characteristics

✔ Shared by all objects

✔ Created only once

✔ Stored in static memory

✔ Accessed using

```cpp
Student::count
```

---

# 3. Static Member Function

## Definition

A static member function belongs to the class rather than an object.

It can be called without creating an object.

---

## Example

```cpp
class Student
{
public:

    static void welcome()
    {
        cout<<"Welcome";
    }
};

int main()
{
    Student::welcome();
}
```

---

## Important Rules

Static member functions

CAN access

✔ Static variables

✔ Static functions

Cannot access

✘ Non-static variables

✘ Non-static functions

because there is no object.

---

# 4. Const Member Function

## Definition

A const member function promises not to modify the object.

Syntax

```cpp
void display() const
{
}
```

---

## Why use const?

Suppose display() only prints information.

It should never change

```
name

marks

salary
```

Adding const makes the compiler enforce that promise.

---

## Example

```cpp
class Student
{
private:

    string name;

public:

    Student(string n)
        : name(n)
    {
    }

    void display() const
    {
        cout<<name;
    }
};
```

---

## Advantages

✔ Prevents accidental modification

✔ Improves code safety

✔ Makes APIs clearer

✔ Required when working with const objects

---

# Difference Between Static Function and Normal Function

| Normal Function | Static Function |
|----------------|----------------|
| Belongs to object | Belongs to class |
| Has this pointer | No this pointer |
| Accesses all members | Accesses only static members |
| Called using object | Called using class name |

---

# Difference Between Static Variable and Normal Variable

| Normal Variable | Static Variable |
|----------------|----------------|
| Every object has its own copy | One copy shared by all objects |
| Stored inside object | Stored once in static memory |
| Different values | Common value |

---

# Key Points

✔ this points to the current object.

✔ Static variables belong to the class.

✔ Static functions belong to the class.

✔ Static functions cannot access non-static members directly.

✔ Const functions promise not to modify object data.

✔ Getter functions should usually be const.

---

# Real World Examples

## this Pointer

Current logged-in user.

```
this = Current User
```

---

## Static Variable

```
Total Employees

Total Cars

Total Students
```

Shared by all objects.

---

## Const Function

```
Check Balance

Display Details

Print Report
```

These functions only display information.

They should not modify data.

---

# Summary

this Pointer

↓

Current Object

----------------------------

Static Variable

↓

Shared among all objects

----------------------------

Static Function

↓

Belongs to class

----------------------------

Const Function

↓

Cannot modify object

---

# Interview Questions & Answers

## 1. What is the this pointer?

Answer:

The this pointer is a hidden pointer automatically passed to every non-static member function. It points to the current object that invoked the function.

---

## 2. When is the this pointer created?

Answer:

The this pointer is automatically available whenever a non-static member function is called. It points to the object that called the function.

---

## 3. Why do we use this-> ?

Answer:

We use `this->` to refer to the object's member variables, especially when constructor parameters or local variables have the same name as class members.

Example:

```cpp
this->name = name;
```

---

## 4. What is a static data member?

Answer:

A static data member belongs to the class rather than individual objects. Only one copy exists and it is shared by all objects.

---

## 5. Why do we use static variables?

Answer:

We use static variables to store information that should be common to every object, such as total number of students, employees, or cars created.

---

## 6. What is a static member function?

Answer:

A static member function belongs to the class and can be called without creating an object.

Example:

```cpp
Student::showCount();
```

---

## 7. Can a static function access non-static members?

Answer:

No.

Static member functions do not have a this pointer, so they cannot directly access non-static data members or member functions.

---

## 8. What is a const member function?

Answer:

A const member function promises not to modify the object's data. It is declared by writing `const` after the function declaration.

Example:

```cpp
void display() const;
```

---

## 9. Why should getter functions be const?

Answer:

Getter functions only return data and should not modify the object. Declaring them const prevents accidental modification and allows them to be called on const objects.

---

## 10. Can a const member function modify object data?

Answer:

No.

A const member function cannot modify non-mutable data members of the object. If it attempts to do so, the compiler generates an error.

---

# Revision Checklist

□ Understand this pointer

□ Understand static variables

□ Understand static functions

□ Understand const member functions

□ Solve today's assignment

□ Answer all interview questions without looking at notes
