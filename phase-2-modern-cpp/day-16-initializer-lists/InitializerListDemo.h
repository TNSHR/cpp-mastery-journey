#ifndef INITIALIZER_LIST_DEMO_H
#define INITIALIZER_LIST_DEMO_H

#include <iostream>
#include <string>

class InitializerListDemo
{
private:

    int id;
    std::string name;
    double marks;

    const int fixedValue;

    int& reference;

public:

    InitializerListDemo(
        int studentId,
        const std::string& studentName,
        double studentMarks,
        int fixed,
        int& ref
    );

    void print() const;

    void updateReference(int value);

    int getFixedValue() const;
};

#endif
