#ifndef ENUM_CLASS_DEMO_H
#define ENUM_CLASS_DEMO_H

#include <iostream>
#include <string>

class EnumClassDemo
{
public:

    enum class Status
    {
        Pending,
        Processing,
        Completed,
        Failed
    };

    enum class Priority
    {
        Low,
        Medium,
        High,
        Critical
    };

    static std::string statusToString(Status status);

    static std::string priorityToString(
        Priority priority
    );

    static void printStatus(Status status);

    static void printPriority(Priority priority);
};

#endif