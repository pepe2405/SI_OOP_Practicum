#include "OptionalDoubleVector.h"

OptionalDoubleVector::OptionalDoubleVector(int capacity) {
    this->capacity = capacity;
    this->arr = new OptionalDouble[capacity];
}

OptionalDoubleVector::OptionalDoubleVector(const OptionalDoubleVector& other) {
    copyFrom(other);
}

OptionalDoubleVector& OptionalDoubleVector::operator=(const OptionalDoubleVector& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

OptionalDoubleVector::~OptionalDoubleVector() {
    free();
}

void OptionalDoubleVector::pushBack(const OptionalDouble& value) {
    if (size == capacity)
        resize(capacity * 2);

    arr[size++] = value;
}

void OptionalDoubleVector::popBack() {
    if (size == capacity / 4 && capacity > 8)
        resize(capacity / 2);

    arr[size - 1].empty();

    if (!isEmpty())
        size--;
}

void OptionalDoubleVector::insert(const OptionalDouble& el, int index) {
    if (index < 0 || index > size)
        throw std::out_of_range("Invalid index");

    arr[index] = el;
}

void OptionalDoubleVector::erase(int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Invalid index");

    arr[index].empty();
}

void OptionalDoubleVector::clear() {
    free();
    capacity = 8;
    arr = new OptionalDouble[capacity];
}

int OptionalDoubleVector::getSize() const {
    return size;
}

int OptionalDoubleVector::getCapacity() const {
    return capacity;
}

bool OptionalDoubleVector::isEmpty() const {
    return size == 0;
}

OptionalDouble& OptionalDoubleVector::operator[](int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Invalid index");

    return arr[index];
}

const OptionalDouble& OptionalDoubleVector::operator[](int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Invalid index");

    return arr[index];
}

void OptionalDoubleVector::copyFrom(const OptionalDoubleVector& other) {
    size = other.size;
    capacity = other.capacity;
    arr = new OptionalDouble[capacity];

    for (int i = 0; i < size; i++)
        arr[i] = other.arr[i];
}

void OptionalDoubleVector::free() {
    delete[] arr;
}

void OptionalDoubleVector::resize(int newCapacity) {
    OptionalDouble* temp = new OptionalDouble[newCapacity];

    for (int i = 0; i < size; i++)
        temp[i] = arr[i];

    delete[] arr;
    arr = temp;
    capacity = newCapacity;
}



