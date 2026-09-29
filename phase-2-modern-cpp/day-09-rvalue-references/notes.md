# Day 09 — Rvalue References (`&&`)
## Phase 2 — Modern C++
### C++ Mastery Journey

---

## 1. Day Objective

By the end of Day 09, you should be able to:

- Explain what an lvalue and rvalue are.
- Understand why C++11 introduced rvalue references.
- Declare and use `T&&`.
- Understand the difference between `T&` and `T&&`.
- Understand how rvalue references enable move semantics.
- Explain how temporary objects bind to rvalue references.
- Understand named rvalue references and why they behave as lvalues inside a function.
- Understand `std::move` at a conceptual level.
- Explain the relationship between rvalue references and move constructors.
- Answer common interview questions about `&&`.

---

# 2. What Is an Lvalue?

An lvalue is an expression that generally represents an object with an identifiable location in memory.

Example:

```cpp
int x = 10;

x = 20;
```

Here `x` is an lvalue because it represents a persistent object that can be referred to.

Another example:

```cpp
int a = 10;
int b = a;
```

`a` is an lvalue.

A useful mental model:

> lvalue = an object that has an identifiable identity/location.

---

# 3. What Is an Rvalue?

An rvalue is generally a temporary value or an expression whose result is not treated as a persistent named object.

Example:

```cpp
int x = 10;
```

The literal `10` is an rvalue.

Example:

```cpp
int result = x + 5;
```

`x + 5` produces a temporary result, so it is an rvalue.

Other examples:

```cpp
42
x + y
std::string("hello")
createObject()
```

The exact modern C++ value-category rules are more detailed than simply "temporary = rvalue", but this model is very useful initially.

---

# 4. Why Do We Need Rvalue References?

Before C++11, C++ primarily used ordinary references:

```cpp
int& ref = x;
```

An ordinary reference (`T&`) normally binds to an lvalue.

But consider a temporary:

```cpp
int&& ref = 100;
```

The `&&` reference can bind to an rvalue.

This gives C++ a way to distinguish:

```text
I am receiving a persistent object
        versus
I am receiving a temporary object that can be reused/moved from
```

That distinction is extremely important for performance.

---

# 5. Basic Syntax

```cpp
T&& reference_name = rvalue;
```

Example:

```cpp
int&& r = 100;
```

Here:

- `int` → type
- `&&` → rvalue reference
- `r` → reference name
- `100` → rvalue

Another example:

```cpp
std::string&& name = std::string("Shrinath");
```

The temporary string can bind to the rvalue reference.

---

# 6. `T&` vs `T&&`

Consider:

```cpp
int x = 10;

int& a = x;
int&& b = 20;
```

Conceptually:

```text
int&  → lvalue reference
int&& → rvalue reference
```

Comparison:

| Feature | `T&` | `T&&` |
|---|---|---|
| Commonly binds to | lvalue | rvalue |
| Represents | existing object | rvalue/temporary |
| Main use | access existing object | enable move operations |
| Introduced | Original C++ | C++11 |
| Important for move semantics | No | Yes |

---

# 7. Example: Function Overloading

Rvalue references become especially useful when functions are overloaded.

```cpp
#include <iostream>

void process(int& x)
{
    std::cout << "lvalue\n";
}

void process(int&& x)
{
    std::cout << "rvalue\n";
}

int main()
{
    int a = 10;

    process(a);
    process(20);
}
```

Output:

```text
lvalue
rvalue
```

Why?

```cpp
process(a);
```

`a` is an lvalue.

Therefore:

```cpp
int&
```

is selected.

But:

```cpp
process(20);
```

`20` is an rvalue.

Therefore:

```cpp
int&&
```

is selected.

---

# 8. Rvalue References and Temporary Objects

Consider:

```cpp
std::string&& s = std::string("Hello");
```

`std::string("Hello")` creates a temporary object.

Normally, that temporary object would eventually be destroyed.

An rvalue reference allows us to bind to that temporary.

This is one of the mechanisms that makes move semantics possible.

---

# 9. The Big Problem: Copying Large Objects

Consider:

```cpp
std::vector<int> a(1000000);
```

Suppose we do:

```cpp
std::vector<int> b = a;
```

The vector's contents must be copied.

