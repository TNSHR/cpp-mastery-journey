#include "InitializerListDemo.h"

InitializerListDemo::InitializerListDemo(
    int studentId,
    const std::string& studentName,
    double studentMarks,
    int fixed,
    int& ref
)
    : id(studentId),
      name(studentName),
      marks(studentMarks),
      fixedValue(fixed),
      reference(ref)
{
}

void InitializerListDemo::print() const
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

    std::cout
        << "Fixed value: "
        << fixedValue
        << '\n';

    std::cout
        << "Reference value: "
        << reference
        << '\n';
}

void InitializerListDemo::updateReference(
    int value
)
{
    reference = value;
}

int InitializerListDemo::getFixedValue() const
{
    return fixedValue;
}
