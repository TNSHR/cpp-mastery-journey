# Day 13 - Inheritance (Single Inheritance)

## Objective

Learn one of the four pillars of Object-Oriented Programming (OOP): **Inheritance**.

By the end of this lesson, you should understand:

- What inheritance is
- Why inheritance is used
- Base (Parent) class
- Derived (Child) class
- Single Inheritance
- Constructor calling order
- Destructor calling order
- Code Reusability
- Advantages and disadvantages of inheritance

---

# What is Inheritance?

Inheritance is an Object-Oriented Programming (OOP) concept that allows one class to acquire the properties and behaviors of another class.

Instead of writing the same code multiple times, we write it once in a parent class and reuse it in child classes.

---

# Real-Life Example

Suppose we have

Person

Every person has

- Name
- Age
- Address

Now we have

Student

Additional property

- Roll Number

Teacher

Additional property

- Salary

Instead of writing

Name

Age

Address

again inside Student and Teacher, we inherit them from Person.

Diagram

                Person
               /      \
         Student     Teacher

Student and Teacher automatically receive the common properties of Person.

---

# Why do we need Inheritance?

Without Inheritance

```cpp
class Student
{
    string name;
    int age;
};

class Teacher
{
    string name;
    int age;
};
```

Here the same code is repeated.

With inheritance

```cpp
class Person
{
protected:
    string name;
    int age;
};

class Student : public Person
{
};

class Teacher : public Person
{
};
```

Now the common code exists only once.

Advantages

- Code Reusability
- Less Duplication
- Easier Maintenance
- Better Organization
- Easier Expansion

---

# Syntax

```cpp
class DerivedClass : accessSpecifier BaseClass
{
};
```

Example

```cpp
class Student : public Person
{
};
```

Read as

Student publicly inherits from Person.

---

# Terminology

Base Class

Also called

- Parent Class
- Super Class

Example

```cpp
class Person
{
};
```

Derived Class

Also called

- Child Class
- Sub Class

Example

```cpp
class Student : public Person
{
};
```

---

# Single Inheritance

One child inherits from one parent.

Diagram

Person

↓

Student

Example

```cpp
class Student : public Person
{
};
```

---

# Constructor Calling Order

Whenever a derived object is created,

the Base Class constructor always executes first.

Example

```cpp
Student s1("Rahul",20,101);
```

Execution

```
Memory Allocated

↓

Person Constructor

↓

Student Constructor

↓

Object Ready
```

This order cannot be changed.

Reason

The child class cannot exist until the parent part of the object has been created.

---

# Destructor Calling Order

When an object is destroyed

the reverse order is followed.

Execution

```
Student Destructor

↓

Person Destructor
```

Reason

The child object must clean up its own resources first before destroying the parent part.

---

# Why Protected?

Suppose

```cpp
class Person
{
protected:
    string name;
};
```

Now Student can use

```cpp
name
```

directly.

If

```cpp
private
```

had been used,

Student would not be able to access it.

---

# Access Specifiers in Inheritance

Public

Accessible everywhere.

Private

Accessible only inside the class.

Protected

Accessible inside the class and inside derived classes.

---

# Constructor Initialization List

Example

```cpp
Student(string n,int a,int r)
    : Person(n,a)
{
    rollNumber = r;
}
```

Meaning

Before creating Student,

call the Person constructor.

Advantages

- Faster initialization
- Required for const members
- Required for reference members
- Modern C++ practice

---

# Code Reusability

Without Inheritance

```
Name

Age

Address

↓

Repeated in every class
```

With Inheritance

```
Person

↓

Student

↓

Teacher

↓

Principal
```

Common code exists only once.

---

# Memory Representation

Object

Student s1

```
+----------------------------+
| Person Part                |
| Name                       |
| Age                        |
+----------------------------+
| Student Part               |
| Roll Number                |
+----------------------------+
```

A Student object actually contains

- Person Part
- Student Part

---

# Advantages of Inheritance

✔ Code Reuse

✔ Easy Maintenance

✔ Easy Expansion

