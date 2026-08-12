# Phase 2 - Day 1
# Modern C++ - auto Keyword

---

# Objective

Learn the Modern C++ `auto` keyword.

Understand how the compiler automatically deduces variable types and when `auto` should be used in professional C++ development.

---

# What is auto?

`auto` is a keyword introduced in C++11.

It allows the compiler to automatically determine the type of a variable based on its initializer.

Example

```cpp
auto age = 25;
```

Compiler converts it into

```cpp
int age = 25;
```

---

Example 2

```cpp
auto salary = 55000.50;
```

Compiler converts it into

```cpp
double salary = 55000.50;
```

---

Example 3

```cpp
auto employee = Employee(101, "Shrinath", 50000);
```

Compiler converts it into

```cpp
Employee employee(101, "Shrinath", 50000);
```

---

# Why was auto introduced?

Before C++11

```cpp
std::vector<Employee>::iterator it = employees.begin();
```

After C++11

```cpp
auto it = employees.begin();
```

Benefits

- Less typing
- Cleaner code
- Fewer mistakes
- Easier template programming
- Better readability

---

# How auto Works

Source Code

```cpp
auto x = 100;
```

Compiler

↓

```cpp
int x = 100;
```

Type deduction happens at compile time.

There is **no runtime overhead**.

---

# auto with Objects

Traditional

```cpp
Employee employee(101, "Shrinath", 50000);
```

Modern

```cpp
auto employee = Employee(101, "Shrinath", 50000);
```

Compiler automatically deduces the type as `Employee`.

---

# auto with References

```cpp
auto& employees = manager.getEmployees();
```

Compiler deduces

```cpp
std::vector<Employee>&
```

Using `&` avoids copying the vector.

---

# auto with Range-Based Loop

```cpp
for (const auto& employee : employees)
```

Compiler internally converts it to

```cpp
for (const Employee& employee : employees)
```

Benefits

- No object copying
- Read-only access
- Cleaner syntax
- Better performance

---

# auto with Iterators

Traditional

```cpp
std::vector<Employee>::iterator it = employees.begin();
```

Modern

```cpp
auto it = employees.begin();
```

This is one of the most common real-world uses of `auto`.

---

# auto vs auto& vs const auto&

## auto

```cpp
auto employee = employees[0];
```

Creates a copy.

Safe, but may be slow for large objects.

---

## auto&

```cpp
auto& employee = employees[0];
```

Creates a reference.

No copy.

Allows modification.

---

## const auto&

```cpp
const auto& employee = employees[0];
```

Creates a read-only reference.

No copy.

Cannot modify the object.

This is the preferred choice for read-only loops.

---

# When to Use auto

✔ Object creation

✔ STL iterators

✔ Range-based loops

✔ Complex template types

✔ Lambda expressions (later)

✔ Smart pointers (later)

---

# When NOT to Use auto

Avoid `auto` when the type is not obvious.

Example

```cpp
auto value = calculateSomething();
```

Without knowing the return type of `calculateSomething()`, the code becomes harder to understand.

Prefer explicit types when readability is more important than shorter code.

---

# Advantages of auto

✔ Cleaner code

✔ Less typing

✔ Fewer type mismatches

✔ Compiler deduces correct type

✔ Easier maintenance

✔ Excellent with STL

---

# Disadvantages

✘ Can reduce readability if the type is unclear

✘ Beginners may not know what type was deduced

✘ Overusing auto can make code harder to understand

---

# Memory Diagram

Source Code

```cpp
auto number = 100;
```

Compiler

↓

```cpp
int number = 100;
```

Memory

```
number
│
└── int
      │
      └── 100
```

---

# Project Architecture

```
main.cpp
      │
      ▼
EmployeeManager
      │
      ▼
vector<Employee>
      │
      ▼
Employee Objects
```

---

# Best Practices

✔ Use `auto` when the type is obvious.

✔ Prefer `const auto&` in range-based loops.

✔ Use `auto` with STL iterators.

✔ Don't use `auto` just to save typing.

✔ Prioritize readability over shorter code.

---

# Common Mistakes

❌ Using `auto` everywhere.

❌ Forgetting `&`, causing unnecessary copies.

❌ Using plain `auto` for large objects inside loops.

❌ Assuming `auto` makes the program faster.

❌ Using `auto` when the type is unclear.

---

# Interview Questions

## Beginner

### 1. What is auto?

`auto` allows the compiler to automatically deduce the type of a variable.

---

### 2. When was auto introduced?

C++11.

---

### 3. Does auto improve runtime performance?

No.

Type deduction happens during compilation.

---

### 4. Can auto be used with classes?

Yes.

Example

```cpp
auto employee = Employee(...);
```

---

### 5. Can auto be used with STL?

Yes.

It is commonly used with vectors, maps, iterators, and algorithms.

---

## Intermediate

### 6. Difference between auto and auto&?

`auto`

Creates a copy.

`auto&`

Creates a reference.

---

### 7. Difference between auto and const auto&?

`auto`

Creates a copy.

`const auto&`

Creates a read-only reference without copying.

---

### 8. Why is const auto& recommended in loops?

Because it avoids unnecessary copying and prevents accidental modification.

---

### 9. Why does Modern C++ encourage auto?

It reduces boilerplate code while keeping the program type-safe.

---

### 10. Can auto deduce pointers?

Yes.

Example

```cpp
auto ptr = &number;
```

Compiler deduces

```cpp
int*
```

---

## Advanced

### 11. How does auto work internally?

The compiler examines the initializer and replaces `auto` with the deduced type during compilation.

---

### 12. Does auto change the generated machine code?

No.

The generated code is equivalent to writing the explicit type.

---

# Assignment

## Level 1

Create five variables using auto.

- int
- double
- char
- bool
- std::string

---

## Level 2

Create three Employee objects using auto.

Display them.

---

## Level 3

Store Employees inside a vector.

Display using

```cpp
const auto&
```

---

## Level 4

Display employees using an iterator created with

```cpp
auto
```

---

## Level 5 ⭐

Compare

```cpp
auto
```

and

```cpp
const auto&
```

inside a loop.

Observe the difference in copying behavior (conceptually).

---

# Summary

Today we learned

✔ Modern C++

✔ auto keyword

✔ Type deduction

✔ auto with objects

✔ auto with vectors

✔ auto with iterators

✔ auto with references

✔ const auto&

✔ Best practices

✔ Interview concepts

---

# Phase 2 Progress

✅ Day 1 — auto Keyword

Next

➡ Day 2 — nullptr and nullptr_t