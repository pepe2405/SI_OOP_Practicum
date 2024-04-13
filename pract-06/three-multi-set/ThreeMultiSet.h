#pragma once

#include <cstdint>
#include <cstddef>


class ThreeMultiSet {
public:
    using Bucket = uint32_t;

    static const short BITS_PER_NUM;
    static const short MAX_COUNT_OF_NUMBER;
    static const short BITS_IN_BYTE;
    static const short NUMS_IN_BUCKET;

private:
    Bucket *buckets;
    size_t size;
    size_t u;

public:
    ThreeMultiSet();

    explicit ThreeMultiSet(size_t u);

    ThreeMultiSet(const ThreeMultiSet &other);

    ThreeMultiSet &operator=(const ThreeMultiSet &other);

    ~ThreeMultiSet();

    size_t getU() const;

    void insert(size_t num);

    void remove(size_t num);

    int count(size_t num) const;

    void printAll() const;

    friend ThreeMultiSet intersect(const ThreeMultiSet &lhs, const ThreeMultiSet &rhs);

private:
    void free();

    void copyFrom(const ThreeMultiSet &other);

    void replace(size_t num, size_t count);

    static size_t bucket(size_t num);

    static size_t position(size_t num);

    static size_t shift(size_t num);
};

ThreeMultiSet intersect(const ThreeMultiSet &lhs, const ThreeMultiSet &rhs);