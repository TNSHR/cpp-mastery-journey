Day 10 — Perfect Forwarding

Phase 2 — Modern C++ | Prerequisite: Move Semantics (Day 8), Rvalue References (Day 9)

1. Theory

Perfect forwarding lets a template function pass its arguments on to another function without losing whether each argument was originally an lvalue or an rvalue, and without adding extra copies along the way.

It has three moving parts that only work together:

Forwarding reference — a function parameter of the exact form T&& where T is a template parameter deduced at the call site (e.g. Args&&... args in a variadic template). This is NOT the same thing as an rvalue reference, even though the syntax looks identical.
Reference collapsing — the compiler's rule for what T&& becomes once T itself gets deduced as a reference type.
std::forward<T>(x) — a conditional cast. It turns x back into an rvalue only if T was deduced from an rvalue; otherwise it leaves x as an lvalue.
2. Why it exists

Without perfect forwarding, every "pass-through" wrapper function — factories, emplace_back, make_unique, logging wrappers, decorators — would have to choose between:

taking arguments by value (forces a copy or move on the way in, every single time, even when the caller had a cheap lvalue to hand), or
taking arguments by const T& (works for lvalues, but forces an unnecessary copy for temporaries that could have been moved instead), or
writing two overloads by hand for every parameter (const T& and T&&) — and this explodes combinatorially with more than one parameter (2 params = 4 overloads, 3 params = 8 overloads...).

Perfect forwarding collapses all of that into one function template that behaves as if the wrapper weren't there at all.

3. Real-world analogy

Think of a mail-forwarding service. If it photocopies every letter before resending it (pass by value), you've paid an unnecessary cost. If it insists every letter must be a "permanent record" copy before it will touch it (const T& only), original one-time-use letters (temporaries) get needlessly duplicated too. Perfect forwarding is a forwarding service that hands off the exact original envelope — copy if the sender wants a copy kept, or move the original along if the sender said "this is disposable" (rvalue).

4. Reference collapsing rules

This is the mechanism that makes Args&& in a template context able to mean either "lvalue ref" or "rvalue ref" depending on what's deduced.

T deduced as	Parameter type T&& collapses to
Widget& (lvalue passed in)	Widget&
Widget&& (rvalue passed in)	Widget&&

Rule of thumb: & + &  = &, & + && = &, && + & = &, && + && = &&. Only "double rvalue" collapses to rvalue — an lvalue anywhere in the mix wins.

This is only true when T is deduced right there at the call site. std::vector<T>&& inside a class template is a plain rvalue reference, NOT a forwarding reference, because T was fixed when the class was instantiated, not deduced by this function call.

5. Folder structure
day-10-perfect-forwarding/
├── include/
│   ├── Widget.hpp     # "loud" class — prints which ctor runs
│   └── Factory.hpp    # myMakeUnique (correct) vs badFactory (broken)
├── src/
│   └── main.cpp        # drives both factories, prints proof
├── build/               # compiled binary lands here
└── notes.md
6. Header walkthrough — Widget.hpp

Every constructor prints what it did. This is deliberate: perfect forwarding is invisible if you can't observe it, so the whole exercise is built around making the constructor choice visible at runtime.

7. Header walkthrough — Factory.hpp
myMakeUnique<T>(Args&&... args) — the correct version. Forwards every argument with std::forward<Args>(args)....
badFactory<T>(Args&&... args) — same signature, but forwards args... directly, without std::forward. Looks almost identical; behaves very differently.
8. main.cpp walkthrough

Four calls, each proving one rule:

