# Day 16 - Virtual Functions, vtable, vptr & Abstract Classes

# Objective

Today we will understand how Runtime Polymorphism actually works inside C++.

Topics Covered

- Virtual Function
- Runtime Polymorphism
- Static Binding
- Dynamic Binding
- vtable
- vptr
- Pure Virtual Function
- Abstract Class
- Virtual Destructor

---------------------------------------------------------

# Why was Virtual Function introduced?

Suppose we have

Animal

↓

Dog

↓

Cat

Every animal makes a sound.

Animal

↓

sound()

Dog

↓

Bark

Cat

↓

Meow

Now suppose

```cpp
Animal* animal;

Dog dog;

animal = &dog;
```

Question

When we call

```cpp
animal->sound();
```

Which function should execute?

Animal::sound()

or

Dog::sound()

The object is Dog.

So Dog::sound() should execute.

But the pointer type is Animal.

Without virtual, C++ executes

Animal::sound()

This is incorrect.

To solve this problem C++ introduced

Virtual Functions.

---------------------------------------------------------

# What is a Virtual Function?

A Virtual Function is a member function declared using the keyword

virtual

Example

```cpp
class Animal
{
public:

    virtual void sound();

};
```

When a function is virtual,

C++ decides which function to execute during Runtime instead of Compile Time.

---------------------------------------------------------

# Without Virtual

```cpp
Animal* animal;

Dog dog;

animal=&dog;

animal->sound();
```

Output

Animal Sound

Reason

Compiler only checks

Animal*

Compiler ignores the actual object.

This is called

Static Binding.

---------------------------------------------------------

# With Virtual

```cpp
Animal* animal;

Dog dog;

animal=&dog;

animal->sound();
```

Output

Dog Bark

Reason

Runtime checks

The actual object.

Object = Dog

Therefore

Dog::sound()

is executed.

This is called

Dynamic Binding.

---------------------------------------------------------

# Static Binding

Definition

The compiler decides which function to call during compilation.

Characteristics

✔ Faster

✔ No Runtime Checking

✔ No Runtime Polymorphism

Examples

Function Overloading

Normal Member Functions

---------------------------------------------------------

# Dynamic Binding

Definition

The program decides which function to execute during Runtime.

Characteristics

✔ Supports Runtime Polymorphism

✔ Uses Virtual Functions

✔ Slightly slower than Static Binding

---------------------------------------------------------

# What is vtable?

Question

How does Runtime know where

Dog::sound()

is stored?

Answer

The compiler creates a hidden table called

Virtual Table

or

vtable.

A vtable stores the addresses of all virtual functions of a class.

Example

Dog vtable

-----------------------------------

sound()

↓

Address 1000

eat()

↓

Address 1500

run()

↓

Address 3000

-----------------------------------

Think of vtable as a Contact List.

Suppose you want to call Rahul.

You don't remember Rahul's phone number.

You open your Contact List.

Search Rahul.

Call Rahul.

Exactly the same happens here.

Instead of phone numbers,

the vtable stores

Function Addresses.

---------------------------------------------------------

# What is vptr?

Question

How does each Dog object know which vtable belongs to it?

Compiler secretly adds one hidden pointer.

Called

Virtual Pointer

or

vptr.

Every object of a class containing virtual functions gets one hidden vptr.

Example

Dog Object

---------------------------------

vptr

name

age

weight

---------------------------------

The vptr stores

Address of Dog vtable.

---------------------------------------------------------

# How Runtime Polymorphism Works

Suppose

```cpp
Animal* animal;

Dog dog;

animal=&dog;

animal->sound();
```

Step 1

animal points to Dog Object

↓

Step 2

Compiler finds

Dog Object

↓

vptr

↓

Step 3

vptr points to

Dog vtable

↓

Step 4

vtable contains

Dog::sound()

↓

Step 5

Dog::sound()

executes.

Memory Flow

Animal Pointer

↓

Dog Object

↓

vptr

↓

Dog vtable

↓

Dog::sound()

↓

Output

Dog Bark

---------------------------------------------------------

# Why is only one vtable created?

Suppose

```cpp
Dog d1;

Dog d2;

Dog d3;

Dog d4;
```

Should compiler create

4 vtables?

No.

All Dogs behave the same.

Therefore

Compiler creates

ONE Dog vtable.

Every Dog object has its own

vptr

pointing to the same Dog vtable.

This saves memory.

---------------------------------------------------------

# What is a Pure Virtual Function?

Sometimes

Base class should NOT provide implementation.

Instead

It only tells derived classes

"You MUST implement this function."

Syntax

```cpp
virtual void sound() = 0;
```

Notice

= 0

means

"No implementation."

"Derived class must implement."

---------------------------------------------------------

# What is an Abstract Class?