Conceptually:

```text
a
│
├── 1
├── 2
├── 3
├── ...
└── 1,000,000

        COPY

        ↓

b
│
├── 1
├── 2
├── 3
├── ...
└── 1,000,000
```

That can be expensive.

Now consider:

```cpp
std::vector<int> createVector()
{
    std::vector<int> data(1000000);
    return data;
}
```

The returned object is a temporary.

Instead of copying the entire resource, modern C++ can move the resources.

---

# 10. Move Semantics Connection

Suppose a class owns dynamically allocated memory.

A copy operation may need to:

```text
allocate new memory
        ↓
copy all data
        ↓
release old data
```

A move operation can instead transfer ownership:

```text
Object A
   │
   └── owns memory ───────► [DATA]

Move
  ↓

Object B
   │
   └── now owns ──────────► [DATA]

Object A
   │
   └── empty/null state
```

This is the central performance benefit of move semantics.

---

# 11. Move Constructor

A move constructor commonly looks like:

```cpp
class Buffer
{
private:
    int* data;

public:
    Buffer(int size)
    {
        data = new int[size];
    }

    Buffer(Buffer&& other)
    {
        data = other.data;
        other.data = nullptr;
    }

    ~Buffer()
    {
        delete[] data;
    }
};
```

The important part is:

```cpp
Buffer(Buffer&& other)
```

The `&&` tells the compiler:

> This constructor accepts an rvalue `Buffer`.

Instead of copying the resource, it can transfer ownership.

---

# 12. Why `std::move` Is Important

Consider:

```cpp
std::string a = "Hello";
std::string b = std::move(a);
```

`std::move(a)` allows `a` to be treated as an rvalue so that move operations can be selected.

Important:

> `std::move()` does not itself move anything.

It is essentially a cast that enables move semantics.

The actual movement is performed by a move constructor or move assignment operator when one is available.

---

# 13. Very Important Interview Point

This is WRONG:

> "`std::move()` moves the object."

Better answer:

> "`std::move()` casts an expression to an xvalue/rvalue-reference-compatible form, allowing move constructors or move assignment operators to be selected."

This distinction is very important in interviews.

---

# 14. Named Rvalue References

One of the most important rules:

```cpp
void process(int&& x)
{
    // x is a named variable here
}
```

Although the parameter type is:

```cpp
int&&
```

the expression:

```cpp
x
```

is an lvalue because it has a name.

This surprises many beginners.

Example:

```cpp
void process(std::string&& text)
{
    std::string other = text;
}
```

Inside the function, `text` behaves as an lvalue expression.

If you want to pass it onward as an rvalue, you may need:

```cpp
std::move(text)
```

Example:

```cpp
void process(std::string&& text)
{
    std::string other = std::move(text);
}
```

---

# 15. Why Does a Named `T&&` Become an Lvalue?

Value categories apply to expressions, not simply to declared types.

Consider:

```cpp
int&& x = 100;
```

The expression:

```cpp
x
```

is an lvalue because `x` is a named variable.

Therefore:

```cpp
process(x);
```

will treat `x` as an lvalue.

But:

```cpp
process(std::move(x));
```

can treat it as an rvalue again.

---

# 16. Example

```cpp
#include <iostream>

void test(int&)
{
    std::cout << "lvalue\n";
}

void test(int&&)
{
    std::cout << "rvalue\n";
}

int main()
{
    int&& x = 100;

    test(x);
    test(std::move(x));
}
```

Output:

```text
lvalue
rvalue
```

This is a classic interview question.

---

# 17. Rvalue Reference Does Not Mean "Object Is Temporary"

This is another important distinction.

```cpp
int&& x = 10;
```

`x` is a named reference variable.

The original initializer `10` is an rvalue.

But the expression `x` is an lvalue.

Therefore:

```text
Type of x/reference:
    int&&

Expression x:
    lvalue
```

Do not confuse type and value category.

---

# 18. Function Returning by Value

Consider:

```cpp
std::string createName()
{
    return "Shrinath";
}
```

Then:

```cpp
std::string name = createName();
```

The returned result can be used as an rvalue.

This allows modern C++ to efficiently construct or move the resulting object.

Modern C++ also has Return Value Optimization (RVO) and copy elision, which can eliminate copying/moving entirely in suitable cases.