Temporary std::string into myMakeUnique → move constructor runs.
Named lvalue std::string into myMakeUnique → copy constructor runs.
Named lvalue wrapped in std::move into myMakeUnique → move runs (because std::move is just a cast to rvalue reference — it doesn't move anything itself).
Same temporary as (1), but through badFactory → copy runs anyway. This is the bug perfect forwarding exists to prevent.
9. Compilation
bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp -o build/day10
./build/day10

Verified output (this run):

=== 1. myMakeUnique with an RVALUE (temporary string) ===
  [Widget]  MOVE-constructed from rvalue: "Sensor-A"

=== 2. myMakeUnique with an LVALUE ===
  [Widget]  COPY-constructed from lvalue: "Sensor-B"

=== 3. myMakeUnique with std::move on an lvalue ===
  [Widget]  MOVE-constructed from rvalue: "Sensor-C"

=== 4. badFactory with the SAME rvalue temporary ===
  [Widget]  COPY-constructed from lvalue: "Sensor-D"
10. Common mistakes
Forgetting std::forward — args become lvalues inside the function body regardless of what was passed in (see badFactory). This is the #1 real-world bug.
Calling std::forward more than once on the same argument — if a parameter is used twice in the function body, only the last use should forward it; forwarding it earlier can leave it moved-from for the second use.
Confusing T&& in a template with T&& in a concrete function — void f(Widget&& w) is a plain rvalue reference (only binds rvalues). template<typename T> void f(T&& w) is a forwarding reference (binds both), purely because T is deduced here.
Using std::move instead of std::forward inside a forwarding function — std::move unconditionally casts to rvalue, which would break case 2 above (the lvalue would get wrongly forwarded as an rvalue and moved from, corrupting the caller's variable).
11. Best practices
Use forwarding references for anything whose job is to pass arguments on to another function unchanged (factories, wrappers, emplace-style APIs).
Always pair a forwarding reference parameter with std::forward, never std::move, unless you specifically intend to consume it.
Prefer std::make_unique / std::make_shared over writing your own in production — this exercise reimplements it purely to see the mechanics; don't reinvent it for real code.
12. Assignment

Extend Factory.hpp with a logAndCreate<T>(Args&&... args) that prints "Creating object..." before forwarding to myMakeUnique, and confirm the constructor selection is unaffected by adding that extra layer of indirection. (This proves forwarding chains correctly through multiple wrapper layers, which is the realistic production scenario — you rarely have just one layer of wrapping.)

13. Interview questions
What's the difference between an rvalue reference and a forwarding reference — same syntax, different meaning. What decides which one you have?
Why does std::move(x) not actually move anything?
Walk through reference collapsing for template<typename T> f(T&&) called with an lvalue int vs an rvalue int.
What breaks if you use std::forward twice on the same variable inside one function?
Why can't emplace_back be implemented efficiently without perfect forwarding?


# C++ Mastery Journey
# Phase 2 — Modern C++
# Day 10 — Perfect Forwarding

---

# 1. Day Objective

The objective of Day 10 is to understand Perfect Forwarding
in modern C++.

Topics covered:

- Forwarding references
- Template type deduction
- Reference collapsing
- std::forward
- Difference between std::move and std::forward
- Preserving lvalue/rvalue category
- Named rvalue references
- Why normal wrapper functions lose value category
- Perfect forwarding pattern
- Practical wrapper functions
- Factory functions
- Connection to variadic templates
- Interview questions
- Coding interview questions
- Common mistakes
- Practical exercises

---

# 2. Prerequisites

Before studying Perfect Forwarding, understand:

- References
- lvalues
- rvalues
- xvalues
- rvalue references
- std::move
- templates
- function overloading

Day 9 — Rvalue References is especially important.

---

# 3. The Problem Perfect Forwarding Solves

Suppose we have:

void process(int& value)
{
    std::cout << "lvalue";
}

void process(int&& value)
{
    std::cout << "rvalue";
}

Direct calls work:

int x = 10;

process(x);

calls:

process(int&)

while:

process(20);

calls:

process(int&&)

Now suppose we create a wrapper:

template<typename T>
void wrapper(T&& value)
{
    process(value);
}

We may expect:

wrapper(x);

to preserve lvalue.

And:

wrapper(20);

to preserve rvalue.

But there is a problem.

The parameter:

T&& value

is a named variable.

A named variable is an lvalue expression.

Therefore:

process(value);

treats value as an lvalue.

This means an original rvalue can lose its rvalue
characteristics.

---

# 4. The Problem Visually

Original call:

wrapper(20);

The programmer may expect:

20
 ↓
rvalue
 ↓
process(int&&)

But inside wrapper:

20
 ↓
T&& value
 ↓
value
 ↓
named expression
 ↓
lvalue
 ↓
process(int&)

The rvalue category has been lost.

---

# 5. The Solution

Perfect forwarding uses:

std::forward<T>(value)

instead of:

value

Therefore:

template<typename T>
void wrapper(T&& value)
{
    process(
        std::forward<T>(value)
    );
}

Now the original value category is preserved.

---

# 6. Definition of Perfect Forwarding

Perfect forwarding is a C++ technique that allows a
function template to pass an argument to another function
while preserving the argument's original value category.

In simple terms:

lvalue in
    ↓
lvalue out

rvalue in
    ↓
rvalue out

This is the main purpose of perfect forwarding.

---

# 7. Forwarding Reference

The common pattern is:

template<typename T>
void wrapper(T&& value)
{
}

When T is deduced, T&& can be a forwarding reference.

A forwarding reference can bind to both:

- lvalues
- rvalues

depending on template deduction.

---

# 8. Important Terminology

Do not confuse:

Rvalue Reference:

T&&

with:

Forwarding Reference:

T&& in a suitable template deduction context.

The same syntax is used, but the role can be different.

For example:

void process(int&& value);

Here:

int&&

is an rvalue reference.

But:

template<typename T>
void wrapper(T&& value);

Here:

T&&

can be a forwarding reference.

---

# 9. Template Deduction — Lvalue

Consider:

template<typename T>
void wrapper(T&& value)
{
}

Then:

int x = 10;

wrapper(x);

x is an lvalue.

Template deduction gives:

T = int&

Therefore:

T&&

becomes:

int& &&

Reference collapsing gives:

int&

Therefore the parameter effectively becomes:

int& value

---

# 10. Template Deduction — Rvalue

Now:

wrapper(10);

10 is an rvalue.

Template deduction gives:

T = int

Therefore:

T&&

becomes:

int&&

No reference collapsing to lvalue is needed.

Therefore the parameter is:

int&& value

---

# 11. The Two Cases

For:

template<typename T>
void wrapper(T&& value);

Lvalue:

T = int&

T&&
↓
int& &&
↓
int&

Rvalue:

T = int

T&&
↓
int&&

This is why T&& in a forwarding-reference context can
accept both lvalues and rvalues.

---

# 12. Reference Collapsing

Reference collapsing rules:

T&  &   -> T&

T&  &&  -> T&

T&& &   -> T&

T&& &&  -> T&&

The important shortcut:

If one side is &, the result is generally &.

Only:

&& + &&

produces:

&&

---

# 13. Why Reference Collapsing Matters

For:

template<typename T>
void wrapper(T&& value);

when:

T = int&

we get:

int& &&

which collapses to:

int&

This is what allows an lvalue to be accepted.

---

# 14. std::forward

std::forward is declared in:

#include <utility>

Typical usage:

std::forward<T>(value)

Its purpose is to preserve the value category determined
by template deduction.

---

# 15. std::move vs std::forward

std::move:

std::move(value)

Conceptually:

"Treat this expression as movable."

It produces an xvalue.

It does not preserve the original category.

std::forward:

std::forward<T>(value)

Conceptually:

"Forward this expression according to the category that
was originally deduced for T."

---

# 16. Comparison

std::move:

lvalue
  |
  v
xvalue

std::forward<T>:

lvalue
  |
  v
lvalue

rvalue
  |
  v
xvalue/rvalue

Therefore:

std::move = request move treatment

std::forward = preserve forwarding category

---

# 17. Why std::move Is Wrong in a Generic Wrapper

Suppose:

template<typename T>
void wrapper(T&& value)
{
    target(std::move(value));
}

This forces the argument toward rvalue treatment.

If the caller passed an lvalue:

int x = 10;

wrapper(x);

the wrapper may now treat x as movable.

That is not what perfect forwarding means.

---

# 18. Correct Generic Wrapper

Correct:

template<typename T>
void wrapper(T&& value)
{
    target(
        std::forward<T>(value)
    );
}

This preserves the caller's original category.

---

# 19. Example

Given:

void process(int&)
{
    std::cout << "L";
}

void process(int&&)
{
    std::cout << "R";
}

Then:

int x = 10;

process(x);

prints:

L

process(10);

prints:

R

Now:

template<typename T>
void wrapper(T&& value)
{
    process(
        std::forward<T>(value)
    );
}

wrapper(x);

prints:

L

wrapper(10);

prints:

R

This is perfect forwarding.

---

# 20. Bad Forwarding Example

Consider:

template<typename T>
void badForward(T&& value)
{
    process(value);
}

Then:

int x = 10;

badForward(x);

prints:

L

That is correct for the lvalue.

But:

badForward(20);

also prints:

L

This is the problem.

20 was originally an rvalue, but value is named.

Therefore value is an lvalue expression.

---

# 21. Perfect Forwarding Fix

Replace:

process(value);

with:

process(
    std::forward<T>(value)
);

Now:

perfectForward(x);

produces:

L

and:

perfectForward(20);

produces:

R

The original category is preserved.

---

# 22. Named Variable Rule

This Day 10 concept depends directly on Day 9.

Even if:

int&& value = 10;

the expression:

value

is an lvalue because it is named.

Therefore:

process(value);

can select an lvalue overload.

To treat it as an xvalue:

process(
    std::move(value)
);

For generic code:

process(
    std::forward<T>(value)
);

---

# 23. Why Perfect Forwarding Is Called "Perfect"

It attempts to preserve the properties of the original
argument as it passes through a wrapper.

For example:

Caller:

wrapper(x);

x is lvalue.

Forwarded:

std::forward<T>(x)

remains lvalue.

Caller:

wrapper(10);

10 is rvalue.

Forwarded:

std::forward<T>(value)

remains an rvalue/xvalue expression.

Therefore the wrapper does not unnecessarily change the
caller's value category.

---

# 24. Real-World Use

Perfect forwarding is heavily used in modern C++ libraries.

Common examples include:

- factory functions
- generic wrappers
- emplace functions
- STL utilities
- smart-pointer factories
- generic constructors
- library implementation code

---

# 25. Factory Example

Suppose:

class Person
{
public:

    Person(
        std::string name,
        int age
    )
    {
    }
};

A generic factory could look like:

template<typename T, typename... Args>
std::unique_ptr<T> create(
    Args&&... args
)
{
    return std::make_unique<T>(
        std::forward<Args>(args)...
    );
}

This combines:

- forwarding references
- variadic templates
- std::forward

Day 11 will focus on Variadic Templates.

---

# 26. Connection to emplace

STL containers provide operations such as:

emplace_back()

These functions can construct an object directly in
the container using forwarded constructor arguments.

Conceptually:

emplace_back(args...)

        ↓

forward arguments

        ↓

construct object

This avoids unnecessary intermediate objects in many
situations.

---

# 27. std::make_unique Connection

Consider:

std::make_unique<MyClass>(
    argument1,
    argument2
);

Internally, the implementation needs to pass constructor
arguments to MyClass.

Perfect forwarding allows those arguments to retain their
appropriate value categories.

---

# 28. std::make_shared Connection

Similarly:

std::make_shared<MyClass>(
    argument1,
    argument2
);

can use forwarding techniques to construct MyClass.

---

# 29. Perfect Forwarding and Performance

Perfect forwarding can help generic code avoid unnecessary
copies.

Instead of:

wrapper(argument);

making an unnecessary copy, the wrapper can forward the
argument directly to the target.

However:

Perfect forwarding is not automatically faster in every
situation.

It is primarily about preserving semantics and allowing
the appropriate overload/constructor to be selected.

---

# 30. Important Limitation

Perfect forwarding does not magically solve every copying
problem.

The target function may still choose to copy an object.

For example:

void target(std::string value);

Even if we forward a string correctly, passing by value
still creates the semantics required by that function.

Perfect forwarding preserves the category; it does not
guarantee zero copies.

---

# 31. Common Mistake #1

Wrong:

template<typename T>
void wrapper(T&& value)
{
    target(value);
}

This does not perfectly forward because value is named.

Correct:

template<typename T>
void wrapper(T&& value)
{
    target(
        std::forward<T>(value)
    );
}

---

# 32. Common Mistake #2

Wrong:

template<typename T>
void wrapper(T&& value)
{
    target(
        std::move(value)
    );
}

This forces rvalue treatment.

Correct:

template<typename T>
void wrapper(T&& value)
{
    target(
        std::forward<T>(value)
    );
}

---

# 33. Common Mistake #3

Thinking every T&& is a forwarding reference.

Not necessarily.

Example:

void function(int&& value);

Here:

int&&

is simply an rvalue reference.

Forwarding references occur in specific template deduction
contexts.

---

# 34. Common Mistake #4

Thinking std::forward can be used everywhere.

std::forward is primarily intended for forwarding a value
whose original category has been captured through template
deduction.

It is not a replacement for std::move.

---

# 35. Common Mistake #5

Thinking perfect forwarding means "always move."

Incorrect.

Perfect forwarding preserves:

lvalue → lvalue

rvalue → rvalue

It does not force everything into a move.

---

# 36. Day 9 Connection

Day 9 introduced:

T&&

and:

std::move()

Day 10 builds on that:

T&&
+
template deduction
+
reference collapsing
+
std::forward
=
perfect forwarding

---

# 37. Day 11 Connection

Day 11 is:

Variadic Templates.

The concepts connect directly:

template<typename... Args>
void wrapper(Args&&... args)
{
    target(
        std::forward<Args>(args)...
    );
}

This is one of the most important generic-programming
patterns in modern C++.

---

# 38. Interview Questions

## Q1. What is perfect forwarding?

Perfect forwarding is a technique that allows a wrapper
function to pass an argument to another function while
preserving the argument's original value category.

---

## Q2. What is a forwarding reference?

A forwarding reference is a `T&&` parameter in a suitable
template type-deduction context.

Example:

template<typename T>
void wrapper(T&& value);

It can bind to both lvalues and rvalues.

---

## Q3. What is the difference between an rvalue reference
and a forwarding reference?

An rvalue reference is a reference to an rvalue:

void function(int&& value);

A forwarding reference occurs in a template deduction
context:

template<typename T>
void function(T&& value);

The latter can accept both lvalues and rvalues because of
template deduction and reference collapsing.

---

## Q4. What does std::forward do?

std::forward<T>(value) conditionally casts the expression
so that the original value category captured by T is
preserved.

---

## Q5. Difference between std::move and std::forward?

std::move unconditionally converts its argument into an
xvalue expression.

std::forward conditionally preserves the original
lvalue/rvalue category.

---

## Q6. Why can't we simply write target(value)?

Because value is a named variable and therefore an lvalue
expression.

This can cause an original rvalue to be forwarded as an
lvalue.

---

## Q7. Why is T&& special in templates?

When T is deduced, T&& can act as a forwarding reference.

For an lvalue:

T becomes T&.

For an rvalue:

T becomes T.

Reference collapsing then produces the appropriate
reference type.

---

## Q8. What happens when an lvalue is passed to T&&?

Example:

int x = 10;

wrapper(x);

T is deduced as:

int&

Then:

T&&

becomes:

int& &&

which collapses to:

int&.

---

## Q9. What happens when an rvalue is passed to T&&?

Example:

wrapper(10);

T is deduced as:

int

Therefore:

T&&

becomes:

int&&.

---

## Q10. What is reference collapsing?

Reference collapsing determines the final reference type
when references are combined.

Rules:

T&  &  -> T&
T&  && -> T&
T&& &  -> T&
T&& && -> T&&

---

## Q11. Does perfect forwarding guarantee no copies?

No.

It preserves the value category and allows the appropriate
overload/constructor to be selected.

The target function may still copy.

---

## Q12. Is every T&& a forwarding reference?

No.

It is a forwarding reference only when it appears in the
appropriate template type-deduction context.

---

## Q13. Why is perfect forwarding important in STL?

It allows generic library functions to pass arguments to
constructors and other functions without unnecessarily
changing their value categories.

---

## Q14. Why are emplace functions associated with perfect
forwarding?

Emplace functions accept constructor arguments and can
forward those arguments directly to construct an object
inside the container.

---

## Q15. Why shouldn't we replace std::forward with
std::move?

Because std::move forces rvalue treatment, while
std::forward preserves the caller's original category.

---

# 39. Coding Interview Question 1

What is the output?

void test(int&)
{
    std::cout << "L";
}

void test(int&&)
{
    std::cout << "R";
}

template<typename T>
void wrapper(T&& value)
{
    test(value);
}

int main()
{
    int x = 10;

    wrapper(x);
    wrapper(20);
}

Answer:

LL

Why?

For x:

T = int&
value is an lvalue.

For 20:

T = int

but value is named, so value is an lvalue expression.

Therefore both calls select test(int&).

---

# 40. Coding Interview Question 2

What happens after changing:

test(value);

to:

test(std::forward<T>(value));

Now the result becomes:

LR

because:

wrapper(x)
→ lvalue

wrapper(20)
→ rvalue

The original value category is preserved.

---

# 41. Coding Interview Question 3

What is T when:

int x = 10;

wrapper(x);

is called for:

template<typename T>
void wrapper(T&& value);

Answer:

T = int&

Then:

T&&

becomes:

int& &&

which collapses to:

int&.

---

# 42. Coding Interview Question 4

What is T when:

wrapper(10);

is called?

Answer:

T = int

Therefore:

T&& = int&&.

---

# 43. Coding Interview Question 5

Which is correct for perfect forwarding?

A:

template<typename T>
void wrapper(T&& value)
{
    target(value);
}

B:

template<typename T>
void wrapper(T&& value)
{
    target(std::move(value));
}

C:

template<typename T>
void wrapper(T&& value)
{
    target(std::forward<T>(value));
}

Correct:

C

---

# 44. Coding Interview Question 6

Predict:

void test(int&);
void test(int&&);

template<typename T>
void wrapper(T&& value)
{
    test(std::forward<T>(value));
}

int x = 10;

wrapper(x);
wrapper(20);

Answer:

LR

---

# 45. Practical Exercise 1

Create:

void test(int&);
void test(int&&);

Create:

template<typename T>
void wrapper(T&& value);

First use:

test(value);

Observe the result.

Then replace it with:

test(std::forward<T>(value));

Compare the results.

---

# 46. Practical Exercise 2

Create:

template<typename T>
void inspect(T&& value)
{
    // experiment here
}

Call:

int x = 10;

inspect(x);

inspect(20);

Determine what T becomes in each case.

---

# 47. Practical Exercise 3

Create a class:

class Person
{
public:

    Person(std::string name)
    {
        std::cout << "Person constructed\n";
    }
};

Create a generic factory.

Use perfect forwarding to pass constructor arguments.

---

# 48. Practical Exercise 4

Compare:

std::move(value)

with:

std::forward<T>(value)

using overloads:

void test(int&);
void test(int&&);

Observe when each overload is selected.

---

# 49. Practical Exercise 5

Create:

template<typename T>
void wrapper(T&& value)
{
    std::cout << "wrapper\n";

    target(
        std::forward<T>(value)
    );
}

Test with:

- int
- std::string
- const int
- const std::string
- temporary string

Record which overloads are selected.

---

# 50. Day 10 Important Syntax

Perfect forwarding pattern:

template<typename T>
void wrapper(T&& value)
{
    target(
        std::forward<T>(value)
    );
}

Remember:

T&&
+
std::forward<T>()
=
Perfect Forwarding

---

# 51. Day 10 Mental Model

```text
Caller
  |
  +-------------------+
  |                   |
lvalue               rvalue
  |                   |
  v                   v
T = U&                T = U
  |                   |
  v                   v
T&& = U&              T&& = U&&
  |                   |
  +---------+---------+
            |
            v
      forwarding reference
            |
            v
     std::forward<T>(value)
            |
       +----+----+
       |         |
       v         v
    lvalue     rvalue