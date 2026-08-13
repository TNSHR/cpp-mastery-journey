# Phase 2 — Day 8
# Move Semantics & std::move

---

## Objective

Understand how C++ can transfer resources instead of copying them.

Today's topics:

- Copy semantics
- Move semantics
- `std::move`
- lvalues
- rvalues
- rvalue references
- Move constructor
- Move assignment operator
- Copy constructor
- Copy assignment operator
- Moved-from objects
- Deep copy
- Shallow copy
- `noexcept`
- `unique_ptr` and move semantics
- Rule of 3 / Rule of 5 connection

---

# 1. Why Move Semantics?

Suppose a class owns dynamically allocated memory:

```text
Resource
   |
   v
[1][2][3][4][5]



33. Interview Questions
Q1. What is move semantics?

Move semantics allow resources to be transferred from
one object to another instead of being copied.

Q2. What is std::move?

std::move casts an expression so it can be treated as
an rvalue and enables move operations.

It does not itself perform the resource transfer.

Q3. What is an rvalue reference?

An rvalue reference is declared using:

T&&

and can bind to rvalue expressions.

Move constructors and move assignment operators commonly
use rvalue references.

Q4. What is a move constructor?

A constructor that transfers resources from another object:

T(T&& other);
Q5. What is move assignment?

An assignment operator that transfers resources from
another already-existing object:

T& operator=(T&& other);
Q6. Difference between copy constructor and move constructor?

Copy constructor:

T(const T& other);

duplicates the resource.

Move constructor:

T(T&& other);

transfers the resource.

Q7. What happens to an object after it is moved from?

It remains a valid object, but its exact state is generally
unspecified unless the type defines the state.

Q8. Why should move constructors often be noexcept?

Because non-throwing move operations allow standard library
containers to use move operations more effectively while
maintaining exception guarantees.

Q9. Why can't unique_ptr be copied?

Because copying would create multiple owners, violating
exclusive ownership.

Q10. Why can unique_ptr be moved?

Because moving transfers ownership.

34. Practical Exercise 1

Create:

Resource a(100);

Then:

Resource b = a;

Identify:

Copy Constructor