# Phase 2 - Day 4
# Lambda Expressions

---

# Objective

Learn Lambda Expressions in Modern C++.

Understand

- Why Lambdas were introduced
- Anonymous Functions
- Capture Lists
- Capture by Value
- Capture by Reference
- Mutable Lambdas
- STL Algorithms with Lambdas
- Compiler Implementation
- Interview Questions

---

# Why were Lambda Expressions introduced?

Before C++11

Suppose we wanted to print every employee.

We usually wrote

```cpp
void printEmployee(const Employee& employee)
{
    employee.display();
}
```

Then

```cpp
std::for_each(
employees.begin(),
employees.end(),
printEmployee
);
```

Problems

- Too many tiny functions
- Functions used only once
- Harder to read
- Logic separated from where it is used

C++11 solved this problem using Lambda Expressions.

---

# What is a Lambda?

A Lambda is an anonymous function.

Anonymous means

It has no name.

Example

```cpp
[](int number)
{
    return number * number;
}
```

This function exists only where it is written.

---

# Lambda Syntax

```cpp
[capture](parameters)
{
    body
}
```

Example

```cpp
[](const Employee& employee)
{
    employee.display();
}
```

---

# Lambda Components

## 1. Capture List

```
[]
```

Controls which outside variables the Lambda can use.

---

## 2. Parameters

```
()
```

Exactly like normal functions.

---

## 3. Body

```
{}
```

Contains executable code.

---

# Compiler's View ⭐

Suppose

```cpp
auto square =
[](int x)
{
    return x * x;
};
```

Compiler conceptually creates

```cpp
class __Lambda
{
public:

    int operator()(int x) const
    {
        return x * x;
    }
};
```

Then

```cpp
auto square = __Lambda();
```

A Lambda is actually an object.

Not magic.

---

# Memory Diagram

```
square

↓

Lambda Object

↓

operator()

↓

Execution
```

---

# Why are Lambdas Fast?

Because

Compiler

knows

everything

at compile time.

Usually

they are

fully inlined.

No function call overhead.

---

# Capture List

## Empty Capture

```cpp
[]
```

Cannot use outside variables.

Example

```cpp
[](int x)
{
    return x * 2;
}
```

---

## Capture by Value

```cpp
[value]
```

Copies variable.

Example

```cpp
int bonus = 5000;

[bonus]
(const Employee& employee)
{
    return employee.getSalary() > bonus;
}
```

Memory

```
bonus

↓

COPY

↓

Lambda
```

Original variable cannot be modified.

---

## Capture by Reference

```cpp
[&value]
```

Stores reference.

Example

```cpp
int count = 0;

[&count]
()
{
    count++;
}
```

Memory

```
count

↓

Reference

↓

Lambda
```

Original variable changes.

---

## Capture Everything by Value

```cpp
[=]
```

Copies all outside variables.

---

## Capture Everything by Reference

```cpp
[&]
```

References all outside variables.

---

## Capture this

Inside classes

```cpp
[this]
```

Allows Lambda to access

member variables.

Example

```cpp
[this]
{
    display();
}
```

---

# Mutable Lambda

Normally

Captured values

are read-only.

Example

```cpp
[value]
() mutable
{
    value++;
}
```

Without

```
mutable
```

Compiler gives an error.

---

# STL Algorithms Used Today

---

## std::for_each()

Purpose

Execute code

for every element.

Example

```cpp
std::for_each(
employees.begin(),
employees.end(),

[](const Employee& employee)
{
    employee.display();
});
```

---

## std::find_if()

Purpose

Find first matching element.

Returns

Iterator.

---

## std::count_if()

Purpose

Count matching elements.

Returns

Integer.

---

## std::sort()

Purpose

Sort container.

Requires

Comparator.

Example

```cpp
[](const Employee& a,
const Employee& b)
{
    return
a.getSalary()
<
b.getSalary();
}
```

---

# Memory Flow

```
Vector

↓

STL Algorithm

↓

Lambda

↓

Employee

↓

Result
```

---

# Lambda vs Normal Function

Normal Function

```
Named

Reusable

Separate Definition
```

Lambda

