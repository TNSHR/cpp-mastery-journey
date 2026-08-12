# Phase 2 - Day 2
# Modern C++ - nullptr and nullptr_t

---

# Objective

Learn why C++11 introduced `nullptr`, how it differs from `NULL`, how to safely initialize pointers, and how to avoid common pointer-related bugs such as wild pointers and dangling pointers.

---

# Why was nullptr Introduced?

Before C++11, programmers used:

```cpp
NULL
```

or

```cpp
0
```

to represent a null pointer.

Example

```cpp
int* ptr = NULL;
```

or

```cpp
int* ptr = 0;
```

Although this worked, it caused ambiguity because `NULL` is typically defined as `0`.

C++11 introduced

```cpp
nullptr
```

which has its own dedicated pointer type.

---

# What is nullptr?

`nullptr` is a keyword introduced in C++11.

It represents a pointer that intentionally points to nothing.

Example

```cpp
int* ptr = nullptr;
```

Memory

```
ptr
│
└── nullptr
```

---

# NULL vs nullptr

Old C++

```cpp
int* ptr = NULL;
```

Modern C++

```cpp
int* ptr = nullptr;
```

Advantages of nullptr

✔ Type Safe

✔ Better Function Overloading

✔ Removes Ambiguity

✔ Recommended by Modern C++

---

# Function Overloading Problem

Example

```cpp
void print(int);
void print(int*);
```

Calling

```cpp
print(0);
```

Compiler chooses

```cpp
print(int);
```

because `0` is an integer literal.

Calling

```cpp
print(nullptr);
```

Compiler chooses

```cpp
print(int*);
```

No ambiguity.

---

# nullptr_t

The type of `nullptr` is

```cpp
std::nullptr_t
```

Header

```cpp
#include <cstddef>
```

Example

```cpp
std::nullptr_t value = nullptr;
```

Normally, you won't use `std::nullptr_t` directly, but it's useful for understanding how `nullptr` participates in type deduction and overload resolution.

---

# Pointer Initialization

Bad

```cpp
int* ptr;
```

Memory

```
ptr

↓

???????
```

Random address.

Dangerous.

---

Good

```cpp
int* ptr = nullptr;
```

Memory

```
ptr

↓

nullptr
```

Safe.

---

# Wild Pointer

Definition

A pointer that has never been initialized.

Example

```cpp
int* ptr;
```

Memory

```
ptr

↓

Random Address
```

Dereferencing it

```cpp
*ptr;
```

causes undefined behavior.

---

# Heap Allocation

```cpp
Employee* employee =
new Employee(...);
```

Execution

```
new

↓

Heap Allocation

↓

Constructor

↓

Return Address

↓

Pointer Receives Address
```

Memory

```
Stack

employee
    │
    ▼

Heap

Employee Object
```

---

# delete

```cpp
delete employee;
```

Execution

```
Object Destroyed

↓

Heap Memory Released
```

---

# Dangling Pointer

After

```cpp
delete employee;
```

Memory

```
employee

↓

Old Address

↓

Object No Longer Exists
```

This pointer is called a **dangling pointer**.

---

# Safe Practice

```cpp
delete employee;

employee = nullptr;
```

Now

```
employee

↓

nullptr
```

Safe again.

---

# Ownership

In today's project

```
EmployeeManager

↓

Owns

↓

Employee*
```

Therefore

```
EmployeeManager Destructor

↓

delete Employee

↓

Memory Released
```

---

# Why Destructor is Important

Without destructor

```
new Employee()

↓

Heap Memory

↓

Program Ends

↓

Memory Leak
```

With destructor

```
new Employee()

↓

Heap Memory

↓

delete

↓

Memory Released
```

---

# Arrow Operator

Pointer

```cpp
Employee* employee;
```

Access member

```cpp
employee->display();
```

Equivalent

```cpp
(*employee).display();
```

The `->` operator is more readable and is the standard way to access members through pointers.

---

# Memory Lifecycle

```
nullptr

↓

new

↓

Heap Object

↓

Use Object

↓

delete

↓

nullptr
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
vector<Employee*>
      │
      ▼
Heap Employee Objects
```

---

# Best Practices

✔ Always initialize pointers with nullptr.

✔ Always check for nullptr before dereferencing.

✔ Always delete dynamically allocated memory when ownership requires it.

✔ Set pointers to nullptr after delete if they may be reused.

✔ Clearly define which class owns dynamically allocated objects.

✔ Prefer Smart Pointers in modern production code whenever ownership is straightforward.

---

# Common Mistakes

❌ Leaving pointers uninitialized.

❌ Dereferencing nullptr.

❌ Forgetting delete.

❌ Accessing a dangling pointer.

❌ Using NULL in new C++ code.

❌ Confusing stack memory with heap memory.

---

# Real-World Analogy

Imagine a house.

Pointer

↓

House Address

If house exists

↓

Visit house.

If house demolished

↓

Old address becomes useless.

Erase the address

↓

nullptr.

This prevents you from visiting a house that no longer exists.

---

# Interview Questions

## Beginner

### 1. What is nullptr?

A keyword representing a null pointer.

---

### 2. Why was nullptr introduced?

To replace NULL with a type-safe pointer value.

---

### 3. Difference between NULL and nullptr?

NULL is typically an integer constant.

nullptr has type `std::nullptr_t` and is a dedicated null pointer value.

---

### 4. What is a Wild Pointer?

A pointer containing an unknown address because it was never initialized.

---

### 5. What is a Dangling Pointer?

A pointer that still points to memory after the object has been deleted.

---

## Intermediate

### 6. What does new do?

Allocates memory on the heap, calls the constructor, and returns the address of the object.

---

### 7. What does delete do?

Destroys the object and releases heap memory.

---

### 8. Why set a pointer to nullptr after delete?

To avoid accidentally using a dangling pointer later in the program.

---

### 9. Why use the -> operator?

Because the variable is a pointer to an object.

---

### 10. Why check

```cpp
if(ptr != nullptr)
```

before using a pointer?

To avoid dereferencing a null pointer.

---

## Advanced

### 11. What is std::nullptr_t?

The unique type of nullptr introduced in C++11.

---

### 12. Does nullptr improve overload resolution?

Yes.

It allows the compiler to choose pointer overloads correctly.

---

### 13. Why are raw pointers still taught?

Because understanding raw pointers is essential before learning Smart Pointers.

---

# Assignment

## Level 1

Create three pointers.

Initialize all using nullptr.

---

## Level 2

Allocate memory using new.

Display object information.

Delete the objects.

Set pointers to nullptr.

---

## Level 3

Modify EmployeeManager to reject nullptr values.

---

## Level 4

Create five Employee objects dynamically.

Store them inside

```cpp
std::vector<Employee*>
```

Display all.

---

## Level 5 ⭐

Create two overloaded functions

```cpp
void print(int);
void print(Employee*);
```

Call

```cpp
print(nullptr);
```

Observe which overload is selected.

---

# Summary

Today we learned

✔ nullptr

✔ nullptr_t

✔ Wild Pointer

✔ Dangling Pointer

✔ Heap Memory

✔ new

✔ delete

✔ Pointer Ownership

✔ Destructor

✔ Arrow Operator

✔ NULL vs nullptr

✔ Modern C++ Pointer Safety

---

# Phase 2 Progress

✅ Day 1 — auto Keyword

✅ Day 2 — nullptr and nullptr_t

Next

➡ Day 3 — Range-Based For Loops & Type Deduction