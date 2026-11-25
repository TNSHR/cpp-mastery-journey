# Day 18 — Inheriting Constructors

## Phase 2 — Modern C++

---

# 1. Day Objective

The objective of Day 18 is to understand **Inheriting Constructors** in modern C++.

After completing this day, you should be able to:

- Understand what an inheriting constructor is.
- Understand the syntax `using Base::Base`.
- Understand why constructors are not automatically inherited in the traditional sense.
- Understand how a derived class can make base-class constructors available.
- Understand the difference between inheriting and delegating constructors.
- Understand how inherited constructors interact with derived-class members.
- Understand how inherited constructors interact with access control.
- Understand when inherited constructors are useful.
- Understand when you should write your own derived-class constructor instead.
- Explain inheriting constructors confidently in interviews.
- Apply inheriting constructors to practical C++ designs.
- Understand their relevance to embedded C++ and hardware abstraction.

---

# 2. What Is an Inheriting Constructor?

An inheriting constructor allows a derived class to make constructors from its base class available for constructing derived-class objects.

The syntax is:

```cpp
using BaseClass::BaseClass;```

---

# 3. Why Do We Need Inheriting Constructors?

Consider a base class with several constructors:

```cpp
class Device
{
public:
    Device();
    Device(int id);
    Device(int id, const std::string& name);
};
```

Without constructor inheritance, a derived class may need forwarding constructors:

```cpp
class Sensor : public Device
{
public:
    Sensor() : Device() {}

    Sensor(int id) : Device(id) {}

    Sensor(int id, const std::string& name)
        : Device(id, name) {}
};
```

This creates repetitive code.

With inheriting constructors:

```cpp
class Sensor : public Device
{
public:
    using Device::Device;
};
```

Eligible base-class constructors become available for constructing Sensor objects.

This reduces boilerplate code.

---

# 4. Understanding `using Base::Base`

The declaration:

```cpp
using Person::Person;
```

means that the derived class makes eligible constructors from Person available.

Important points:

1. The declaration is written inside the derived class.
2. The base-class constructor initializes the base-class subobject.
3. Derived-class members are initialized separately.
4. A derived class can declare its own constructors.
5. Constructor inheritance does not bypass access control.

---

# 5. Complete Practical Example

## Header file

```cpp
#ifndef INHERITING_CONSTRUCTOR_DEMO_H
#define INHERITING_CONSTRUCTOR_DEMO_H

#include <iostream>
#include <string>

class Person
{
protected:
    std::string name;
    int age;

public:
    Person();

    Person(const std::string& personName, int personAge);

    void printPerson() const;
};

class Student : public Person
{
private:
    int rollNumber{};

public:
    using Person::Person;

    Student(
        const std::string& studentName,
        int studentAge,
        int studentRollNumber
    );

    void printStudent() const;
};

#endif
```

## Implementation file

```cpp
#include "InheritingConstructorDemo.h"

Person::Person()
    : name("Unknown"), age(0)
{
}

Person::Person(
    const std::string& personName,
    int personAge
)
    : name(personName), age(personAge)
{
}

void Person::printPerson() const
{
    std::cout << "Name: " << name << '\n';
    std::cout << "Age: " << age << '\n';
}

Student::Student(
    const std::string& studentName,
    int studentAge,
    int studentRollNumber
)
    : Person(studentName, studentAge),
      rollNumber(studentRollNumber)
{
}

void Student::printStudent() const
{
    std::cout << "Name: " << name << '\n';
    std::cout << "Age: " << age << '\n';
    std::cout << "Roll Number: " << rollNumber << '\n';
}
```

## Main file

```cpp
#include <iostream>
#include "InheritingConstructorDemo.h"

int main()
{
    Person person("Amit", 35);
    person.printPerson();

    Student student("Rahul", 20);
    student.printStudent();

    Student student2("Priya", 21, 101);
    student2.printStudent();

    return 0;
}
```

---

# 6. How Are Derived-Class Members Initialized?

