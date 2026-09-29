#include "EnumClassDemo.h"

std::string EnumClassDemo::statusToString(
    Status status
)
{
    switch (status)
    {
        case Status::Pending:
            return "Pending";

        case Status::Processing:
            return "Processing";

        case Status::Completed:
            return "Completed";

        case Status::Failed:
            return "Failed";
    }

    return "Unknown";
}


std::string EnumClassDemo::priorityToString(
    Priority priority
)
{
    switch (priority)
    {
        case Priority::Low:
            return "Low";

        case Priority::Medium:
            return "Medium";

        case Priority::High:
            return "High";

        case Priority::Critical:
            return "Critical";
    }

    return "Unknown";
}


void EnumClassDemo::printStatus(
    Status status
)
{
    std::cout
        << "Status: "
        << statusToString(status)
        << '\n';
}


void EnumClassDemo::printPriority(
    Priority priority
)
{
    std::cout
        << "Priority: "
        << priorityToString(priority)
        << '\n';
}