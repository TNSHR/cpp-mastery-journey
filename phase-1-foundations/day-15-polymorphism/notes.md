# Day 15 - Polymorphism (Part 1)

# Objective

Learn one of the four pillars of Object-Oriented Programming (OOP): Polymorphism.

Topics Covered

- Function Overriding
- Virtual Functions
- Runtime Polymorphism
- Compile-Time vs Runtime Polymorphism
- Base Pointer
- Derived Object
- Dynamic Binding
- Static Binding

--------------------------------------------

# What is Polymorphism?

Polymorphism means

"One Interface, Many Forms."

The same function behaves differently depending on the object calling it.

Example

Animal

↓

Dog

↓

Cat

All have

sound()

Dog

↓

Bark

Cat

↓

Meow

Same function

Different implementation.

--------------------------------------------

# Types of Polymorphism

1. Compile-Time Polymorphism

Achieved using

- Function Overloading
- Operator Overloading

Compiler decides which function to execute.

--------------------------------------------

2. Runtime Polymorphism

Achieved using

- Function Overriding
- Virtual Functions

Decision is made while the program is running.

--------------------------------------------

# Function Overriding

A derived class provides its own implementation of a function already defined in the base class.

Example

class Animal
{
public:
    virtual void sound();
};

class Dog : public Animal
{
public:
    void sound() override;
};

--------------------------------------------

# Virtual Function

A virtual function allows C++ to decide at runtime which function should be called.

Syntax

virtual void sound();

Without virtual

Animal Pointer

↓

Dog Object

↓

Animal::sound()

With virtual

Animal Pointer

↓

Dog Object

↓

Dog::sound()

--------------------------------------------

# Static Binding

Compiler decides the function.

Decision made during compilation.

Fast

Cannot achieve runtime polymorphism.

--------------------------------------------

# Dynamic Binding

Runtime decides the function.

Requires

virtual

Supports Runtime Polymorphism.

--------------------------------------------

# override Keyword

Example

void sound() override;

Benefits

- Compiler checks correctness.
- Prevents accidental mistakes.
- Improves readability.

--------------------------------------------

# Base Pointer

Example

Animal* animal;

The pointer can point to

Animal

Dog

Cat

Cow

Any derived object.

--------------------------------------------

# Why Base Pointer?

One pointer

↓

Many Objects

Allows Runtime Polymorphism.

--------------------------------------------

# Advantages

✔ Flexible Design

✔ Code Reuse

✔ Easy Extension

✔ Runtime Decision

✔ Cleaner Code

✔ Better Maintainability

--------------------------------------------

# Common Mistakes

Forgetting virtual

Wrong

void sound();

Correct

virtual void sound();

--------------------------------------------

Wrong function signature

Base

void sound();

Derived

void sound(int);

This is not overriding.

--------------------------------------------

Forgetting override keyword

Always use

override

Compiler catches mistakes.

--------------------------------------------

# Key Points

Polymorphism

↓

Many Forms

Compile Time

↓

Overloading

Runtime

↓

Overriding

Virtual

↓

Dynamic Binding

--------------------------------------------

# Interview Questions

## 1. What is Polymorphism?

Polymorphism is an OOP feature where one interface can have multiple implementations.

--------------------------------------------

## 2. What are the types of Polymorphism?

Compile-Time

Runtime

--------------------------------------------

## 3. What is Function Overriding?

Derived class provides its own implementation of a base class function.

--------------------------------------------

## 4. What is a Virtual Function?

A function declared with virtual that enables runtime polymorphism.

--------------------------------------------

## 5. What is Dynamic Binding?

Selecting the correct function during program execution.

--------------------------------------------

## 6. What is Static Binding?

Selecting the function during compilation.

--------------------------------------------

## 7. Why do we use override?

To let the compiler verify that a derived class correctly overrides a virtual function.

--------------------------------------------

## 8. What is the difference between Overloading and Overriding?

Overloading

Same class

Different parameters

Compile Time

Overriding

Different classes

Same signature

Runtime

--------------------------------------------

## 9. Why should base classes have virtual destructors?

To ensure the derived class destructor is called when deleting an object through a base class pointer.

--------------------------------------------

## 10. What is Runtime Polymorphism?

Calling the correct overridden function based on the actual object type at runtime.

--------------------------------------------

# Next Day

Virtual Table (vtable)

Virtual Pointer (vptr)

Abstract Classes

Pure Virtual Functions

Interfaces