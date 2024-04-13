#include "ThreeMultiSet.h"
#include <algorithm>
#include <iostream>

constexpr short DEFAULT_U = 16;

const short ThreeMultiSet::BITS_PER_NUM = 2;
const short ThreeMultiSet::MAX_COUNT_OF_NUMBER = (1 << BITS_PER_NUM) - 1;
const short ThreeMultiSet::BITS_IN_BYTE = 8;
const short ThreeMultiSet::NUMS_IN_BUCKET = sizeof(ThreeMultiSet::Bucket) * BITS_IN_BYTE / BITS_PER_NUM;

ThreeMultiSet::ThreeMultiSet() : ThreeMultiSet(DEFAULT_U) {
}


ThreeMultiSet::ThreeMultiSet(size_t u) : u(u), size(bucket(u - 1) + 1) {
    buckets = new Bucket[size];
}

ThreeMultiSet::ThreeMultiSet(const ThreeMultiSet &other) {
    copyFrom(other);
}

ThreeMultiSet &ThreeMultiSet::operator=(const ThreeMultiSet &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

ThreeMultiSet::~ThreeMultiSet() {
    free();
}

void ThreeMultiSet::insert(size_t num) {
    int countNum = count(num);
    if (num >= u || countNum == MAX_COUNT_OF_NUMBER) {
        return;
    }

    ++countNum;
    replace(num, countNum);
}

void ThreeMultiSet::remove(size_t num) {
    int countNum = count(num);
    if (countNum == 0) {
        return;
    }

    --countNum;
    replace(num, countNum);
}

int ThreeMultiSet::count(size_t num) const {
    if (num >= u) {
        return 0;
    }

    return (buckets[bucket(num)] & position(num)) >> shift(num);
}

void ThreeMultiSet::printAll() const {
    for (int i = 0; i < u; ++i) {
        int countNum = count(i);
        while (countNum--) {
            std::cout << i << ' ';
        }
    }
}

void ThreeMultiSet::free() {
    delete[] buckets;
    buckets = nullptr;
    size = u = 0;
}

void ThreeMultiSet::copyFrom(const ThreeMultiSet &other) {
    size = other.size;
    u = other.u;
    buckets = new Bucket[size];

    for (size_t i = 0; i < size; ++i) {
        buckets[i] = other.buckets[i];
    }
}


void ThreeMultiSet::replace(size_t num, size_t count) {
    size_t bucketIdx = bucket(num);

    buckets[bucketIdx] &= ~position(num);
    buckets[bucketIdx] |= (count << shift(num));
}

size_t ThreeMultiSet::bucket(size_t num) {
    return num / NUMS_IN_BUCKET;
}

size_t ThreeMultiSet::position(size_t num) {
    return MAX_COUNT_OF_NUMBER << shift(num);
}

size_t ThreeMultiSet::shift(size_t num) {
    return BITS_PER_NUM * (NUMS_IN_BUCKET - 1 - num % NUMS_IN_BUCKET);
}


ThreeMultiSet intersect(const ThreeMultiSet &lhs, const ThreeMultiSet &rhs) {
    size_t minU = std::min(lhs.u, rhs.u);
    ThreeMultiSet intersection(minU);

    for (size_t i = 0; i < minU; ++i) {
        intersection.replace(i, std::min(lhs.count(i), rhs.count(i)));
    }

    return intersection;
}