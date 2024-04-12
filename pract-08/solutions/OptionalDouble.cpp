#include "OptionalDouble.h"
#include <exception>

double OptionalDouble::get() const
{
    if (value == nullptr)
        throw std::runtime_error("No value present");

    return *value;
}

void OptionalDouble::set(double value)
{
    if (this->value == nullptr)
        this->value = new double(value);
    else
        *this->value = value;
}

bool OptionalDouble::isPresent() const
{
    return value != nullptr;
}

void OptionalDouble::empty() {
    free();
    value = nullptr;
}

void OptionalDouble::copyFrom(const OptionalDouble& other)
{
    if (!other.isPresent())
        value = nullptr;
    else
        value = new double(*other.value);
}

void OptionalDouble::free()
{
    delete value;
    value = nullptr;
}

OptionalDouble::OptionalDouble(double value)
{
    set(value);
}

OptionalDouble::OptionalDouble(const OptionalDouble& other)
{
    copyFrom(other);
}

OptionalDouble& OptionalDouble::operator=(const OptionalDouble& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

OptionalDouble::~OptionalDouble()
{
    free();
}