Consider:

```cpp
class Student : public Person
{
private:
    int rollNumber{};

public:
    using Person::Person;
};
```

When this object is created:

```cpp
Student student("Rahul", 20);
```

The following happens:

1. The Person base-class constructor initializes name.
2. The Person base-class constructor initializes age.
3. The Student member rollNumber is initialized using its default member initializer.
4. The Student object is ready for use.

The result is:

```text
Name: Rahul
Age: 20
Roll Number: 0
```

## Why is `{}` important?

Compare:

```cpp
int rollNumber;
```

with:

```cpp
int rollNumber{};
```

For an inherited constructor that does not explicitly initialize rollNumber:

- `int rollNumber;` can leave the integer indeterminate.
- `int rollNumber{};` initializes it to zero.

Reading an indeterminate integer can cause undefined behavior.

Default member initializers are therefore useful when inheriting constructors.

---

# 7. Inherited Constructor vs Own Constructor

A derived class can use both inherited constructors and its own constructors.

```cpp
class Person
{
public:
    Person(const std::string& name, int age);
};

class Student : public Person
{
private:
    int rollNumber{};

public:
    using Person::Person;

    Student(
        const std::string& name,
        int age,
        int roll
    )
        : Person(name, age),
          rollNumber(roll)
    {
    }
};
```

Usage:

```cpp
Student s1("Rahul", 20);
Student s2("Priya", 21, 101);
```

The first object uses an inherited constructor.

The second object uses the constructor declared directly in Student.

---

# 8. Inheriting Constructors vs Delegating Constructors

These concepts are different.

## Inheriting constructors

Makes eligible constructors from a base class available in a derived class.

```cpp
class Student : public Person
{
public:
    using Person::Person;
};
```

## Delegating constructors

One constructor in the same class calls another constructor in that class.

```cpp
class Device
{
private:
    int id;
    std::string name;

public:
    Device(int deviceId, const std::string& deviceName)
        : id(deviceId), name(deviceName)
    {
    }

    Device(int deviceId)
        : Device(deviceId, "Unknown")
    {
    }
};
```

The one-argument constructor delegates to the two-argument constructor.

Remember:

- Inheriting constructors involve a base class.
- Delegating constructors involve another constructor of the same class.

---

# 9. Constructor Overloading and Access Control

When constructors are inherited, normal overload resolution rules help select the best matching constructor.

Example:

```cpp
class Base
{
public:
    Base(int id);
    Base(int id, const std::string& name);
};

class Derived : public Base
{
public:
    using Base::Base;
};
```

Usage:

```cpp
Derived d1(10);
Derived d2(10, "Sensor");
```

The argument list determines which eligible constructor is selected.

Access control also matters.

A constructor that is inaccessible in the base class does not become publicly accessible merely because a derived class writes a public using-declaration.

The accessibility of inherited constructors must be considered when using them.

---

# 10. Important Rules to Remember

1. Constructor inheritance was introduced in C++11.
2. Use `using Base::Base` inside a derived class.
3. Inherited constructors initialize the base-class subobject.
4. Derived-class members still need initialization.
5. Default member initializers are applied when appropriate.
6. Derived classes can declare their own constructors.
7. Constructor overload resolution selects a suitable constructor.
8. Access control still applies.
9. Inheriting constructors do not replace normal copy and move constructor rules.
10. Use constructor inheritance when it makes the class interface simpler and clearer.

---

# 11. Practical Applications in Embedded C++

In embedded software, we often create related hardware abstraction classes.

Example:

```cpp
#include <string>

class Peripheral
{
protected:
    int deviceId;

public:
    explicit Peripheral(int id)
        : deviceId(id)
    {
    }
};

class Sensor : public Peripheral
{
public:
    using Peripheral::Peripheral;

    void readSensor()
    {
        // Sensor-specific implementation
    }
};
```

Usage:

```cpp
Sensor temperatureSensor(101);
Sensor pressureSensor(102);
```

