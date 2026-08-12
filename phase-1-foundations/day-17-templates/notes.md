# Day 17 – Templates

## Objective

Learn Generic Programming using Function Templates and Class Templates.

---

## Why Templates?

Templates remove duplicate code by allowing one implementation to work with multiple datatypes.

---

## Generic Programming

Write once.

Reuse for many datatypes.

---

## Function Template

```cpp
template<typename T>
T add(T a, T b)
{
    return a + b;
}
```