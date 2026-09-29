Replace the entire file with:
# C++ Mastery Journey
# Phase 2 — Modern C++
# Day 14 — enum class

---

## 1. Day Objective

Understand modern C++ scoped enumerations using `enum class`.

Key goals:

- Understand traditional `enum`
- Understand `enum class`
- Understand scoped enumerators
- Understand strong type safety
- Understand implicit vs explicit conversion
- Understand underlying types
- Use `enum class` with `switch`
- Use `enum class` in classes
- Understand practical and embedded-system applications

---

# 2. What Is an Enumeration?

An enumeration represents a fixed set of named values.

Example:

```cpp
enum Status
{
    Pending,
    Processing,
    Completed,
    Failed
};
Instead of using:
int status = 0;
we can use:
Status status = Pending;
This makes the code more readable.
3. Traditional enum Problems
Traditional enums have two important weaknesses.
3.1 Names are not strongly scoped
Example:
enum Status
{
    Pending,
    Completed
};
The enumerators can be accessed directly:
Pending
Completed
This can cause naming conflicts.
Example:
enum Status
{
    Pending,
    Completed
};

enum TaskStatus
{
    Pending,
    Failed
};
Both enums try to introduce Pending into the same scope.
3.2 Implicit conversion to integer
Traditional enums can implicitly convert to integers.
Example:
enum Status
{
    Pending,
    Completed
};

int value = Pending;
This can be legal.
The conversion can sometimes happen accidentally.
4. enum class
C++11 introduced scoped enumerations:
enum class Status
{
    Pending,
    Processing,
    Completed,
    Failed
};
Values must be accessed using the enum type:
Status::Pending
Status::Processing
Status::Completed
Status::Failed
This provides stronger type safety.
5. Basic Example
enum class Status
{
    Pending,
    Processing,
    Completed,
    Failed
};
Create a variable:
Status status =
    Status::Pending;
Change it:
status =
    Status::Completed;
Compare it:
if (status == Status::Completed)
{
    // completed
}
6. Scoped Enumerators
With:
enum class Status
{
    Pending,
    Completed
};
we use:
Status::Pending
Status::Completed
We cannot simply write:
Pending
in normal code.
The enum values are scoped inside Status.
7. Strong Type Safety
Consider:
enum class Status
{
    Pending,
    Completed
};

enum class Priority
{
    Low,
    High
};
This is valid:
Status status =
    Status::Pending;
This is also valid:
Priority priority =
    Priority::High;
But this is invalid:
status = Priority::High;
because Status and Priority are different types.
This prevents accidental mixing of unrelated values.
8. enum class vs Traditional enum
Traditional:
enum Color
{
    Red,
    Green,
    Blue
};
Scoped:
enum class Color
{
    Red,
    Green,
    Blue
};
Usage:
Color color = Color::Red;
9. Comparison
Feature	enum	enum class
Scoped enumerators	No	Yes
Strong type safety	Lower	Higher
Implicit conversion to integer	Yes	No
Values accessed with scope	Not required	Required
Naming conflicts	More likely	Less likely
Modern C++ preference	Usually avoid for new code	Preferred


10. Integer Conversion
This is invalid:
enum class Status
{
    Pending,
    Completed
};

int value = Status::Pending;
enum class does not implicitly convert to int.
Use explicit conversion:
int value =
    static_cast<int>(
        Status::Pending
    );
The conversion is now intentional.
11. Why Explicit Conversion Is Better
Consider:
int value =
    static_cast<int>(
        Status::Completed
    );
The code clearly communicates:
I intentionally want the underlying numeric value.

This avoids accidental conversions.
12. Underlying Type
An enum has an underlying integral type.
You can explicitly specify it:
enum class Status : int
{
    Pending,
    Processing,
    Completed,
    Failed
};
Or:
enum class Status : unsigned char
{
    Pending,
    Processing,
    Completed,
    Failed
};
For fixed-width integer types:
#include <cstdint>

enum class Status : std::uint8_t
{
    Pending,
    Processing,
    Completed,
    Failed
};
13. Why Specify an Underlying Type?
It can be useful when:
memory representation matters
interfacing with hardware
binary protocols are involved
serialization is required
ABI/layout needs to be controlled
embedded systems use compact state values
Example:
enum class GPIOState : std::uint8_t
{
    Low,
    High
};
This is useful in embedded programming.
14. enum class With switch
enum class works naturally with switch.
Example:
enum class Status
{
    Pending,
    Processing,
    Completed,
    Failed
};

Status status =
    Status::Processing;

switch (status)
{
    case Status::Pending:
        // ...
        break;

    case Status::Processing:
        // ...
        break;

    case Status::Completed:
        // ...
        break;

    case Status::Failed:
        // ...
        break;
}
Each case explicitly identifies the enum type.
15. enum class in a Class
Example:
class Job
{
public:

    enum class Status
    {
        Pending,
        Running,
        Completed,
        Failed
    };

private:

    Status status =
        Status::Pending;
};
The enumeration is scoped inside the class.
Access from outside:
Job::Status::Completed
16. Practical Example — Payout System
A production system can use:
enum class PayoutStatus
{
    Pending,
    Processing,
    Completed,
    Failed
};
Instead of:
int status = 0;
Then:
PayoutStatus status =
    PayoutStatus::Processing;
This makes invalid states harder to represent accidentally.
17. Practical Example — Network State
enum class ConnectionState
{
    Disconnected,
    Connecting,
    Connected,
    Error
};
Usage:
ConnectionState state =
    ConnectionState::Connected;
18. Practical Example — Embedded System
#include <cstdint>

enum class MotorState : std::uint8_t
{
    Stopped,
    Starting,
    Running,
    Fault
};
Then:
MotorState state =
    MotorState::Running;
This is preferable to:
std::uint8_t state = 2;
because the enum communicates what 2 actually means.
19. enum class and Functions
A function can accept an enum class:
void processStatus(
    Status status
)
{
    if (status == Status::Completed)
    {
        // ...
    }
}
This prevents unrelated enum types from being passed.
20. enum class and Return Values
Functions can return enum classes:
Status getStatus()
{
    return Status::Completed;
}
This is clearer than:
int getStatus()
{
    return 2;
}
The caller knows what the returned value represents.
21. enum class and switch
A common production pattern:
Status status =
    Status::Processing;

switch (status)
{
    case Status::Pending:
        break;

    case Status::Processing:
        break;

    case Status::Completed:
        break;

    case Status::Failed:
        break;
}
This is often clearer and safer than using integer constants.
22. enum class Does Not Automatically Print
This does not normally work:
std::cout << Status::Pending;
because enum class does not implicitly convert to an integer
for stream output.
You can explicitly convert:
std::cout
    << static_cast<int>(
        Status::Pending
    );
Or, preferably, create a conversion function:
std::string toString(Status status)
{
    switch (status)
    {
        case Status::Pending:
            return "Pending";

        case Status::Completed:
            return "Completed";
    }

    return "Unknown";
}
Then:
std::cout << toString(Status::Pending);
23. enum class and Comparison
Enum values of the same enum type can be compared:
if (status == Status::Completed)
{
}
You can also use:
if (status != Status::Failed)
{
}
But unrelated enum classes cannot be compared directly.
24. enum class and Arithmetic
This is not normally allowed:
Status status =
    Status::Pending;

int x = status + 1;
Unlike traditional enums, enum class does not freely participate
in arithmetic operations.
If you genuinely need the underlying integer:
int x =
    static_cast<int>(status);
25. enum class and enum struct
These are equivalent:
enum class Status
{
    Pending,
    Completed
};
and:
enum struct Status
{
    Pending,
    Completed
};
enum class is more commonly used.
26. Anonymous enum
Older C++ code may contain:
enum
{
    BUFFER_SIZE = 256
};
Modern C++ generally has better alternatives depending on
the purpose:
constexpr int BUFFER_SIZE = 256;
or an appropriately scoped enum.
27. enum class vs constexpr
Do not confuse them.
constexpr is mainly about compile-time constants and
evaluation.
constexpr int MAX_SIZE = 256;
enum class represents a fixed set of named states/choices.
enum class Status
{
    Pending,
    Completed
};
They solve different problems.
28. enum class vs #define
Avoid:
#define STATUS_PENDING 0
#define STATUS_COMPLETED 1
Prefer:
enum class Status
{
    Pending,
    Completed
};
Advantages:
type safety
scope
debugger-friendly names
no macro substitution
better compiler checking
29. Common Mistake #1
Wrong:
enum class Status
{
    Pending,
    Completed
};

Status status = Pending;
Correct:
Status status =
    Status::Pending;
30. Common Mistake #2
Wrong:
int value = Status::Pending;
Correct:
int value =
    static_cast<int>(
        Status::Pending
    );
31. Common Mistake #3
Mixing different enum classes:
enum class Status
{
    Pending,
    Completed
};

enum class Priority
{
    Low,
    High
};

Status status =
    Priority::High;
This is invalid.
The two values belong to different types.
32. Common Mistake #4
Using integer states everywhere:
int state = 2;
The reader has no idea what 2 means.
Prefer:
enum class State
{
    Idle,
    Running,
    Completed
};

State state =
    State::Completed;
33. Interview Questions
Q1. What is enum class?
enum class is a scoped, strongly typed enumeration introduced
in C++11.
Example:
enum class Status
{
    Pending,
    Completed
};
Q2. Why is enum class preferred over traditional enum?
Main reasons:
scoped enumerator names
stronger type safety
no implicit conversion to integers
fewer naming conflicts
Q3. What is the difference between enum and enum class?
Traditional enum has weaker type safety and its enumerators can
be introduced into the surrounding scope.
enum class scopes its enumerators and does not implicitly
convert to integers.
Q4. How do you access an enum class value?
Status::Pending
not:
Pending
Q5. Can enum class convert to int implicitly?
No.
Use:
static_cast<int>(
    Status::Pending
);
for explicit conversion.
Q6. Can an enum class have an underlying type?
Yes.
Example:
enum class Status : std::uint8_t
{
    Pending,
    Completed
};
Q7. Why specify an underlying type?
It can provide predictable representation and can be useful
for memory-sensitive code, embedded systems, protocols, and
serialization.
Q8. Can enum class values be used in switch?
Yes.
Example:
switch (status)
{
    case Status::Pending:
        break;

    case Status::Completed:
        break;
}
Q9. Can two enum classes be assigned to each other?
No.
Different enum classes are different types.
Q10. Can enum class values be printed directly using cout?
Normally no.
Use an explicit conversion or a custom string conversion
function.
Q11. What is the difference between enum class and enum struct?
For enumeration declarations, they provide the same scoped
strongly typed behavior.
enum class is more commonly used.
Q12. Which C++ version introduced enum class?
C++11.
34. Coding Interview Questions
Question 1
What is wrong?
enum class Color
{
    Red,
    Blue
};

Color color = Red;
Answer:
Red must be accessed through the enum scope:
Color color =
    Color::Red;
Question 2
Is this valid?
enum class Status
{
    Pending,
    Completed
};

int value = Status::Pending;
No.
Use:
int value =
    static_cast<int>(
        Status::Pending
    );
Question 3
What is the type of:
Status::Pending
It is:
Status
not simply int.
Question 4
Why is this invalid?
enum class Status
{
    Pending,
    Completed
};

enum class Priority
{
    Low,
    High
};

Status status =
    Priority::High;
Because Status and Priority are distinct types.
35. Practical Exercises
Exercise 1 — Device State
Create:
enum class DeviceState
{
    Off,
    Starting,
    Running,
    Error
};
Use a switch to print each state.
Exercise 2 — HTTP Status
Create:
enum class HttpStatus
{
    OK,
    BadRequest,
    Unauthorized,
    NotFound,
    ServerError
};
Create:
std::string toString(
    HttpStatus status
);
Exercise 3 — Embedded GPIO
Create:
enum class GPIOState : std::uint8_t
{
    Low,
    High
};
Explicitly convert the enum value to an integer and print it.
Exercise 4 — Payout State
Create:
enum class PayoutStatus
{
    Pending,
    Processing,
    Completed,
    Failed
};
Write:
bool isSuccessful(
    PayoutStatus status
);
Return true only for Completed.
Exercise 5 — Compare Enum Classes
Create two unrelated enum classes and demonstrate that they
cannot be assigned to each other.
36. Production Perspective
Prefer:
enum class ConnectionState
{
    Disconnected,
    Connecting,
    Connected,
    Error
};
over:
int state = 2;
The first communicates intent directly.
This becomes especially important in:
embedded systems
networking
state machines
payment systems
robotics
device drivers
GUI applications
protocol handling
37. Embedded C++ Connection
Later in Phase 3, you may use:
enum class MotorState : std::uint8_t
{
    Stopped,
    Starting,
    Running,
    Fault
};
or:
enum class GPIOState : std::uint8_t
{
    Low,
    High
};
This gives readable state names while allowing a compact
underlying representation.
38. Day 14 Connection to Previous Days
Day 11
Variadic Templates
        ↓
Day 12
constexpr
        ↓
Day 13
noexcept
        ↓
Day 14
enum class
The focus is moving from generic programming and exception
behavior toward safer type representation.
39. Key Syntax to Remember
Declaration
enum class Status
{
    Pending,
    Processing,
    Completed,
    Failed
};
Variable
Status status =
    Status::Pending;
Comparison
if (status == Status::Completed)
{
}
Switch
switch (status)
{
    case Status::Pending:
        break;

    case Status::Completed:
        break;
}
Explicit integer conversion
int value =
    static_cast<int>(
        Status::Pending
    );
Explicit underlying type
enum class Status : std::uint8_t
{
    Pending,
    Completed
};
40. One-Minute Revision
Remember:
enum class
    ↓
scoped + strongly typed enum

Status::Pending
    ↓
correct access

No implicit int conversion
    ↓
static_cast<int>(Status::Pending)

Different enum classes
    ↓
different types

enum class : std::uint8_t
    ↓
explicit underlying type
41. Day 14 Checklist
[ ] Understand traditional enum
[ ] Understand enum class
[ ] Understand scoped enumerators
[ ] Understand strong type safety
[ ] Understand implicit conversion restrictions
[ ] Understand static_cast
[ ] Understand underlying types
[ ] Understand enum class with switch
[ ] Understand enum class inside classes
[ ] Understand enum class with functions
[ ] Understand enum class in state machines
[ ] Understand embedded-system usage
[ ] Complete EnumClassDemo project
[ ] Complete practical exercises
[ ] Practice interview questions
[ ] Practice coding questions
42. Phase 2 Progress
Day 01 — auto Keyword                 ✅
Day 02 — nullptr & nullptr_t          ✅
Day 03 — Range-Based For              ✅
Day 04 — Lambda Expressions            ✅
Day 05 — unique_ptr                    ✅
Day 06 — shared_ptr                    ✅
Day 07 — weak_ptr                      ✅
Day 08 — Move Semantics                ✅
Day 09 — Rvalue References             ✅
Day 10 — Perfect Forwarding            ✅
Day 11 — Variadic Templates            ✅
Day 12 — constexpr                     ✅
Day 13 — noexcept                      ✅
Day 14 — enum class                    ✅
NEXT:
Day 15 — Type Inference
43. Final Interview Answer
If asked:
"What is enum class and why do we use it?"
Answer:
enum class is a scoped and strongly typed enumeration
introduced in C++11. Unlike traditional enums, its
enumerators are scoped and it does not implicitly convert
to integers. This improves type safety, prevents naming
conflicts, and makes code more expressive. An underlying
type can also be explicitly specified when required, which
is useful in areas such as embedded systems and binary
protocols.


Save:

```text
Ctrl+O
Enter
Ctrl+X
Verify:
wc -l notes.md
Then Day 14 is fully complete:
Phase 1 — Folder & Files       ✅
Phase 2 — Code & Concepts      ✅
Phase 3 — notes.md             ✅