A class containing at least one Pure Virtual Function is called an

Abstract Class.

Example

```cpp
class Animal
{
public:

    virtual void sound() = 0;

};
```

Cannot create object

❌

```cpp
Animal animal;
```

Allowed

✔

```cpp
Dog dog;
```

---------------------------------------------------------

# Why do we need Abstract Classes?

Suppose we have

Payment

↓

UPI

Credit Card

Debit Card

Can Payment itself perform payment?

No.

Only

UPI

Credit Card

Debit Card

know how to pay.

Therefore

Payment should only define

pay()

It should NOT implement

pay()

This is exactly what an Abstract Class does.

---------------------------------------------------------

# Difference Between Virtual Function and Pure Virtual Function

Virtual Function

✔ Has implementation

✔ Child may override

✔ Base object can be created

Example

```cpp
virtual void sound()
{
    cout<<"Animal";
}
```

Pure Virtual Function

✔ No implementation

✔ Child MUST override

✔ Base object cannot be created

Example

```cpp
virtual void sound() = 0;
```

---------------------------------------------------------

# Why Virtual Destructor?

Suppose

```cpp
Animal* animal = new Dog;

delete animal;
```

If destructor is NOT virtual

Only

Animal Destructor

executes.

Dog Destructor

does not execute.

Resources allocated by Dog may leak.

Correct

```cpp
virtual ~Animal();
```

Now

delete animal;

calls

Dog Destructor

↓

Animal Destructor

This ensures proper cleanup.

---------------------------------------------------------

# Advantages of Virtual Functions

✔ Runtime Polymorphism

✔ Flexible Design

✔ Easy Maintenance

✔ Extensible Code

✔ Code Reusability

---------------------------------------------------------

# Disadvantages

❌ Slight Runtime Overhead

❌ Every object stores one hidden vptr

❌ Virtual lookup is slightly slower than normal function calls

---------------------------------------------------------

# Common Mistakes

Mistake 1

Forgetting virtual

Wrong

```cpp
void sound();
```

Correct

```cpp
virtual void sound();
```

-----------------------------------

Mistake 2

Wrong Function Signature

Base

```cpp
virtual void sound();
```

Derived

```cpp
void sound(int);
```

This is NOT overriding.

Always use

override

-----------------------------------

Mistake 3

Creating object of Abstract Class

Wrong

```cpp
Animal animal;
```

Correct

```cpp
Dog dog;
```

---------------------------------------------------------

# Interview Questions

## 1. What is Runtime Polymorphism?

Runtime Polymorphism allows the program to decide which overridden function should execute during Runtime.

---------------------------------------------------------

## 2. What is a Virtual Function?

A function declared using the keyword virtual. It enables Runtime Polymorphism.

---------------------------------------------------------

## 3. What is Static Binding?

Compile-time function selection.

---------------------------------------------------------

## 4. What is Dynamic Binding?

Runtime function selection using Virtual Functions.

---------------------------------------------------------

## 5. What is a vtable?

A compiler-generated table that stores addresses of virtual functions.

---------------------------------------------------------

## 6. What is a vptr?

A hidden pointer added by the compiler to every object containing virtual functions. It points to the class's vtable.

---------------------------------------------------------

## 7. Why does every object have a vptr?

Each object needs to know which class's vtable it should use for runtime dispatch.

---------------------------------------------------------

## 8. Why is there only one vtable per class?

All objects of the same class share the same virtual function implementations, so one shared vtable saves memory.

---------------------------------------------------------

## 9. What is an Abstract Class?

A class containing at least one Pure Virtual Function. Objects of an Abstract Class cannot be created.

---------------------------------------------------------

## 10. What is a Pure Virtual Function?

A virtual function declared using

= 0

that must be implemented by derived classes.

---------------------------------------------------------

## 11. Why do we use Virtual Destructor?

To ensure both derived and base destructors execute correctly when deleting an object through a base class pointer.

---------------------------------------------------------

# Revision

Virtual Function

↓

Runtime decides function.

vtable

↓

Stores addresses of virtual functions.

vptr

↓

Hidden pointer inside every object with virtual functions.

Runtime Flow

Pointer

↓

Object

↓

vptr

↓

vtable

↓

Correct Function

Pure Virtual Function

↓

No implementation.

Abstract Class

↓

Cannot create objects.

Virtual Destructor

↓

Proper object destruction.

---------------------------------------------------------

# Real World Usage

Virtual Functions are heavily used in:

- Qt Framework (QWidget, QObject)
- Unreal Engine
- ROS2
- Embedded Driver Interfaces
- Game Engines
- GUI Applications
- Plugin Systems
- Device Drivers
- Payment Gateways
- CAD Software

These frameworks rely on Runtime Polymorphism to make software flexible and extensible.