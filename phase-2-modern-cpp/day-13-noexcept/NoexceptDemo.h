#ifndef NOEXCEPT_DEMO_H
#define NOEXCEPT_DEMO_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

class NoexceptDemo
{
public:

    // A function guaranteed not to throw
    static void safeFunction() noexcept
    {
        std::cout << "safeFunction() called\n";
    }


    // A function that may throw
    static void riskyFunction()
    {
        throw std::runtime_error(
            "Something went wrong"
        );
    }


    // noexcept can be checked using noexcept(...)
    static constexpr bool isSafe() noexcept
    {
        return true;
    }


    // Conditional noexcept
    template<typename T>
    static void process(T value)
        noexcept(std::is_nothrow_copy_constructible_v<T>)
    {
        std::cout
            << "Processing value: "
            << value
            << '\n';
    }


    // Demonstrates noexcept with move operations
    template<typename T>
    static void moveObject(T&& object)
        noexcept(noexcept(
            T(std::forward<T>(object))
        ))
    {
        std::cout
            << "Object moved/constructed\n";
    }
};

#endif