# Phase 2 - Day 5
# Smart Pointers (std::unique_ptr)

---

# Objective

Learn Modern C++ memory management using `std::unique_ptr`.

Understand

- Why raw pointers are dangerous
- Memory leaks
- RAII
- std::unique_ptr
- Ownership
- std::move()
- Automatic destruction
- Best practices
- Interview Questions

---

# Why were Smart Pointers introduced?

Old C++

```cpp
Employee* employee = new Employee(
101,
"Shrinath",
50000
);
```

Memory

```
Stack

employee

↓

Heap

Employee
```

Later

```cpp
return;
```

Oops...

Forgot

```cpp
delete employee;
```

Memory

```
Heap

Employee

↓

Never Deleted

↓

Memory Leak
```

---

# What is a Memory Leak?

A memory leak occurs when dynamically allocated memory is never released.

Example

```cpp
Employee* employee = new Employee();

// forgot delete
```

Program

↓

Ends

↓

Memory Lost

---

# Problems with Raw Pointers

- Manual delete required
- Memory leaks
- Double delete
- Dangling pointers
- Exception unsafe

Example

```cpp
Employee* employee = new Employee();

throw exception();

// delete never executed
```

Memory leak.

---

# The Modern Solution

```cpp
auto employee =
std::make_unique<Employee>(
101,
"Shrinath",
50000
);
```

No

```cpp
delete
```

required.

Automatic cleanup.

---

# What is RAII?

RAII means

**Resource Acquisition Is Initialization**

Meaning

When an object acquires a resource

↓

Constructor

When object dies

↓

Destructor

↓

Resource released automatically.

---

# RAII Example

```cpp
{
    auto employee =
    std::make_unique<Employee>();
}
```

Leaving scope

↓

unique_ptr Destructor

↓

delete Employee

↓

Employee Destructor

↓

Memory Freed

---

# What is unique_ptr?

A smart pointer

that owns exactly

ONE object.

Memory

```
Stack

unique_ptr

↓

Heap

Employee
```

Only

one owner

exists.

---

# Why Only One Owner?

Suppose

```cpp
employee1

↓

Employee
```

Copy

```cpp
employee2 = employee1;
```

Now

```
employee1

↓

Employee

employee2

↓

Employee
```

Program ends

↓

delete

↓

delete

↓

Crash

Therefore

Compiler

forbids copying.

---

# std::move()

Instead

ownership transfers.

```cpp
manager.addEmployee(

std::move(employee)

);
```

Memory

Before

```
employee

↓

Employee
```

After

```
employee

↓

nullptr

Manager

↓

Employee
```

Ownership moved.

Employee

did NOT move.

---

# Does std::move() Move Memory?

No.

This is one of the biggest interview questions.

std::move()

does NOT move

the object.

It only converts an object into an rvalue, allowing ownership to be transferred.

---

# Compiler's View

Suppose

```cpp
auto employee =
std::make_unique<Employee>();
```

Compiler conceptually creates

```
unique_ptr

↓

Employee

↓

Destructor

↓

delete
```

Automatic.

---

# make_unique()

Instead of

```cpp
new Employee(...)
```

Modern C++

uses

```cpp
std::make_unique<Employee>(...)
```

Advantages

✔ Exception safe

✔ Cleaner

✔ Faster to write

✔ Recommended

---

# get()

Example

```cpp
Employee* employee =
smartPointer.get();
```

Returns

raw pointer.

Ownership

does NOT change.

---

# release()

Example

```cpp
Employee* employee =
smartPointer.release();
```

Ownership released.

Now

YOU

must

call

```cpp
delete
```

Rarely used.

---

# reset()

```cpp
smartPointer.reset();
```

Immediately

destroys

current object.

Memory freed.

---

# swap()

```cpp
ptr1.swap(ptr2);
```

Ownership exchanged.

---

# Comparison

Raw Pointer

```
Employee*
```

Manual

delete.

---

unique_ptr

```
std::unique_ptr<Employee>
```

Automatic.

---

