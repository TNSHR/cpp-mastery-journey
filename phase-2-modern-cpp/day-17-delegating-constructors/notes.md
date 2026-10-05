# Day 17 — Delegating Constructors

## Phase 2 — Modern C++

---

# 1. Day Objective

The objective of Day 17 is to understand **Delegating Constructors** in modern C++.

After completing this day, you should be able to:

- Understand what a delegating constructor is.
- Understand why constructor delegation was introduced.
- Understand how one constructor delegates to another constructor of the same class.
- Understand the syntax of delegating constructors.
- Understand the target constructor.
- Understand constructor chaining.
- Avoid duplicated initialization logic.
- Understand the difference between constructor delegation and normal function calls.
- Understand the difference between delegating constructors and base-class initialization.
- Understand constructor delegation rules and restrictions.
- Identify circular delegation problems.
- Design clean constructor overloads.
- Explain delegating constructors in a C++ interview.
- Apply delegating constructors in production-style C++ code.
- Understand how delegating constructors relate to embedded C++ development.

---

# 2. What Is a Delegating Constructor?

A **delegating constructor** is a constructor that calls another constructor of the **same class**.

Example:

```cpp
class Student
{
private:
    int id;
    std::string name;

public:

    Student()
        : Student(0, "Unknown")
    {
    }

    Student(int studentId, const std::string& studentName)
        : id(studentId),
          name(studentName)
    {
    }
};