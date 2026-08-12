# Phase 2 - Day 6
# Smart Pointers - std::shared_ptr

---

# Objective

Learn shared ownership in Modern C++ using `std::shared_ptr`.

Understand:

- Smart pointers
- Shared ownership
- Reference counting
- `std::shared_ptr`
- `std::make_shared()`
- `use_count()`
- `reset()`
- `get()`
- Control block
- RAII
- `unique_ptr` vs `shared_ptr`
- Common mistakes
- Best practices
- Interview questions

---

# 1. What is std::shared_ptr?

`std::shared_ptr` is a smart pointer that allows multiple
owners to manage the same dynamically allocated object.

Example:

```cpp
auto employee =
    std::make_shared<Employee>(
        101,
        "Shrinath",
        50000
    );