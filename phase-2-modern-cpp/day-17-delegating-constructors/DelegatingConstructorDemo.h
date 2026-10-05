#ifndef DELEGATING_CONSTRUCTOR_DEMO_H
#define DELEGATING_CONSTRUCTOR_DEMO_H

#include <iostream>
#include <string>

class DelegatingConstructorDemo
{
private:

    int id;
    std::string name;
    double marks;

public:

    // Default constructor
    DelegatingConstructorDemo();

    // Constructor with ID
    explicit DelegatingConstructorDemo(int studentId);

    // Main/target constructor
    DelegatingConstructorDemo(
        int studentId,
        const std::string& studentName,
        double studentMarks
    );

    void print() const;
};

#endif