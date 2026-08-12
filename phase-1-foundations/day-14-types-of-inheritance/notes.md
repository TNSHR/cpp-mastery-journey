# Day 14 – Types of Inheritance

## Objective

Understand the different inheritance models available in C++ and when to use each one.

---

# 1. Single Inheritance

One child inherits from one parent.

```
Person
   │
Student
```

Example:

```cpp
class Student : public Person
{
};
```

---

# 2. Multilevel Inheritance

A class inherits from another derived class.

```
Person
   │
Student
   │
ResearchStudent
```

ResearchStudent inherits everything from Student and Person.

---

# 3. Hierarchical Inheritance

Multiple child classes inherit from one parent.

```
        Person
       /      \
 Student      Teacher
```

Student and Teacher both inherit from Person.

---

# 4. Multiple Inheritance

A class inherits from two or more parent classes.

```
Teacher        Employee
      \        /
       \      /
      TeachingAssistant
```

Example:

```cpp
class TeachingAssistant
    : public Student,
      public Employee
{
};
```

Use carefully because it increases complexity.

---

# 5. Hybrid Inheritance

A combination of two or more inheritance types.

Example:

```
          Person
         /      \
   Student    Employee
         \      /
    TeachingAssistant
```

Hybrid inheritance often introduces ambiguity.

---

# 6. Diamond Problem

```
        Person
       /      \
 Student      Employee
       \      /
 TeachingAssistant
```

Now TeachingAssistant has **two Person objects**, causing ambiguity.

Solution:

Use **virtual inheritance**.

Example:

```cpp
class Student : virtual public Person
{
};

class Employee : virtual public Person
{
};
```

---

# Constructor Order

Always:

Base Class

↓

Derived Class

---

# Destructor Order

Always:

Derived Class

↓

Base Class

---

# Advantages

- Code Reuse
- Better Design
- Easy Maintenance
- Extensibility

---

# Disadvantages

- Tight Coupling
- Complexity
- Diamond Problem
- Harder to debug if overused

---

# Interview Questions & Answers

## 1. What is inheritance?

Inheritance allows one class to acquire properties and behaviors of another class.

---

## 2. What are the five types of inheritance?

- Single
- Multiple
- Multilevel
- Hierarchical
- Hybrid

---

## 3. What is multilevel inheritance?

A derived class becomes the parent of another derived class.

Example:

Person → Student → ResearchStudent

---

## 4. What is hierarchical inheritance?

One parent has multiple child classes.

Example:

Person → Student

Person → Teacher

---

## 5. What is multiple inheritance?

One class inherits from two or more parent classes.

---

## 6. What is hybrid inheritance?

A combination of two or more inheritance types.

---

## 7. What is the Diamond Problem?

When multiple inheritance causes a class to receive two copies of the same base class, leading to ambiguity.

---

## 8. How is the Diamond Problem solved?

Using virtual inheritance.

---

## 9. Which constructor executes first?

Base constructor.

---

## 10. Which destructor executes first?

Derived destructor.

---

## 11. Why is inheritance important?

It promotes code reuse, reduces duplication, and improves maintainability.

---

# Revision

- Single → One parent, one child.
- Multilevel → Chain of inheritance.
- Hierarchical → One parent, many children.
- Multiple → Many parents, one child.
- Hybrid → Combination of inheritance models.
- Diamond Problem → Solved with virtual inheritance.