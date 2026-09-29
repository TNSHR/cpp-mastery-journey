






    1. What Is constexpr?
constexpr means:
This expression/function is capable of being evaluated at compile time.

The key word is capable.
It does not mean that every call to a constexpr function must happen at compile time.
Example:
constexpr int square(int x)
{
    return x * x;
}
If:
constexpr int x = square(5);
then the compiler can calculate:
5 × 5 = 25
during compilation.
2. Why Do We Need constexpr?
Consider:
int square(int x)
{
    return x * x;
}
This normally represents a runtime function.
With:
constexpr int square(int x)
{
    return x * x;
}
the function can participate in compile-time computation.
This is useful for:
compile-time constants
array sizes
template arguments
embedded programming
optimization
lookup tables
configuration values
generic programming
3. const vs constexpr
This is an important interview topic.
const
const int x = 10;
means:
x cannot be modified after initialization.

constexpr
constexpr int x = 10;
means:
x is a constant expression and must be initialized with a compile-time constant expression.

So:
const
↓
read-only object

constexpr
↓
compile-time constant expression
4. Example
int value = 10;

const int a = value;
This can be valid.
But:
int value = 10;

constexpr int b = value;
is invalid because value is not a compile-time constant expression.
Instead:
constexpr int value = 10;

constexpr int b = value;
is valid.
5. First constexpr Function
constexpr int square(int x)
{
    return x * x;
}
Then:
constexpr int result = square(5);
The compiler can evaluate:
square(5)
↓
25
during compilation.
6. Compile-Time vs Runtime Call
This is extremely important.
Consider:
constexpr int square(int x)
{
    return x * x;
}
This can be used both ways.
Compile time
constexpr int a = square(10);
Runtime
int x;

std::cin >> x;

int b = square(x);
The second call cannot be evaluated at compile time because x is known only at runtime.
But the function is still perfectly valid.
Therefore:
constexpr function
        ↓
CAN execute at compile time
        +
CAN execute at runtime
7. constexpr Does Not Mean "Always Compile Time"
This is one of the most common interview traps.
Wrong statement:
"constexpr means the function always executes at compile time."

Correct:
A constexpr function can be evaluated at compile time when its arguments and context permit it.

8. Create Day 12 Folder
Go to:
cd ~/cpp-mastery-journey/cpp-mastery-journey/phase-2-modern-cpp
Create:
mkdir -p day-12-constexpr/build
cd day-12-constexpr
Create:
touch ConstexprDemo.h
touch ConstexprDemo.cpp
touch main.cpp
touch notes.md
Structure:
day-12-constexpr/
├── build/
├── ConstexprDemo.h
├── ConstexprDemo.cpp
├── main.cpp
└── notes.md
9. constexpr Variables
Example:
constexpr int MAX_STUDENTS = 100;
This is a compile-time constant.
Another example:
constexpr double PI = 3.141592653589793;
You cannot modify it.
PI = 4.0;
is invalid.
10. Compile-Time Array Size
One practical use:
constexpr int SIZE = 10;

int data[SIZE];
SIZE is known during compilation.
This is especially relevant to embedded programming.
For example:
constexpr int BUFFER_SIZE = 256;

char buffer[BUFFER_SIZE];
This is a very common pattern.
11. constexpr Function
Let's create:
constexpr int multiply(int a, int b)
{
    return a * b;
}
Then:
constexpr int result = multiply(6, 7);
The compiler can calculate:
42
at compile time.
12. constexpr Function Requirements
Modern C++ has progressively relaxed the restrictions on
constexpr functions.
In older C++ standards, constexpr functions were highly
restricted.
Modern C++ allows much more:
constexpr int calculate(int x)
{
    int result = x * 2;

    if (result > 10)
    {
        result += 5;
    }

    return result;
}
Compile with:
-std=c++17
13. C++11 vs C++14 vs C++17
Historically:
C++11
constexpr functions were very restrictive.
C++14
Allowed:
local variables
loops
more complex control flow
C++17
Further improved compile-time programming and introduced:
if constexpr
This is the version we will use in our project.
14. if constexpr
This is one of the most important modern C++ features.
Normal:
if (condition)
{
}
is runtime branching.
if constexpr:
if constexpr (condition)
{
}
is compile-time branching.
15. Example
template<typename T>
void process(T value)
{
    if constexpr (std::is_integral_v<T>)
    {
        std::cout << "Integer\n";
    }
    else
    {
        std::cout << "Not integer\n";
    }
}
For:
process(10);
the compiler selects the integer branch.
For:
process(3.14);
the other branch is selected.
16. Why if constexpr Matters
Consider:
template<typename T>
void process(T value)
{
    if constexpr (std::is_integral_v<T>)
    {
        // integer-specific code
    }
    else
    {
        // other code
    }
}
The unused branch is discarded during compilation.
This is different from normal runtime if.
17. Connection to Day 11
Day 11 taught:
template<typename... Args>
Today:
if constexpr
allows compile-time decisions while processing generic types.
These two features are frequently used together in modern
generic C++.
For example:
template<typename... Args>
void process(Args... args)
{
    if constexpr (sizeof...(Args) > 0)
    {
        // process arguments
    }
}
18. Build the Project
Open:
nano ConstexprDemo.h
Use:
#ifndef CONSTEXPR_DEMO_H
#define CONSTEXPR_DEMO_H

