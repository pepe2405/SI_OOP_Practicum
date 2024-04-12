#include "OptionalDouble.h"

class OptionalDoubleVector {
private:
    OptionalDouble* arr;
    int size = 0;
    int capacity = 8;

    void copyFrom(const OptionalDoubleVector& other);
    void free();
    void resize(int newCapacity);

public:
    OptionalDoubleVector() = default;
    OptionalDoubleVector(int capacity);
    OptionalDoubleVector(const OptionalDoubleVector& other);
    OptionalDoubleVector& operator=(const OptionalDoubleVector& other);
    ~OptionalDoubleVector();

    void pushBack(const OptionalDouble& value);
    void popBack();

    void insert(const OptionalDouble& el, int index);
    void erase(int index);
    void clear();
    int getSize() const;
    int getCapacity() const;
    bool isEmpty() const;

    OptionalDouble& operator[](int index);
    const OptionalDouble& operator[](int index) const;
};