# Day 18 – Exception Handling

Author: Shrinath Sharma

---

# Objective

By the end of this lesson you should understand:

- Why Exception Handling exists
- Problems with traditional error handling
- try
- throw
- catch
- Standard Exception Classes
- Custom Exceptions
- Stack Unwinding
- RAII and Exceptions
- Best Practices
- Common Mistakes
- Industry Usage

---

# What is Exception Handling?

Exception Handling is a mechanism that allows a program to detect, report, and handle runtime errors without crashing.

Instead of returning special error values, a function throws an exception object.

The caller can catch the exception and decide how to recover.

---

# Why Was Exception Handling Introduced?

Before exceptions, programmers usually returned error codes.

Example

```cpp
int divide(int a,int b)
{
    if(b==0)
        return -1;

    return a/b;
}
```

Problem

If the correct answer is -1, we cannot distinguish between

- Actual Result
- Error

This makes programs unreliable.

Exception Handling solves this problem.

---

# Real World Example

Imagine an ATM.

Customer requests ₹10,000.

Machine checks account.

If the balance is insufficient, the ATM does not display a fake balance.

Instead, it shows

"Insufficient Balance"

This is similar to throwing an exception.

---

# Three Keywords

## try

Contains code that may generate an exception.

Example

```cpp
try
{
    // risky code
}
```

---

## throw

Used to create and send an exception object.

Example

```cpp
throw std::runtime_error("Division by zero");
```

The current function immediately stops executing.

---

## catch

Receives and handles the exception.

Example

```cpp
catch(const std::exception &e)
{
    std::cout << e.what();
}
```

---

# Exception Flow

Problem Occurs

↓

throw

↓

Current Function Ends

↓

Search for Matching catch

↓

Execute catch Block

↓

Program Continues

---

# Standard Exception Classes

The C++ Standard Library provides several exception classes.

Some commonly used ones are

- std::exception
- std::runtime_error
- std::logic_error
- std::invalid_argument
- std::out_of_range
- std::overflow_error
- std::underflow_error
- std::bad_alloc

---

# Why runtime_error?

runtime_error represents errors that occur while the program is running.

Examples

- Divide by zero
- File not found
- Network failure
- Database unavailable

---

# The what() Function

Every standard exception provides

```cpp
what()
```

It returns a descriptive error message.

Example

```cpp
catch(const std::exception &e)
{
    std::cout << e.what();
}
```

Output

```
Division by zero is not allowed.
```

---

# Compiler vs Runtime

Compiler Detects

- Missing semicolon
- Wrong datatype
- Undefined variable
- Syntax errors

Runtime Detects

- Divide by zero
- File missing
- Network disconnected
- Memory allocation failure

Exception Handling deals only with runtime errors.

---

# What Happens During throw?

Suppose

```cpp
throw std::runtime_error("Error");
```

Compiler creates an exception object.

The current function immediately stops.

Execution jumps to the nearest matching catch block.

Code below throw never executes.

Example

```cpp
throw std::runtime_error("Error");

std::cout<<"Hello";
```

"Hello" is never printed.

---

# Stack Unwinding

One of the most important interview topics.

When an exception is thrown,

every function currently on the call stack is destroyed one by one until a matching catch block is found.

Example

```
main()

↓

functionA()

↓

functionB()

↓

functionC()

↓

throw
```

Compiler destroys

```
functionC

↓

functionB

↓

functionA

↓

catch
```

This automatic cleanup is called

Stack Unwinding.

---

# RAII (Resource Acquisition Is Initialization)

Modern C++ uses RAII.

Objects clean themselves automatically when leaving scope.

Because of stack unwinding,

destructors are automatically called.

Example

```cpp
class File
{
public:

    File()
    {
        std::cout<<"Opened\n";
    }

    ~File()
    {
        std::cout<<"Closed\n";
    }
};
```

If an exception occurs,

the destructor still executes.

This prevents

- Memory leaks
- Open files
- Locked resources

RAII is one of the biggest strengths of Modern C++.

---

# Custom Exceptions

Sometimes standard exceptions are not enough.

Example

```cpp
class InvalidAgeException
{
};
```

Used for

- Invalid Age
- Invalid Marks
- Invalid Salary
- Invalid Sensor Data

Applications often create their own exception classes.

---

# Exception Hierarchy

```
std::exception

│

├── logic_error

│      ├── invalid_argument

│      └── out_of_range

│

├── runtime_error

│      ├── overflow_error

│      ├── underflow_error

│      └── range_error

│

└── bad_alloc
```

