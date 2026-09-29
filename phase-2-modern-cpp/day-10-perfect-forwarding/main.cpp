#include <iostream>
#include <string>
#include <utility>

#include "PerfectForwardingDemo.h"

void separator()
{
    std::cout
        << "\n=========================================="
        << std::endl;
}

int main()
{
    std::cout
        << "=========================================="
        << std::endl;

    std::cout
        << "   Modern C++ - Perfect Forwarding"
        << std::endl;

    std::cout
        << "=========================================="
        << std::endl;


    // ==================================================
    // 1. Direct lvalue
    // ==================================================

    separator();

    std::cout
        << "1. Direct lvalue"
        << std::endl;

    int number = 10;

    PerfectForwardingDemo::process(number);


    // ==================================================
    // 2. Direct rvalue
    // ==================================================

    separator();

    std::cout
        << "2. Direct rvalue"
        << std::endl;

    PerfectForwardingDemo::process(20);


    // ==================================================
    // 3. Bad forwarding with lvalue
    // ==================================================

    separator();

    std::cout
        << "3. badForward(lvalue)"
        << std::endl;

    PerfectForwardingDemo::badForward(number);


    // ==================================================
    // 4. Bad forwarding with rvalue
    // ==================================================

    separator();

    std::cout
        << "4. badForward(rvalue)"
        << std::endl;

    PerfectForwardingDemo::badForward(30);


    // ==================================================
    // 5. Perfect forwarding with lvalue
    // ==================================================

    separator();

    std::cout
        << "5. perfectForward(lvalue)"
        << std::endl;

    PerfectForwardingDemo::perfectForward(number);


    // ==================================================
    // 6. Perfect forwarding with rvalue
    // ==================================================

    separator();

    std::cout
        << "6. perfectForward(rvalue)"
        << std::endl;

    PerfectForwardingDemo::perfectForward(40);


    // ==================================================
    // 7. String lvalue
    // ==================================================

    separator();

    std::cout
        << "7. String lvalue"
        << std::endl;

    std::string name = "Shrinath";

    PerfectForwardingDemo::perfectForward(name);


    // ==================================================
    // 8. String rvalue
    // ==================================================

    separator();

    std::cout
        << "8. String rvalue"
        << std::endl;

    PerfectForwardingDemo::perfectForward(
        std::string("Modern C++")
    );


    // ==================================================
    // 9. std::move + forwarding
    // ==================================================

    separator();

    std::cout
        << "9. std::move + perfect forwarding"
        << std::endl;

    PerfectForwardingDemo::perfectForward(
        std::move(name)
    );


    // ==================================================
    // 10. End
    // ==================================================

    separator();

    std::cout
        << "Program Ending..."
        << std::endl;

    return 0;
}