---

# 19. Rvalue References and `const`

Compare:

```cpp
const int& a = 10;
```

and:

```cpp
int&& b = 10;
```

Both can bind to a temporary, but they have different purposes.

`const T&`:

```text
Can bind to lvalues and rvalues.
Does not allow modification through the reference.
```

`T&&`:

```text
Can bind to rvalues.
Can allow modification of the referred object.
Primarily useful for move semantics and overload resolution.
```

---

# 20. Example with Strings

```cpp
#include <iostream>
#include <string>

void process(const std::string& text)
{
    std::cout << "const lvalue reference\n";
}

void process(std::string&& text)
{
    std::cout << "rvalue reference\n";
}

int main()
{
    std::string name = "Shrinath";

    process(name);
    process("Hello");
}
```

Output:

```text
const lvalue reference
rvalue reference
```

The temporary string created from `"Hello"` can select the rvalue-reference overload.

---

# 21. The Five Important Value Categories

Modern C++ has a richer value-category system.

The major categories are:

```text
expression
   │
   ├── lvalue
   │
   └── rvalue
        │
        ├── prvalue
        │
        └── xvalue
```

More precisely:

```text
                 Expression
                 /         \
             glvalue      rvalue
             /    \        /   \
         lvalue  xvalue  prvalue
                         /
                  xvalue is also
                  a glvalue
```

For Day 09, the practical focus is:

```text
lvalue
rvalue
xvalue
prvalue
```

You will use these concepts heavily in Perfect Forwarding on Day 10.

---

# 22. prvalue

A prvalue is a pure rvalue.

Examples include:

```cpp
10
20 + 30
std::string("Hello")
```

A simplified mental model:

> prvalue = value-producing expression.

---

# 23. xvalue

An xvalue is an expression referring to an object whose resources can potentially be reused.

The classic example:

```cpp
std::move(obj)
```

`std::move(obj)` produces an xvalue.

This is why move operations can be selected.

---

# 24. Quick Value-Category Table

| Expression | Category |
|---|---|
| `x` | lvalue |
| `10` | prvalue |
| `x + y` | prvalue |
| `std::move(x)` | xvalue |
| named `T&&` variable | lvalue expression |
| temporary object | generally prvalue |

---

# 25. Reference Binding Rules — Practical Version

```cpp
int x = 10;

int& a = x;          // OK
int&& b = 20;        // OK

int&& c = x;         // ERROR
```

Why?

`x` is an lvalue and `int&&` normally requires an rvalue.

You can explicitly cast:

```cpp
int&& c = std::move(x);
```

But be careful: after moving from `x`, the object remains valid but its value/state is generally unspecified for many standard-library types.

---

# 26. Moved-From Objects

Example:

```cpp
std::string a = "Hello";

std::string b = std::move(a);
```

After the move:

```text
b → owns the transferred string resources

a → valid but moved-from state
```

Do not assume:

```cpp
a == ""
```

for every type.

The safe rule is:

> A moved-from standard-library object is generally valid but its exact state should not be assumed unless the type specifies it.

---

# 27. Rvalue References and Ownership

Rvalue references are especially powerful when a type manages resources:

```text
heap memory
file handles
sockets
buffers
locks/resources
large containers
```

Instead of duplicating resources:

```text
COPY
A ─────► Resource 1
B ─────► Resource 2
```

we can transfer ownership:

```text
MOVE
A ─────► Resource
          ↑
          │
B ────────┘
```

This is one reason move semantics is critical in production C++.

---

# 28. Common Mistake #1

Wrong idea:

> "`&&` always means rvalue."

Not always.

In an ordinary declaration:

```cpp
int&& x;
```

it is an rvalue reference.

But in templates, `T&&` can participate in forwarding references.

That will be covered in **Day 10 — Perfect Forwarding**.

---

# 29. Common Mistake #2

Wrong:

> "`std::move()` moves data."

Correct:

> "`std::move()` enables move semantics by converting an expression to an xvalue."

---

# 30. Common Mistake #3

Wrong:

```text
If a variable has type T&&,
then the variable itself is an rvalue.
```

Correct:

```text
A named variable is an lvalue expression,
even if its declared type is T&&.
```