#include <iostream>
#include <type_traits>

class ConstexprDemo
{
public:

    static constexpr int MAX_BUFFER_SIZE = 256;

    static constexpr int square(int value)
    {
        return value * value;
    }

    static constexpr int factorial(int value)
    {
        int result = 1;

        for (int i = 1; i <= value; ++i)
        {
            result *= i;
        }

        return result;
    }

    static constexpr bool isEven(int value)
    {
        return value % 2 == 0;
    }

    static constexpr int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    template<typename T>
    static void describeType(const T&)
    {
        if constexpr (std::is_integral_v<T>)
        {
            std::cout << "Integral type\n";
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            std::cout << "Floating-point type\n";
        }
        else
        {
            std::cout << "Other type\n";
        }
    }
};

#endif
19. Why factorial() Is Interesting
We have:
static constexpr int factorial(int value)
{
    int result = 1;

    for (int i = 1; i <= value; ++i)
    {
        result *= i;
    }

    return result;
}
Because we're compiling with C++17, the function can perform
more complex compile-time calculations than early C++11
constexpr functions could.
Then:
constexpr int result =
    ConstexprDemo::factorial(5);
can become:
120
at compile time.
20. ConstexprDemo.cpp
Open:
nano ConstexprDemo.cpp
Put:
#include "ConstexprDemo.h"
That's all we need here because the functions are defined
inside the header.
21. main.cpp
Open:
nano main.cpp
Use:
#include <iostream>

#include "ConstexprDemo.h"

int main()
{
    std::cout
        << "====================================\n";

    std::cout
        << "      C++ constexpr Demo\n";

    std::cout
        << "====================================\n";


    // =========================================
    // 1. constexpr variable
    // =========================================

    constexpr int size = 10;

    int data[size];

    std::cout
        << "\nArray size: "
        << size
        << '\n';


    // =========================================
    // 2. Compile-time square
    // =========================================

    constexpr int square =
        ConstexprDemo::square(10);

    std::cout
        << "Square: "
        << square
        << '\n';


    // =========================================
    // 3. Compile-time factorial
    // =========================================

    constexpr int factorial =
        ConstexprDemo::factorial(5);

    std::cout
        << "Factorial: "
        << factorial
        << '\n';


    // =========================================
    // 4. Compile-time even check
    // =========================================

    constexpr bool even =
        ConstexprDemo::isEven(20);

    std::cout
        << "20 is even: "
        << std::boolalpha
        << even
        << '\n';


    // =========================================
    // 5. Compile-time max
    // =========================================

    constexpr int maximum =
        ConstexprDemo::max(
            100,
            200
        );

    std::cout
        << "Maximum: "
        << maximum
        << '\n';


    // =========================================
    // 6. Runtime constexpr function
    // =========================================

    int runtimeValue;

    std::cout
        << "\nEnter a number: ";

    std::cin
        >> runtimeValue;

    int runtimeSquare =
        ConstexprDemo::square(
            runtimeValue
        );

    std::cout
        << "Runtime square: "
        << runtimeSquare
        << '\n';


    // =========================================
    // 7. if constexpr
    // =========================================

    std::cout
        << "\nType information:\n";

    ConstexprDemo::describeType(10);

    ConstexprDemo::describeType(3.14);

    ConstexprDemo::describeType("C++");


    // =========================================
    // 8. End
    // =========================================

    std::cout
        << "\nProgram completed.\n";

    return 0;
}
22. Compile
Run:
g++ -std=c++17 -Wall -Wextra -pedantic \
main.cpp \
ConstexprDemo.cpp \
-o build/main
Then:
./build/main
23. Expected Output
For input:
5
you should see approximately:
====================================
      C++ constexpr Demo
====================================

Array size: 10
Square: 100
Factorial: 120
20 is even: true
Maximum: 200

Enter a number: 5
Runtime square: 25

Type information:
Integral type
Floating-point type
Other type

