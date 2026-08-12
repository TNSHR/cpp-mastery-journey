# Phase 2 - Day 7
# std::weak_ptr

---

# Objective

Learn `std::weak_ptr` and understand how it differs from:

- `std::unique_ptr`
- `std::shared_ptr`

Main topics:

- Non-owning ownership model
- `std::weak_ptr`
- `lock()`
- `expired()`
- Reference counting
- Shared ownership vs observation
- Reference cycles
- Control block
- `shared_ptr` + `weak_ptr`
- RAII
- Smart pointer best practices
- Interview questions

---

# 1. What is std::weak_ptr?

`std::weak_ptr` is a smart pointer that provides
non-owning access to an object managed by `shared_ptr`.

Example:

```cpp
auto employee =
    std::make_shared<Employee>(
        101,
        "Shrinath",
        50000
    );

std::weak_ptr<Employee> observer = employee;