Example:

```cpp
int&& x = 10;

test(x);              // lvalue
test(std::move(x));   // xvalue/rvalue
```

---

# 31. Common Mistake #4

Do not write:

```cpp
std::move(x);
std::move(x);
```

and assume `x` still contains its original value.

After moving from an object, its state may have changed.

Use moved-from objects carefully.

---

# 32. Rvalue References vs Pointers

These are completely different concepts.

Pointer:

```cpp
int* p = &x;
```

A pointer stores an address.

Rvalue reference:

```cpp
int&& r = 10;
```

A reference provides another way to refer to an object/expression and participates in overload resolution and move semantics.

---

# 33. Rvalue References vs `const T&`

This is an important interview comparison.

### `const T&`

```cpp
void process(const std::string& value);
```

Useful when:

- You only need to read the object.
- You want to avoid copying.
- You want to accept both lvalues and rvalues.

### `T&&`

```cpp
void process(std::string&& value);
```

Useful when:

- You specifically want rvalues.
- You want to distinguish rvalues from lvalues.
- You want to enable moving from the supplied object.

---

# 34. Real-World Example

Imagine a large image buffer:

```cpp
class Image
{
    unsigned char* pixels;
    size_t size;
};
```

Copy:

```text
Image A
   ↓
allocate memory
   ↓
copy millions of pixels
   ↓
Image B
```

Move:

```text
Image A
   ↓
transfer pointer
   ↓
Image B
```

The pixel data does not need to be duplicated.

This is why rvalue references are extremely useful in:

- game engines
- robotics
- embedded software
- image processing
- networking
- databases
- high-performance systems

---

# 35. Interview Questions

## Q1. What is an rvalue reference?

An rvalue reference is a reference declared using `&&` that can bind to rvalues and is a key language feature enabling move semantics and perfect forwarding.

---

## Q2. Why were rvalue references introduced?

Primarily to support efficient resource transfer and perfect forwarding.

They allow C++ to distinguish between objects that can be safely moved from and objects that should generally be copied/reused without consuming their resources.

---

## Q3. What is the difference between `T&` and `T&&`?

`T&` is an lvalue reference and commonly binds to lvalues.

`T&&` is an rvalue reference and commonly binds to rvalues.

---

## Q4. What does `std::move()` do?

It converts an expression into an xvalue so that move operations can participate in overload resolution.

It does not itself perform the move.

---

## Q5. Does `std::move()` move an object?

No.

The actual move is performed by a move constructor or move assignment operator if one is available.

---

## Q6. Can an rvalue reference be named?

Yes.

```cpp
int&& x = 10;
```

But the expression `x` is an lvalue because it is named.

---

## Q7. Why does a named rvalue reference behave as an lvalue?

Because value categories describe expressions. A named variable is an lvalue expression regardless of whether its declared type is `T&&`.

---

## Q8. What happens after moving an object?

The object's resources may have been transferred. The moved-from object remains valid, but its exact state should not generally be assumed unless specified by its type.

---

## Q9. What is an xvalue?

An xvalue is a glvalue that represents an object whose resources can potentially be reused. `std::move(x)` is a common way to produce an xvalue.

---

## Q10. What is the connection between rvalue references and move constructors?

A move constructor commonly takes `T&&` and transfers resources from the source object instead of performing an expensive deep copy.

---

# 36. Coding Exercise 1 — Identify the Category

Determine whether each expression is an lvalue or rvalue:

```cpp
int x = 10;
int y = 20;

x
10
x + y
std::move(x)
y
42
```

Expected practical classification:

```text
x              → lvalue
10             → prvalue/rvalue
x + y          → prvalue/rvalue
std::move(x)   → xvalue/rvalue
y              → lvalue
42             → prvalue/rvalue
```

---

# 37. Coding Exercise 2 — Overload Resolution

Write:

```cpp
void check(int& x);
void check(int&& x);
```

Then test:

```cpp
int a = 10;

check(a);
check(20);
check(std::move(a));
```

Predict the output before compiling.

---

# 38. Coding Exercise 3 — Named Rvalue Reference

Predict the output:

```cpp
#include <iostream>

void test(int&)
{
    std::cout << "L\n";
}

void test(int&&)
{
    std::cout << "R\n";
}

int main()
{
    int&& x = 100;

    test(x);
    test(std::move(x));
}
```

