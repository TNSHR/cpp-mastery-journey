// #pragma once

// #include <string>
// #include <iostream>
// #include <sstream>
// #include <utility>

// // ============================================================
// // Logger — plain class. Declaration only; defined in
// // VariadicDemo.cpp (same .h/.cpp split as Day 09 / Day 10).
// // ============================================================
// class Logger {
// public:
//     void logLine(const std::string& line);
// };

// // ============================================================
// // 1. Classic recursive variadic unpacking (works pre-C++17 too)
// // ============================================================
// // Base case: no arguments left. This ends the recursion. It has to
// // exist as a real overload, not just "the loop condition" — variadic
// // templates don't loop, they generate one function per call depth.
// inline void printAll() {
//     std::cout << "\n";
// }

// // Recursive case: peel off the first argument, print it, recurse on
// // "everything else" (Rest&&... rest). Each recursive call instantiates
// // a NEW template overload with one fewer parameter, until it bottoms
// // out at the zero-argument overload above. This is why a base case is
// // mandatory — without it, template instantiation never terminates.
// template <typename First, typename... Rest>
// void printAll(First&& first, Rest&&... rest) {
//     std::cout << first << " ";
//     printAll(std::forward<Rest>(rest)...);
// }

// // ============================================================
// // 2. Fold expressions (C++17) — same idea, no recursion needed
// // ============================================================
// // (args + ...) is a unary right fold: expands to
// // (arg1 + (arg2 + (arg3 + ... + argN)))
// template <typename... Args>
// auto sum(Args... args) {
//     return (args + ...);
// }

// // A fold over the comma operator is the idiomatic way to apply a side
// // effect (here: stream insertion) to every element of a pack without
// // writing a recursive helper at all. This combines directly with Day
// // 10's forwarding — Args&&... + std::forward is still correct inside
// // a fold.
// template <typename... Args>
// void logAll(Logger& logger, Args&&... args) {
//     std::ostringstream oss;
//     ((oss << std::forward<Args>(args) << " "), ...);   // left fold over comma
//     logger.logLine(oss.str());
// }

// // ============================================================
// // 3. sizeof... — pack size at compile time, zero runtime cost
// // ============================================================
// template <typename... Args>
// void reportPackSize(Args&&...) {
//     std::cout << "Pack has " << sizeof...(Args) << " argument(s)\n";
// }

#ifndef VARIADIC_DEMO_H
#define VARIADIC_DEMO_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>

class VariadicDemo
{
public:

    // ==========================================
    // Basic variadic printing
    // ==========================================

    template<typename... Args>
    static void printAll(const Args&... args)
    {
        (std::cout << ... << args) << '\n';
    }


    // ==========================================
    // Count arguments
    // ==========================================

    template<typename... Args>
    static constexpr std::size_t countArgs(
        const Args&...
    )
    {
        return sizeof...(Args);
    }


    // ==========================================
    // Sum
    // ==========================================

    template<typename... Args>
    static auto sum(Args... args)
    {
        return (args + ...);
    }


    // ==========================================
    // Sum with initial value
    // ==========================================

    template<typename... Args>
    static auto sumSafe(Args... args)
    {
        return (0 + ... + args);
    }


    // ==========================================
    // Product
    // ==========================================

    template<typename... Args>
    static auto product(Args... args)
    {
        return (args * ...);
    }


    // ==========================================
    // Recursive print
    // ==========================================

    static void recursivePrint();

    template<typename T, typename... Args>
    static void recursivePrint(
        T first,
        Args... rest
    )
    {
        std::cout
            << first
            << ' ';

        recursivePrint(rest...);
    }


    // ==========================================
    // Perfect forwarding
    // ==========================================

    template<typename... Args>
    static void forwardAll(Args&&... args)
    {
        printForwarded(
            std::forward<Args>(args)...
        );
    }


private:

    static void printForwarded();

    template<typename T, typename... Args>
    static void printForwarded(
        T&& first,
        Args&&... rest
    )
    {
        std::cout
            << first
            << ' ';

        printForwarded(
            std::forward<Args>(rest)...
        );
    }
};

#endif