Program completed.
24. Important Observation
This:
constexpr int square =
    ConstexprDemo::square(10);
is compile-time capable.
But:
int runtimeValue;

std::cin >> runtimeValue;

int result =
    ConstexprDemo::square(runtimeValue);
is runtime.
The same constexpr function can participate in both.
That distinction is critical.
25. consteval
C++20 introduced:
consteval
A consteval function must be evaluated at compile time.
Example:
consteval int square(int x)
{
    return x * x;
}
This is different from:
constexpr int square(int x)
{
    return x * x;
}
constexpr
compile time if possible
runtime if necessary
consteval
compile time only
This distinction is an excellent interview topic.
26. constinit
Another C++20 keyword:
constinit
is used to ensure static/thread-storage-duration variables
are initialized during static initialization.
It is related to compile-time initialization but is not
the same thing as constexpr.
For Day 12, remember the distinction:
constexpr
→ constant expression

consteval
→ immediate function

constinit
→ guaranteed static initialization
We will not go deeply into consteval and constinit yet;
our curriculum today is specifically constexpr.
27. constexpr Class Member
A class can have:
static constexpr int MAX_SIZE = 256;
Example:
class Buffer
{
public:

    static constexpr int MAX_SIZE = 256;
};
Then:
int buffer[
    Buffer::MAX_SIZE
];
This is especially useful in embedded systems.
28. constexpr Constructors
Modern C++ also allows constructors to be constexpr.
Example:
class Point
{
private:

    int x;
    int y;

public:

    constexpr Point(
        int xValue,
        int yValue
    )
        : x(xValue),
          y(yValue)
    {
    }

    constexpr int getX() const
    {
        return x;
    }

    constexpr int getY() const
    {
        return y;
    }
};
Then:
constexpr Point p(10, 20);
can be created at compile time.
29. Why This Matters
Compile-time objects can be useful for:
configuration
lookup tables
embedded systems
mathematical constants
protocol definitions
static configuration
generic programming
30. Embedded C++ Connection
This is particularly important for your later:
Phase 3 — Embedded C++
Suppose:
constexpr int UART_BUFFER_SIZE = 128;
constexpr int ADC_MAX_VALUE = 4095;
constexpr int PWM_FREQUENCY = 1000;
These values can be compile-time constants.
Example:
constexpr int BUFFER_SIZE = 128;

uint8_t uartBuffer[BUFFER_SIZE];
This avoids unnecessary runtime configuration for values
that are known during compilation.
31. Why constexpr Is Important for Embedded Systems
Embedded systems often have:
limited RAM
limited CPU
predictable timing requirements
fixed hardware configuration
static buffers
compile-time configuration
Therefore compile-time computation can be valuable.
Example:
constexpr int calculatePrescaler(
    int clock,
    int target
)
{
    return clock / target;
}
Then:
constexpr int prescaler =
    calculatePrescaler(
        16000000,
        1000
    );
The calculation can happen during compilation.
32. constexpr and Optimization
Do not say:
"constexpr always makes code faster."

That is too simplistic.
A better statement:
constexpr allows certain computations to be performed at compile time, potentially eliminating runtime work.

The compiler can then generate code using the already-computed
value.
33. Interview Question — const vs constexpr
Q: What is the difference?
const means an object cannot be modified after initialization.
constexpr means the value is required to be a constant
expression where applicable and can be evaluated at compile time.
Example:
const int a = runtimeFunction();
may be valid.
But:
constexpr int b = runtimeFunction();
requires the initializer to be a valid constant expression.
34. Interview Question
Does constexpr guarantee compile-time execution?
No.
A constexpr function can also execute at runtime when called
with runtime values.
35. Interview Question
What is if constexpr?
if constexpr is a compile-time conditional introduced in
C++17.
Example:
if constexpr (std::is_integral_v<T>)
{
}
The compiler selects the appropriate branch based on the
compile-time condition.
36. Interview Question
Why is if constexpr useful with templates?
Because it allows type-dependent code to be selected during
compilation.
The discarded branch does not need to be instantiated in the
same way as a normal runtime if.
This makes generic code much easier to write.
37. Interview Question
What is the difference between constexpr and consteval?
constexpr
→ can execute at compile time or runtime

consteval
→ must execute at compile time
consteval was introduced in C++20.
38. Interview Question
What is a constant expression?
A constant expression is an expression whose value can be
determined during compilation and which satisfies the language
rules for use where a compile-time constant is required.
Examples:
constexpr int x = 10;

