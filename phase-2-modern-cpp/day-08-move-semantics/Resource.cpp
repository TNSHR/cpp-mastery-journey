#include "Resource.h"

#include <algorithm>
#include <iostream>

// -----------------------------------------
// Constructor
// -----------------------------------------

Resource::Resource(std::size_t size)
    : data(nullptr),
      size(size)
{
    if(size > 0)
    {
        data = new int[size];

        for(std::size_t i = 0; i < size; ++i)
        {
            data[i] = static_cast<int>(i + 1);
        }
    }

    std::cout
        << "Constructor: Resource created with size "
        << size
        << std::endl;
}

// -----------------------------------------
// Destructor
// -----------------------------------------

Resource::~Resource()
{
    delete[] data;

    std::cout
        << "Destructor: Resource destroyed"
        << std::endl;
}

// -----------------------------------------
// Copy Constructor
// -----------------------------------------

Resource::Resource(const Resource& other)
    : data(nullptr),
      size(other.size)
{
    if(size > 0)
    {
        data = new int[size];

        std::copy(
            other.data,
            other.data + size,
            data
        );
    }

    std::cout
        << "Copy Constructor Called"
        << std::endl;
}

// -----------------------------------------
// Move Constructor
// -----------------------------------------

Resource::Resource(Resource&& other) noexcept
    : data(other.data),
      size(other.size)
{
    other.data = nullptr;
    other.size = 0;

    std::cout
        << "Move Constructor Called"
        << std::endl;
}

// -----------------------------------------
// Copy Assignment Operator
// -----------------------------------------

Resource& Resource::operator=(
    const Resource& other)
{
    std::cout
        << "Copy Assignment Called"
        << std::endl;

    if(this == &other)
    {
        return *this;
    }

    int* newData = nullptr;

    if(other.size > 0)
    {
        newData = new int[other.size];

        std::copy(
            other.data,
            other.data + other.size,
            newData
        );
    }

    delete[] data;

    data = newData;
    size = other.size;

    return *this;
}

// -----------------------------------------
// Move Assignment Operator
// -----------------------------------------

Resource& Resource::operator=(
    Resource&& other) noexcept
{
    std::cout
        << "Move Assignment Called"
        << std::endl;

    if(this == &other)
    {
        return *this;
    }

    delete[] data;

    data = other.data;
    size = other.size;

    other.data = nullptr;
    other.size = 0;

    return *this;
}

// -----------------------------------------
// Display
// -----------------------------------------

void Resource::display() const
{
    std::cout
        << "Size: "
        << size
        << std::endl;

    std::cout
        << "Data: ";

    for(std::size_t i = 0; i < size; ++i)
    {
        std::cout
            << data[i]
            << " ";
    }

    std::cout
        << std::endl;
}

// -----------------------------------------
// Get Size
// -----------------------------------------

std::size_t Resource::getSize() const
{
    return size;
}