# Memory Flow

```
make_unique()

↓

Heap Allocation

↓

unique_ptr Owns

↓

Program Uses Object

↓

Scope Ends

↓

unique_ptr Destructor

↓

Employee Destructor

↓

delete

↓

Memory Freed
```

---

# Real World Analogy

Imagine

A Car.

Old C++

```
Borrow Car

↓

Forget Keys

↓

Nobody Responsible
```

Modern C++

```
Borrow Car

↓

Return Keys Automatically

↓

Safe
```

---

# Best Practices

✔ Always prefer

```cpp
make_unique()
```

✔ Avoid

```cpp
new
```

✔ Never manually

```cpp
delete
```

when using

unique_ptr.

✔ Transfer ownership using

```cpp
std::move()
```

✔ Keep ownership clear.

---

# Common Mistakes

❌ Copying unique_ptr.

```cpp
ptr2 = ptr1;
```

Compiler Error.

---

❌ Using moved pointer.

```cpp
std::move(ptr);

ptr->display();
```

Wrong.

Check

```cpp
if(ptr)
```

first.

---

❌ Calling delete

after using

unique_ptr.

Never.

---

# Interview Questions

## Beginner

### 1. What is a Smart Pointer?

A class that manages dynamically allocated memory automatically.

---

### 2. What is unique_ptr?

A smart pointer with exclusive ownership.

---

### 3. Why use make_unique()?

It is safer, cleaner, and exception-safe compared to using `new`.

---

### 4. Can unique_ptr be copied?

No.

---

### 5. Why?

Because only one owner is allowed.

---

## Intermediate

### 6. What does std::move() do?

It transfers ownership by converting an object into an rvalue.

---

### 7. Does std::move() move memory?

No.

It transfers ownership only.

---

### 8. What happens after std::move()?

The source unique_ptr becomes empty (`nullptr`).

---

### 9. What does get() return?

The raw pointer without transferring ownership.

---

### 10. What is release()?

Releases ownership and returns the raw pointer. The caller becomes responsible for deleting it.

---

### 11. What is reset()?

Deletes the current object and optionally takes ownership of another.

---

## Advanced

### 12. Explain RAII.

Tie the lifetime of resources to the lifetime of objects. Constructors acquire resources; destructors release them automatically.

---

### 13. Why are Smart Pointers exception-safe?

Because destructors run automatically during stack unwinding when exceptions occur.

---

### 14. Why are raw pointers still used?

For non-owning access, interoperability with legacy APIs, or observing objects without owning them.

---

### 15. Difference between ownership and access?

Ownership controls object lifetime.

Access only allows using the object.

---

### 16. Why does unique_ptr delete its copy constructor?

To prevent multiple owners and double deletion.

---

### 17. Where is unique_ptr commonly used?

- Qt
- ROS2
- LLVM
- Chromium
- Unreal Engine
- Embedded Linux
- Modern C++ applications

---

# Assignment

## Level 1

Create one unique_ptr.

Display object.

---

## Level 2

Transfer ownership using

```cpp
std::move()
```

---

## Level 3

Verify

```cpp
ptr == nullptr
```

after move.

---

## Level 4

Create vector of unique_ptr.

Store five Employees.

Display all.

---

## Level 5

Search Employee.

---

## Level 6

Observe destructor order.

---

## Level 7 ⭐

Try copying

```cpp
unique_ptr
```

Observe compiler error.

Understand why copying is prohibited.

---

# Summary

Today we learned

✔ Memory Leaks

✔ RAII

✔ unique_ptr

✔ Ownership

✔ make_unique()

✔ std::move()

✔ get()

✔ release()

✔ reset()

✔ Automatic Cleanup

✔ Interview Questions

---

# Phase 2 Progress

✅ Day 1 — auto

✅ Day 2 — nullptr

✅ Day 3 — Range-Based For Loops

✅ Day 4 — Lambda Expressions

✅ Day 5 — Smart Pointers (unique_ptr)

Next

➡ Day 6 — std::shared_ptr