Expected:

```text
L
R
```

Explain why.

---

# 39. Coding Exercise 4 — Build a Move Constructor

Create a class:

```cpp
class Resource
{
private:
    int* data;

public:
    Resource(int value);
    Resource(const Resource& other);
    Resource(Resource&& other);
    ~Resource();
};
```

Requirements:

- Allocate memory.
- Implement deep copy.
- Implement move constructor.
- Transfer ownership during move.
- Set the source pointer to `nullptr`.
- Add output statements to observe copy vs move.

---

# 40. Day 09 Mini Project

## Resource Manager

Build a small class that manages a dynamically allocated integer array.

Requirements:

```text
ResourceManager
│
├── Constructor
├── Destructor
├── Copy Constructor
├── Copy Assignment
├── Move Constructor
└── Move Assignment
```

Test:

```cpp
ResourceManager a(1000);

ResourceManager b = a;              // copy

ResourceManager c = std::move(a);   // move
```

Print:

```text
Constructor called
Copy Constructor called
Move Constructor called
Destructor called
```

The goal is to visually understand:

```text
COPY
resource duplicated

vs

MOVE
resource ownership transferred
```

---

# 41. Day 09 Interview Gold

You should be able to answer these without looking at notes:

```text
1. What is an lvalue?
2. What is an rvalue?
3. What is an rvalue reference?
4. Why was && introduced?
5. Difference between & and &&?
6. What is move semantics?
7. What does std::move() actually do?
8. Does std::move() move an object?
9. Why is a named T&& variable an lvalue?
10. What is an xvalue?
11. What happens to a moved-from object?
12. How does && help a move constructor?
13. Why is moving faster than copying?
14. What is the difference between const T& and T&&?
15. How are rvalue references related to perfect forwarding?
```

The last question leads directly into Day 10.

---

# 42. Day 09 — Key Mental Model

Remember this:

```text
lvalue
  ↓
named / identifiable object

rvalue
  ↓
temporary/value-producing expression

T&&
  ↓
rvalue reference

std::move(x)
  ↓
cast x to xvalue
  ↓
allows move operations to be selected

Move Constructor
  ↓
transfers resources
  ↓
avoids expensive copying
```

---

# 43. The Most Important Rule

Memorize:

```cpp
int&& x = 10;

test(x);              // x is an lvalue expression

test(std::move(x));   // x is treated as an xvalue
```

And:

```text
TYPE ≠ VALUE CATEGORY OF EXPRESSION
```

This is one of the foundations for understanding:

```text
Rvalue References
        ↓
Move Semantics
        ↓
Perfect Forwarding
        ↓
Universal/Forwarding References
        ↓
Variadic Templates
```

---

# 44. Day 09 Completion Checklist

- [ ] Understand lvalues
- [ ] Understand rvalues
- [ ] Understand `T&&`
- [ ] Understand `T&` vs `T&&`
- [ ] Understand temporary objects
- [ ] Understand move semantics
- [ ] Understand move constructors
- [ ] Understand `std::move`
- [ ] Know that `std::move` does not itself move
- [ ] Understand named rvalue references
- [ ] Understand xvalues
- [ ] Understand prvalues
- [ ] Complete overload-resolution exercises
- [ ] Implement a move constructor
- [ ] Complete Resource Manager mini project
- [ ] Answer Day 09 interview questions
- [ ] Push Day 09 work to GitHub

---

# 45. Day 09 → Day 10 Connection

Day 09 taught:

```text
Rvalue References
       &&
        ↓
Move Semantics
        ↓
std::move
        ↓
Resource Transfer
```

Day 10 will build on this:

```text
Perfect Forwarding
       ↓
T&& in templates
       ↓
Forwarding References
       ↓
Reference Collapsing
       ↓
std::forward
       ↓
Preserve lvalue/rvalue nature
```

So **do not start Day 10 until you can explain why `test(x)` and `test(std::move(x))` can select different overloads.**

---

## Day 09 Status

**Phase 2 — Modern C++**

**Day 09 — Rvalue References `&&`**

Status: **COMPLETED NOTES**

**Next: Day 10 — Perfect Forwarding**