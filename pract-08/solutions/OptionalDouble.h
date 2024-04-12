#pragma once
#include <iostream>

class OptionalDouble {
private:
    double* value = nullptr;
    void copyFrom(const OptionalDouble& other);
    void free();

public:
    OptionalDouble() = default;
    OptionalDouble(double value);
    OptionalDouble(const OptionalDouble& other);
    OptionalDouble& operator=(const OptionalDouble& other);
    ~OptionalDouble();

    bool isPresent() const;
    double get() const;
    void set(double value);
    void empty();
};