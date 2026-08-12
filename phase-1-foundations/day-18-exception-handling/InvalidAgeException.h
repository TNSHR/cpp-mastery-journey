#ifndef INVALID_AGE_EXCEPTION_H
#define INVALID_AGE_EXCEPTION_H

#include <exception>

class InvalidAgeException : public std::exception
{
public:

    const char* what() const noexcept override
    {
        return "Age must be 18 years or above.";
    }
};

#endif