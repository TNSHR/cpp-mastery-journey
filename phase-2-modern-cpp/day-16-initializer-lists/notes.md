# Day 16 — Initializer Lists

## Phase 2 — Modern C++

---

# 1. Day Objective

By the end of Day 16, you should understand:

- What constructor member initializer lists are.
- Why initializer lists are preferred over assignment inside constructors.
- How to initialize:
  - normal data members
  - `const` members
  - reference members
  - member objects
  - base classes
- The difference between initialization and assignment.
- Member initialization order.
- Common initializer-list mistakes.
- How initializer lists are used in production C++.
- Why initializer lists are important for embedded and resource-constrained systems.

---

# 2. What Is an Initializer List?

A constructor initializer list is the part of a constructor that initializes class members before the constructor body executes.

Syntax:

```cpp
ClassName(parameters)
    : member1(value1),
      member2(value2),
      member3(value3)
{
    // constructor body
}
