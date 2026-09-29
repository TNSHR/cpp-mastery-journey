8. The Most Important Rule
Consider:
void function() noexcept
{
    throw std::runtime_error("Error");
}
This is dangerous.
If an exception escapes a noexcept function, C++ calls:
std::terminate();
The program terminates.
So never use noexcept simply because you don't expect an error.
Use it when the function genuinely has a non-throwing guarantee.
9. noexcept vs noexcept(...)
These are different syntaxes.
Declaration
void foo() noexcept;
Means:
foo is non-throwing
Operator
noexcept(foo());
Means:
check whether calling foo() is non-throwing
10. Why noexcept Matters for Move Constructors
This is one of the most important interview topics.
Suppose a class has:
class Buffer
{
public:

    Buffer(Buffer&& other) noexcept;
};
A container such as std::vector can use the information that
moving the object won't throw.
This can influence whether the container prefers moving or
copying elements during reallocation.
Therefore:
noexcept move constructor
        ↓
stronger exception guarantee
        ↓
better STL behavior
11. Conditional noexcept
Modern C++ often uses:
noexcept(condition)
Example:
template<typename T>
void process(T value)
    noexcept(std::is_nothrow_copy_constructible_v<T>)
{
}
This means:
The function is noexcept only if the specified operation is
itself non-throwing.

This is called a conditional noexcept specification.
12. Connection With Previous Days
Your progression now makes sense:
Day 08
Move Semantics
       ↓
Day 09
Rvalue References
       ↓
Day 10
Perfect Forwarding
       ↓
Day 11
Variadic Templates
       ↓
Day 12
constexpr
       ↓
Day 13
noexcept
These are all building toward production-quality generic C++.
📄 notes.md
Now create your permanent Day 13 notes:
nano notes.md
Paste this:
# C++ Mastery Journey
# Phase 2 — Modern C++
# Day 13 — noexcept

---

## 1. Objective

Understand `noexcept`, exception guarantees, the `noexcept`
operator, conditional `noexcept`, and why `noexcept` is
important for move operations and STL containers.

---

# 2. What Is noexcept?

`noexcept` specifies that a function is not expected to throw
an exception.

Example:

