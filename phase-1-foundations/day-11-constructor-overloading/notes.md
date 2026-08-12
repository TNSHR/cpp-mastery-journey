# Day 11 - Constructor Overloading & Copy Constructor

## Objective

Learn how objects are initialized in different ways and how objects are copied in C++.

---

# Constructors

A constructor is a special member function that is automatically called when an object is created.

Characteristics:
- Same name as the class.
- No return type.
- Called automatically.
- Used to initialize objects.

Example:

class Student
{
public:
    Student()
    {
    }
};

---

# Constructor Overloading

A class can have multiple constructors with different parameter lists.

Example:

Student()

Student(string name)

Student(string name, int marks)

The compiler chooses the correct constructor based on the arguments provided.

Advantages:
- Flexible object creation.
- Cleaner code.
- Better readability.
- Avoids repetitive initialization code.

---

# Default Constructor

A constructor with no parameters.

Example:

Student()
{
    name = "Unknown";
    marks = 0;
}

Usage:

Student s1;

---

# Parameterized Constructor

A constructor that accepts parameters.

Example:

Student(string n, int m)
{
    name = n;
    marks = m;
}

Usage:

Student s2("Shrinath", 98);

---

# Copy Constructor

A constructor that creates a new object from an existing object.

Syntax:

Student(const Student& other)

Example:

Student s1("Shrinath", 98);

Student s2(s1);

Purpose:
- Copy an existing object.
- Used when passing or returning objects by value.
- Required for proper resource management.

---

# Why pass by Reference?

Correct:

Student(const Student& other)

Wrong:

Student(Student other)

Passing by value would create another copy, causing infinite recursive constructor calls.

Using a reference avoids unnecessary copying.

Using const prevents accidental modification of the original object.

---

# Copy Constructor vs Assignment Operator

Copy Constructor

Student s2(s1);

- Creates a new object.
- Automatically called.

Assignment Operator

Student s2;

s2 = s1;

- Object already exists.
- Copies values only.

---

# Constructor Initialization List

Instead of:

Student(string n, int m)
{
    name = n;
    marks = m;
}

Modern C++ prefers:

Student(string n, int m)
    : name(n), marks(m)
{
}

Advantages:
- Faster initialization.
- Required for const and reference members.
- Preferred in modern C++.

---

# Shallow Copy (Introduction)

A shallow copy copies memory addresses instead of creating new memory.

This can lead to:
- Shared resources.
- Double deletion.
- Memory corruption.

We'll study this in detail later.

---

# Deep Copy (Introduction)

A deep copy creates completely independent copies of resources.

Each object owns its own memory.

---

# Key Points

✔ Constructors initialize objects automatically.

✔ A class can have multiple constructors.

✔ Copy constructors create new objects from existing ones.

✔ Copy constructors should receive objects by const reference.

✔ Assignment operators copy values into an already existing object.

✔ Initialization lists are preferred in modern C++.

---

# Interview Tips

Remember:

Student s1;

→ Default Constructor

Student s2("Rahul",95);

→ Parameterized Constructor

Student s3(s2);

→ Copy Constructor

Student s4;

s4 = s2;

→ Assignment Operator

---

# Summary

Constructor
→ Initializes a new object.

Constructor Overloading
→ Multiple constructors with different parameters.

Copy Constructor
→ Creates a new object from another object.

Assignment Operator
→ Copies values into an existing object.

Initialization List
→ Modern and efficient way of initializing members.