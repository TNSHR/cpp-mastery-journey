#include "DelegatingConstructorDemo.h"

// =====================================================
// Default constructor
// Delegates to the full constructor
// =====================================================

DelegatingConstructorDemo::DelegatingConstructorDemo()
    : DelegatingConstructorDemo(
        0,
        "Unknown",
        0.0
    )
{
}


// =====================================================
// ID-only constructor
// Delegates to the full constructor
// =====================================================

DelegatingConstructorDemo::DelegatingConstructorDemo(
    int studentId
)
    : DelegatingConstructorDemo(
        studentId,
        "Unknown",
        0.0
    )
{
}


// =====================================================
// Target constructor
// Performs actual member initialization
// =====================================================

DelegatingConstructorDemo::DelegatingConstructorDemo(
    int studentId,
    const std::string& studentName,
    double studentMarks
)
    : id(studentId),
      name(studentName),
      marks(studentMarks)
{
}


// =====================================================
// Print student information
// =====================================================

void DelegatingConstructorDemo::print() const
{
    std::cout
        << "ID: "
        << id
        << '\n';

    std::cout
        << "Name: "
        << name
        << '\n';

    std::cout
        << "Marks: "
        << marks
        << '\n';
}