```
Anonymous

Small

Written Inline
```

---

# When to Use Lambdas

✔ Small logic

✔ One-time use

✔ STL Algorithms

✔ Event Handlers

✔ Callbacks

✔ Qt Signals

✔ ROS2 Callbacks

---

# When NOT to Use Lambdas

❌ Huge business logic

❌ Hundreds of lines

❌ Reused across many files

Use a normal function instead.

---

# Best Practices

✔ Keep Lambdas small.

✔ Capture only what is needed.

✔ Prefer

```cpp
const auto&
```

inside Lambdas.

✔ Avoid

```cpp
[&]
```

unless necessary.

✔ Prefer explicit captures

```cpp
[salary]
```

instead of

```cpp
[=]
```

when possible.

---

# Common Mistakes

❌ Capturing everything by reference unnecessarily.

❌ Large Lambdas.

❌ Forgetting capture list.

❌ Modifying captured values without

```
mutable
```

❌ Returning references to destroyed objects.

---

# Real World Analogy

Imagine hiring a temporary worker.

Old Way

```
Hire Employee

↓

Give Employee Name

↓

Assign Office

↓

One Task
```

Modern Way

```
Call Worker

↓

Do Task

↓

Leave
```

Lambda

is

that temporary worker.

---

# Professional Usage

Google

```
Algorithms

+

Lambdas
```

LLVM

```
Algorithms

+

Lambdas
```

Qt

```
Signals

↓

Lambdas
```

ROS2

```
Callbacks

↓

Lambdas
```

Modern C++

uses Lambdas extensively.

---

# Interview Questions

## Beginner

### 1. What is a Lambda Expression?

An anonymous function introduced in C++11.

---

### 2. Why use Lambdas?

To write small functions exactly where they are needed.

---

### 3. What does [] mean?

Capture List.

---

### 4. Can Lambdas have parameters?

Yes.

Exactly like normal functions.

---

### 5. Can Lambdas return values?

Yes.

---

## Intermediate

### 6. Difference between

```
[]
```

and

```
[=]
```

Answer

```
[]

No Capture

[=]

Capture All By Value
```

---

### 7. Difference between

```
[value]
```

and

```
[&value]
```

Answer

```
[value]

Copy

[&value]

Reference
```

---

### 8. Why use Lambdas with STL?

Because STL algorithms require callable objects.

Lambdas provide concise inline behavior.

---

### 9. What does std::find_if() return?

Iterator.

---

### 10. What does std::count_if() return?

Count of matching elements.

---

## Advanced

### 11. What is a Lambda internally?

A compiler-generated class with `operator()`.

---

### 12. Why are Lambdas efficient?

They are usually inlined by the compiler.

---

### 13. When should you avoid Lambdas?

When the logic is large or reused frequently.

---

### 14. What is mutable in a Lambda?

It allows modification of variables captured by value.

---

### 15. Can Lambdas capture member variables?

Yes, using

```cpp
[this]
```

---

# Assignment

## Level 1

Create a Lambda

that prints

Hello World.

---

## Level 2

Create a Lambda

that squares a number.

---

## Level 3

Use

```
std::for_each()
```

to display employees.

---

## Level 4

Use

```
std::find_if()
```

to search by salary.

---

## Level 5

Use

```
std::count_if()
```

to count employees.

---

## Level 6

Sort employees

using

```
std::sort()
```

---

## Level 7 ⭐

Create one Lambda

capturing

salary

by value.

Create another

capturing

salary

by reference.

Observe

the difference.

---

# Summary

Today we learned

✔ Lambda Expressions

✔ Anonymous Functions

✔ Capture Lists

✔ Capture by Value

✔ Capture by Reference

✔ Mutable Lambdas

✔ std::for_each()

✔ std::find_if()

✔ std::count_if()

✔ std::sort()

✔ Compiler Implementation

✔ Interview Questions

---

# Phase 2 Progress

✅ Day 1 — auto

✅ Day 2 — nullptr

✅ Day 3 — Range-Based for Loops

✅ Day 4 — Lambda Expressions

Next

➡ Day 5 — std::unique_ptr (Smart Pointers)