```cpp
void function() noexcept
{
}
It is mainly used to communicate and enforce a non-throwing
exception guarantee.
3. Basic Syntax
return_type function() noexcept;
Example:
void safeFunction() noexcept
{
}
This function has a non-throwing specification.
4. noexcept Is Not the Same as const
const relates to modification of an object.
noexcept relates to exception behavior.
const int x = 10;
means x cannot be modified.
void foo() noexcept;
means foo() has a non-throwing exception specification.
5. Function Without noexcept
void riskyFunction()
{
    throw std::runtime_error("Error");
}
The function is allowed to throw.
6. Function With noexcept
void safeFunction() noexcept
{
}
The function promises not to allow an exception to escape.
7. Important Rule
If an exception escapes from a noexcept function,
std::terminate() is called.
Example:
void dangerous() noexcept
{
    throw std::runtime_error("Error");
}
This leads to program termination.
Therefore noexcept should only be used when the function
really provides a non-throwing guarantee.
8. noexcept Operator
C++ provides the noexcept operator:
noexcept(expression)
It checks whether an expression is known to be non-throwing.
Example:
noexcept(foo())
returns a compile-time boolean result.
9. Example
void safe() noexcept
{
}

void risky()
{
}

static_assert(
    noexcept(safe())
);

static_assert(
    !noexcept(risky())
);
10. noexcept Specification vs noexcept Operator
These must not be confused.
Function specification:
void foo() noexcept;
Operator:
noexcept(foo());
The first declares exception behavior.
The second checks exception behavior.
11. Conditional noexcept
A function can have a condition:
template<typename T>
void process(T value)
    noexcept(std::is_nothrow_copy_constructible_v<T>)
{
}
The function is non-throwing only when the condition is true.
This is useful in generic programming.
12. noexcept(true) and noexcept(false)
These are valid:
void foo() noexcept(true);
and:
void bar() noexcept(false);
They mean:
noexcept(true)
→ non-throwing

noexcept(false)
→ may throw
Normally:
void foo() noexcept;
is preferred for a simple unconditional guarantee.
13. noexcept and Move Constructors
One of the most important uses of noexcept is move operations.
Example:
class Buffer
{
public:

    Buffer(Buffer&& other) noexcept;
};
A move constructor that is known not to throw can be used more
efficiently by standard library containers.
For example, during vector reallocation, exception guarantees
can affect whether moving or copying is preferred.
14. Why noexcept Matters for std::vector
Consider:
std::vector<Buffer> buffers;
When the vector grows, existing objects may need to be relocated.
If moving them is known to be non-throwing, the library can use
that information when choosing an appropriate relocation strategy.
Therefore:
noexcept move
      ↓
stronger exception guarantee
      ↓
better container behavior
15. std::is_nothrow_move_constructible
The standard library provides:
std::is_nothrow_move_constructible_v<T>
It checks whether T can be move-constructed without throwing.
Example:
static_assert(
    std::is_nothrow_move_constructible_v<MyClass>
);
16. Conditional Move Operations
A generic function may use:
noexcept(
    std::is_nothrow_move_constructible_v<T>
)
Example:
template<typename T>
void moveObject(T&& object)
    noexcept(
        std::is_nothrow_move_constructible_v<T>
    )
{
}
This allows the exception guarantee to depend on the type.
17. noexcept and Generic Programming
Generic code often cannot assume that operations are
non-throwing.
Therefore modern C++ uses traits such as:
std::is_nothrow_move_constructible_v<T>
and:
std::is_nothrow_copy_constructible_v<T>
to conditionally specify noexcept.
18. noexcept and Templates
Example:
template<typename T>
void process(T value)
    noexcept(
        std::is_nothrow_copy_constructible_v<T>
    )
{
}
The exception specification depends on T.
This is called a conditional noexcept specification.
19. noexcept and Perfect Forwarding
Day 10 introduced:
template<typename T>
void wrapper(T&& value)
{
    target(
        std::forward<T>(value)
    );
}
A production-quality wrapper can additionally describe
whether the forwarded operation is non-throwing.
Conceptually:
template<typename T>
void wrapper(T&& value)
    noexcept(
        noexcept(
            target(
                std::forward<T>(value)
            )
        )
    )
{
    target(
        std::forward<T>(value)
    );
}
This is an advanced but important pattern.
20. Connection With Day 11
Day 11:
template<typename... Args>
void wrapper(Args&&... args)
{
    target(
        std::forward<Args>(args)...
    );
}
Day 13 can add a conditional exception guarantee:
template<typename... Args>
void wrapper(Args&&... args)
    noexcept(
        noexcept(
            target(
                std::forward<Args>(args)...
            )
        )
    )
{
    target(
        std::forward<Args>(args)...
    );
}
This combines:
Variadic templates
Perfect forwarding
noexcept
This is a strong modern C++ pattern.
21. noexcept and Destructors
Destructors should generally not allow exceptions to escape.
Modern C++ destructors are effectively expected to be
non-throwing unless explicitly specified otherwise.
Example:
class Resource
{
public:

    ~Resource() noexcept
    {
        // cleanup
    }
};
Throwing from a destructor during stack unwinding can cause
program termination.
22. noexcept and RAII
RAII classes commonly perform cleanup in destructors.
Example:
class File
{
public:

    ~File() noexcept
    {
        // close file
    }
};
Cleanup should generally not throw.
This is important for reliable resource management.
23. noexcept vs throw()
Old C++ code may contain:
void foo() throw();
This was an older exception specification.
Modern C++ uses:
void foo() noexcept;
throw() was deprecated and eventually removed as a
general exception specification mechanism.
Use noexcept in modern C++.
24. Interview Questions
Q1. What is noexcept?
noexcept specifies that a function has a non-throwing
exception guarantee.
Example:
void foo() noexcept;
Q2. What happens if an exception escapes a noexcept function?
std::terminate() is called.
Q3. Does noexcept prevent exceptions from being thrown?
No.
A noexcept function can still execute code that attempts
to throw.
The important point is that an exception must not escape the
function.
Q4. What is the noexcept operator?
noexcept(expression)
checks whether an expression is known to be non-throwing.
It produces a compile-time boolean result.
Q5. Difference between:
void foo() noexcept;
and:
noexcept(foo());
The first is a function exception specification.
The second is the noexcept operator used to query an
expression.
Q6. What is conditional noexcept?
Example:
template<typename T>
void foo(T value)
    noexcept(std::is_nothrow_copy_constructible_v<T>)
{
}
The function is non-throwing depending on a compile-time
condition.
Q7. Why is noexcept important for move constructors?
A non-throwing move constructor allows standard library
containers to make better decisions when moving objects,
especially during reallocation.
Q8. What is std::is_nothrow_move_constructible_v<T>?
It is a type trait that determines whether T can be
move-constructed without throwing.
Q9. Should destructors throw exceptions?
Generally no.
Exceptions escaping destructors can lead to
std::terminate(), especially during stack unwinding.
Q10. What is the difference between noexcept and throw()?
throw() was an old exception specification.
Modern C++ uses noexcept.
Q11. Does noexcept improve performance?
It can enable better optimization and allows the standard
library to make stronger assumptions about exception safety.
However, its primary purpose is expressing exception
guarantees, not simply optimization.
Q12. Can a noexcept function call another throwing function?
Yes, but if that exception escapes the noexcept function,
std::terminate() is called.
25. Coding Questions
Question 1
What does this return?
void foo() noexcept
{
}

std::cout << noexcept(foo());
Answer:
true
Question 2
What does this return?
void foo()
{
}

std::cout << noexcept(foo());
Answer:
false
Question 3
What happens?
void foo() noexcept
{
    throw std::runtime_error("Error");
}

int main()
{
    try
    {
        foo();
    }
    catch (...)
    {
        std::cout << "Caught";
    }
}
The exception escapes the noexcept function, so
std::terminate() is called.
The normal catch does not get a chance to handle it.
26. Practical Exercises
Exercise 1
Create:
void safeFunction() noexcept;
and verify:
noexcept(safeFunction())
returns true.
Exercise 2
Create a throwing function and verify:
noexcept(riskyFunction())
returns false.
Exercise 3
Create a class with:
Class(Class&& other) noexcept;
and check:
std::is_nothrow_move_constructible_v<Class>
Exercise 4
Create a generic function with:
noexcept(
    std::is_nothrow_move_constructible_v<T>
)
Exercise 5
Combine Day 11 and Day 13:
template<typename... Args>
void wrapper(Args&&... args)
and add a conditional noexcept based on the forwarded
call.
27. Common Mistakes
Mistake 1
Using noexcept everywhere.
Don't.
Only promise non-throwing behavior when it is actually true.
Mistake 2
Thinking noexcept catches exceptions.
It does not.
It specifies exception behavior.
Mistake 3
Throwing from a noexcept function.
If the exception escapes:
std::terminate();
Mistake 4
Confusing:
noexcept
with:
noexcept(expression)
The first is commonly a specification.
The second queries whether an expression is non-throwing.
Mistake 5
Forgetting move constructors.
For production C++, understand why:
T(T&&) noexcept;
is important.
28. Production Pattern
A common modern pattern is:
class Buffer
{
public:

    Buffer(Buffer&& other) noexcept
        : data(other.data)
    {
        other.data = nullptr;
    }
};
The move operation transfers ownership without throwing.
This is especially important for resource-owning classes.
29. Day 13 Mental Model
                    noexcept
                       |
          +------------+------------+
          |            |            |
          v            v            v
      Function       Operator     Conditional
      Guarantee       Check       noexcept
          |            |            |
          +------------+------------+
                       |
                       v
                Exception Safety
                       |
                       v
                Move Operations
                       |
                       v
                    STL
30. Day 8 → Day 13 Connection
Day 08
Move Semantics
     ↓
Day 09
Rvalue References
     ↓
Day 10
Perfect Forwarding
     ↓
Day 11
Variadic Templates
     ↓
Day 12
constexpr
     ↓
Day 13
noexcept
These concepts are now starting to combine into
production-quality C++.
31. One-Minute Revision
Remember:
noexcept
→ function is non-throwing

noexcept(expr)
→ check whether expression is non-throwing

exception escaping noexcept
→ std::terminate()

conditional noexcept
→ noexcept(condition)

noexcept move constructor
→ important for STL/container behavior

is_nothrow_move_constructible_v<T>
→ checks whether T's move constructor is non-throwing
Most important syntax:
void foo() noexcept
{
}
noexcept(foo())
template<typename T>
void foo(T value)
    noexcept(
        std::is_nothrow_copy_constructible_v<T>
    )
{
}
32. Final Checklist
[ ] Understand noexcept
[ ] Understand non-throwing functions
[ ] Understand noexcept(expression)
[ ] Understand std::terminate()
[ ] Understand conditional noexcept
[ ] Understand is_nothrow_move_constructible
[ ] Understand noexcept move constructors
[ ] Understand destructors and exceptions
[ ] Understand RAII connection
[ ] Understand noexcept + templates
[ ] Understand noexcept + perfect forwarding
[ ] Understand noexcept + variadic templates
[ ] Complete project
[ ] Complete exercises
[ ] Practice interview questions
[ ] Practice coding questions
33. Next Day
Phase 2:
Day 13 — noexcept ✅
Next:
Day 14 — enum class

---

# 13. Git

After testing:

```bash
git add .
git commit -m "Complete Day 13 noexcept"
git push
Day 13 complete
Day 08  Move Semantics          ✅
Day 09  Rvalue References      ✅
Day 10  Perfect Forwarding     ✅
Day 11  Variadic Templates     ✅
Day 12  constexpr              ✅
Day 13  noexcept               ✅