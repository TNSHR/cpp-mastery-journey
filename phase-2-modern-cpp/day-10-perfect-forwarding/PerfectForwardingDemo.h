#ifndef PERFECT_FORWARDING_DEMO_H
#define PERFECT_FORWARDING_DEMO_H

#include <string>
#include <utility>

class PerfectForwardingDemo
{
public:

    static void process(int& value);
    static void process(int&& value);

    static void process(
        const std::string& value
    );

    static void process(
        std::string&& value
    );

    template<typename T>
    static void badForward(T&& value)
    {
        process(value);
    }

    template<typename T>
    static void perfectForward(T&& value)
    {
        process(
            std::forward<T>(value)
        );
    }
};

#endif