constexpr int y = x * 2;
39. Interview Question
Can a constexpr function contain loops?
In modern C++, yes.
For example:
constexpr int factorial(int n)
{
    int result = 1;

    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }

    return result;
}
Modern C++ relaxed the restrictions that existed in C++11.
40. Interview Question
What C++ version introduced if constexpr?
C++17.
41. Interview Question
What C++ version introduced consteval?
C++20.
42. Interview Question
Why is constexpr useful in embedded programming?
It allows values and calculations known at compile time to be
computed during compilation, which can reduce runtime work and
help create fixed-size, predictable configurations.
43. Coding Question
What is the result?
constexpr int square(int x)
{
    return x * x;
}

constexpr int result = square(5);
Answer:
25
44. Coding Question
Is this valid?
int x = 10;

constexpr int y = x;
No.
x is not a compile-time constant expression.
45. Coding Question
Is this valid?
constexpr int x = 10;

constexpr int y = x * 2;
Yes.
The compiler can determine:
20
at compile time.
46. Coding Question
What does this do?
template<typename T>
void process(T value)
{
    if constexpr (std::is_integral_v<T>)
    {
        std::cout << "Integer";
    }
    else
    {
        std::cout << "Other";
    }
}
For:
process(10);
output:
Integer
For:
process(3.14);
output:
Other
47. Practical Exercises
Exercise 1 — Compile-Time Square
Create:
constexpr int square(int x)
Then:
constexpr int result = square(12);
Expected:
144
Exercise 2 — Compile-Time Cube
Create:
constexpr int cube(int x)
Test:
constexpr int result = cube(5);
Expected:
125
Exercise 3 — Factorial
Create:
constexpr int factorial(int n)
Test:
constexpr int result = factorial(6);
Expected:
720
Exercise 4 — Maximum
Create:
constexpr int max(
    int a,
    int b
)
Test:
constexpr int result =
    max(
        100,
        250
    );
Expected:
250
Exercise 5 — Power
Create:
constexpr int power(
    int base,
    int exponent
)
Test:
constexpr int result =
    power(
        2,
        10
    );
Expected:
1024
Exercise 6 — if constexpr
Create:
template<typename T>
void inspect(T value)
Use:
if constexpr
to distinguish:
integer
floating point
other
48. Important Day 11 → Day 12 Connection
Day 11:
template<typename... Args>
gave us compile-time knowledge about:
number of arguments
types of arguments
Day 12:
constexpr
allows us to perform certain computations using compile-time
information.
Together:
Templates
   ↓
Compile-Time Types
   ↓
constexpr
   ↓
Compile-Time Computation
49. Day 12 Mental Model
                 constexpr
                     |
          +----------+----------+
          |          |          |
          v          v          v
       Values     Functions    Classes
          |          |          |
          v          v          v
       Compile   Compile-Time  Compile-
        Time      Evaluation    Time
       Constants              Objects
          |
          v
      Optimization
          |
          v
 Embedded / Generic / High Performance C++
50. Day 12 Checklist
[ ] Understand constexpr

[ ] Understand constexpr variables

[ ] Understand constexpr functions

[ ] Understand compile-time evaluation

[ ] Understand runtime evaluation of constexpr functions

[ ] Understand const vs constexpr

[ ] Understand constant expressions

[ ] Understand constexpr member functions

[ ] Understand constexpr static members

[ ] Understand constexpr constructors

[ ] Understand if constexpr

[ ] Understand template + if constexpr

[ ] Understand C++11 constexpr restrictions

[ ] Understand C++14 improvements

[ ] Understand C++17 improvements

[ ] Know what consteval is

[ ] Know what constinit is

[ ] Understand embedded-system applications

[ ] Complete constexpr project

[ ] Complete exercises

[ ] Practice interview questions
51. One-Minute Interview Revision
Remember these:
constexpr
↓
compile-time capable

const
↓
read-only

constexpr function
↓
can run at compile time or runtime

if constexpr
↓
compile-time branch

C++17
↓
if constexpr

C++20
↓
consteval

consteval
↓
must execute at compile time
Most important:
constexpr int square(int x)
{
    return x * x;
}
And:
template<typename T>
void process(T value)
{
    if constexpr (std::is_integral_v<T>)
    {
        // integer branch
    }
}
52. Phase 2 Progress
Day 01  auto Keyword                    ✅
Day 02  nullptr & nullptr_t             ✅
Day 03  Range Based For Loops            ✅
Day 04  Lambda Expressions              ✅
Day 05  unique_ptr                       ✅
Day 06  shared_ptr                       ✅
Day 07  weak_ptr                         ✅
Day 08  Move Semantics                   ✅
Day 09  Rvalue References                ✅
Day 10  Perfect Forwarding               ✅
Day 11  Variadic Templates               ✅
Day 12  constexpr                        ✅
👉 Day 13  noexcept