Both objects use the inherited Peripheral constructor to initialize their device IDs.

This is a simplified educational example. Real hardware drivers may require additional initialization, configuration and resource management.

---

# 12. Common Mistakes

## Mistake 1: Forgetting the using declaration

```cpp
class Student : public Person
{
};
```

This does not automatically inherit all Person constructors.

## Mistake 2: Forgetting derived-class members

```cpp
class Student : public Person
{
    int rollNumber;
public:
    using Person::Person;
};
```

An inherited constructor does not automatically assign a meaningful roll number.

Use a default member initializer or an appropriate derived-class constructor.

## Mistake 3: Confusing inheriting and delegating constructors

They solve different problems.

## Mistake 4: Assuming every base constructor is usable

Constructor accessibility, overload resolution and special member function rules still apply.

---

# 13. Interview Questions

## Beginner

**Q1. What is an inheriting constructor?**

It allows a derived class to make eligible base-class constructors available using a using-declaration.

**Q2. What is the syntax?**

```cpp
using Base::Base;
```

**Q3. Which C++ standard introduced inheriting constructors?**

C++11.

## Intermediate

**Q4. Why do we use inheriting constructors?**

To reduce repetitive forwarding constructors and reuse base-class construction interfaces.

**Q5. Are derived-class data members initialized by an inherited constructor?**

They are initialized according to their applicable default member initializers or other initialization rules. They are not automatically assigned meaningful values by the base constructor.

**Q6. Can a derived class have its own constructor and inherit base constructors?**

Yes.

**Q7. What is the difference between inheriting and delegating constructors?**

Inheriting constructors make base-class constructors available. Delegating constructors call another constructor in the same class.

## Advanced

**Q8. Does inheriting a constructor bypass access control?**

No. Access restrictions still apply.

**Q9. Does constructor inheritance mean the derived class becomes a copy of the base class?**

No. It only makes eligible constructors available for constructing derived objects.

**Q10. When should you avoid inheriting constructors?**

When the derived class needs substantially different initialization, validation, resource management or construction semantics.

---

# 14. Day 18 Practice Exercises

## Exercise 1 — Basic

Create a class Animal with:

- A name member.
- A parameterized constructor.
- A display function.

Create a derived class Dog and inherit the Animal constructor.

Create a Dog object and print its name.

## Exercise 2 — Intermediate

Create:

- Base class Employee with name and salary.
- Derived class Manager with a department member.
- Inherit Employee constructors.
- Initialize department using a default member initializer.
- Add a custom Manager constructor that accepts all three values.

## Exercise 3 — Advanced

Create a base class Device with multiple constructors.

Create derived classes:

- TemperatureSensor
- PressureSensor
- HumiditySensor

Use inherited constructors where appropriate.

Add derived-class-specific members and ensure they are initialized safely.

## Exercise 4 — Embedded Application

Design a simplified hardware abstraction:

- Base class Peripheral.
- Derived class GPIO.
- Derived class UART.
- Inherit suitable constructors.
- Add peripheral-specific configuration members.
- Explain which initialization belongs to the base class and which belongs to the derived class.

---

# 15. Day 18 Completion Checklist

- [ ] Understand inheriting constructors.
- [ ] Understand `using Base::Base`.
- [ ] Understand base and derived initialization.
- [ ] Understand default member initializers.
- [ ] Understand constructor overloading.
- [ ] Understand access control.
- [ ] Understand inheriting vs delegating constructors.
- [ ] Complete all four exercises.
- [ ] Explain the topic without looking at notes.
- [ ] Compile and run the practical example.

---

# 16. Day 18 Summary

Inheriting constructors provide a convenient way for a derived class to reuse eligible constructors from its base class.

The key syntax is:

```cpp
using Base::Base;
```

However, inheriting constructors does not remove the responsibility of initializing derived-class members.

A good C++ programmer understands both constructor reuse and safe object initialization.

**Day 18 Topic: Inheriting Constructors — Completed.**
```
