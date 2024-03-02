#include <iostream>

struct Triplet {
    int first;
    int second;
    int third;
};

void readTriplet(Triplet &triplet) {
    std::cin >> triplet.first >> triplet.second >> triplet.third;
}

int compare(const Triplet &lhs, const Triplet &rhs) {
    if (lhs.first == rhs.first) {
        if (lhs.second == rhs.second) {
            return lhs.third - rhs.third;
        }
        return lhs.second - rhs.second;
    }
    return lhs.first - rhs.first;
}

int findMinTripletIndex(const Triplet *triplets, int size) {
    if (!triplets) {
        return -1;
    }

    int minIdx = 0;
    for (int i = 1; i < size; i++) {
        if (compare(triplets[i], triplets[minIdx]) < 0) {
            minIdx = i;
        }
    }

    return minIdx;
}