---

# Multiple catch Blocks

Different exceptions can be handled differently.

Example

```cpp
try
{
}

catch(const std::invalid_argument &e)
{
}

catch(const std::runtime_error &e)
{
}

catch(const std::exception &e)
{
}
```

Always keep the most general exception (std::exception) last.

---

# Best Practices

✔ Throw objects, not primitive values.

Good

```cpp
throw std::runtime_error("Invalid");
```

Bad

```cpp
throw 10;
```

---

✔ Catch by const reference.

Good

```cpp
catch(const std::exception &e)
```

---

✔ Keep try blocks as small as possible.

---

✔ Use exceptions only for exceptional situations.

---

✔ Prefer standard exceptions whenever possible.

---

✔ Design classes using RAII.

---

# Common Mistakes

❌ Returning error codes everywhere.

❌ Throwing primitive datatypes.

❌ Catching exceptions by value.

❌ Ignoring exceptions.

❌ Catching every exception without proper handling.

❌ Using exceptions for normal program flow.

---

# Advantages

- Cleaner code
- Centralized error handling
- Automatic stack unwinding
- Prevents crashes
- Works well with RAII
- Easy recovery from runtime errors

---

# Disadvantages

- Slight runtime overhead
- Harder debugging if overused
- Misuse can reduce readability

---

# Industry Usage

Exception Handling is widely used in

- Qt
- STL
- Boost
- Database Drivers
- File Systems
- Networking Libraries
- Financial Applications
- Embedded Linux Applications

Some microcontroller firmware avoids exceptions due to memory and code-size constraints, but desktop, server, and application software commonly uses them.

---

# Memory Flow

```
main()

↓

try

↓

Calculator::divide()

↓

b==0 ?

↓

YES

↓

throw runtime_error

↓

Current Function Ends

↓

Stack Unwinding

↓

catch

↓

Print Error

↓

Program Continues
```

---

# Keywords to Remember

- try
- throw
- catch
- runtime_error
- exception
- what()
- Stack Unwinding
- RAII
- Destructor
- Custom Exception

---

# Interview Questions

### Q1 What is Exception Handling?

A mechanism used to handle runtime errors without crashing the program.

---

### Q2 Difference between compile-time error and runtime error?

Compile-time errors are detected by the compiler.

Runtime errors occur while executing the program.

---

### Q3 What happens after throw?

Current function immediately terminates.

Compiler starts stack unwinding.

Nearest matching catch block executes.

---

### Q4 Why catch exceptions using const reference?

Avoid copying the exception object and prevent modification.

---

### Q5 What does what() return?

A descriptive error message stored inside the exception.

---

### Q6 What is Stack Unwinding?

Automatic destruction of stack objects while searching for a matching catch block.

---

### Q7 What is RAII?

A design principle where resources are acquired during object construction and released automatically in the destructor.

---

### Q8 Name five standard exceptions.

- runtime_error
- logic_error
- invalid_argument
- out_of_range
- bad_alloc

---

### Q9 Why should std::exception usually be the last catch block?

Because it is the base class for most standard exceptions. Placing it first would prevent more specific catch blocks from being reached.

---

### Q10 Why should exceptions not be used for normal program logic?

Exceptions are intended for unexpected or exceptional conditions. Using them for regular control flow reduces readability and may introduce unnecessary overhead.

---

# Assignment

Level 1

Create a divide() function that throws runtime_error on divide-by-zero.

---

Level 2

Create a calculator supporting

- Addition
- Subtraction
- Multiplication
- Division

Throw exceptions where appropriate.

---

Level 3

Create an InvalidAgeException class.

Throw it when age < 18.

---

Level 4

Create a BankAccount class.

Throw exceptions for

- Negative Withdrawal
- Insufficient Balance

---

Level 5 (Challenge)

Create a FileManager class using RAII.

Ensure the destructor always closes the file, even when an exception occurs.

---

# Revision Summary

Exception Handling

↓

Runtime Error Management

↓

try

↓

throw

↓

catch

↓

Stack Unwinding

↓

RAII

↓

Automatic Resource Cleanup

↓

Reliable Software

---

# Conclusion

Exception Handling is one of the most important features of Modern C++. It separates normal program logic from error handling, provides safer and more maintainable code, and works seamlessly with RAII to automatically clean up resources during failures.

Understanding Exception Handling is essential for writing production-quality C++ applications and is a common topic in software engineering interviews.