✔ Better Software Design

✔ Less Duplicate Code

✔ Supports Polymorphism

---

# Disadvantages

- Tight coupling between classes
- Incorrect inheritance hierarchy can make code difficult to maintain
- Can increase complexity if overused

---

# Common Mistakes

Mistake

```cpp
class Student : Person
```

This is **private inheritance** by default for classes.

Preferred

```cpp
class Student : public Person
```

---

Mistake

Trying to access

```cpp
private
```

members directly.

Wrong

```cpp
name = "Rahul";
```

if name is private in Person.

---

Mistake

Forgetting to call the base class constructor.

Wrong

```cpp
Student(string n,int a,int r)
{
}
```

Correct

```cpp
Student(string n,int a,int r)
    : Person(n,a)
{
}
```

---

# Key Points

✔ Inheritance allows one class to reuse another class.

✔ Parent class is called Base Class.

✔ Child class is called Derived Class.

✔ Constructor Order

Base

↓

Derived

✔ Destructor Order

Derived

↓

Base

✔ Public inheritance models an "is-a" relationship.

Example

Student is a Person.

Teacher is a Person.

---

# Interview Questions & Answers

## 1. What is Inheritance?

Answer

Inheritance is an OOP feature that allows one class to acquire the properties and behaviors of another class. It promotes code reuse and reduces duplication.

---

## 2. Why do we use Inheritance?

Answer

Inheritance is used to

- Reuse existing code
- Reduce duplication
- Improve maintainability
- Build hierarchical relationships
- Support polymorphism

---

## 3. What is the difference between a Base Class and a Derived Class?

Answer

Base Class

The class whose properties are inherited.

Derived Class

The class that inherits from the base class.

Example

```cpp
class Person
{
};

class Student : public Person
{
};
```

Person

→ Base Class

Student

→ Derived Class

---

## 4. What is Single Inheritance?

Answer

Single inheritance means one child class inherits from one parent class.

Example

```
Person

↓

Student
```

---

## 5. What is the syntax of inheritance?

Answer

```cpp
class Student : public Person
{
};
```

---

## 6. Why do we use protected instead of private?

Answer

Protected members are accessible inside derived classes, while private members are not.

This allows child classes to reuse parent data safely.

---

## 7. Which constructor executes first?

Answer

The Base Class constructor always executes first.

Then the Derived Class constructor executes.

Reason

The parent part of an object must be initialized before the child part.

---

## 8. Which destructor executes first?

Answer

The Derived Class destructor executes first.

Then the Base Class destructor executes.

Reason

The child object must clean up its own resources before destroying the parent object.

---

## 9. What is Code Reusability?

Answer

Code reusability means writing common functionality once and using it in multiple places instead of duplicating code.

Inheritance is one of the main techniques used to achieve code reusability.

---

## 10. Can a derived class access private members of the base class?

Answer

No.

Private members cannot be accessed directly by derived classes.

They can only be accessed through public or protected member functions of the base class.

---

## 11. Does inheritance copy the base class code?

Answer

No.

Inheritance does not copy the code. The derived class extends the base class and gains access to its members according to the inheritance rules.

---

## 12. What is an "is-a" relationship?

Answer

Public inheritance represents an "is-a" relationship.

Examples

Student is a Person.

Teacher is a Person.

Car is a Vehicle.

Dog is an Animal.

---

# Quick Revision

Inheritance

→ Reuse existing code.

Base Class

→ Parent Class.

Derived Class

→ Child Class.

Single Inheritance

→ One Parent → One Child.

Constructor Order

Base → Derived.

Destructor Order

Derived → Base.

Protected

→ Accessible inside derived classes.

Private

→ Not directly accessible inside derived classes.

Public Inheritance

→ Represents an "is-a" relationship.

---

# What's Next?

Day 14

- Types of Inheritance
- Multiple Inheritance
- Multilevel Inheritance
- Hierarchical Inheritance
- Hybrid Inheritance
- Diamond Problem
- Constructor & Destructor order in different inheritance types
- Interview Questions