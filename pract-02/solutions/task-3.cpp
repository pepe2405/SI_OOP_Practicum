#include <iostream>
#include <fstream>

constexpr int MAX_PAIRS = 25;

struct Pair {
    int x;
    int y;
};

Pair createPair(int x, int y) {
    return {x, y};
}

void initPair(Pair &pair, int x, int y) {
    pair.x = x;
    pair.y = y;
}

Pair readPairFromFile(std::ifstream &file) {
    Pair pair;
    file >> pair.x >> pair.y;
    return pair;
}

void writePairToFile(std::ofstream &file, const Pair &pair) {
    file << pair.x << " " << pair.y;
}

struct Relation {
    Pair pairs[MAX_PAIRS];
    int pairsCount;
};

bool addPair(Relation &relation, const Pair &pair) {
    if (relation.pairsCount >= MAX_PAIRS) {
        return false;
    }

    relation.pairs[relation.pairsCount++] = pair;
    return true;
}

bool writeRelation(const char *filePath, const Relation &relation) {
    if (!filePath) {
        return false;
    }

    std::ofstream file(filePath);
    if (!file.is_open()) {
        return false;
    }

    file << relation.pairsCount << std::endl;
    for (int i = 0; i < relation.pairsCount; i++) {
        writePairToFile(file, relation.pairs[i]);
        file << std::endl;
    }

    file.close();
    return true;
}

bool readRelation(const char *filePath, Relation &relation) {
    if (!filePath) {
        return false;
    }

    std::ifstream file(filePath);
    if (!file.is_open()) {
        return false;
    }

    file >> relation.pairsCount;
    for (int i = 0; i < relation.pairsCount; i++) {
        relation.pairs[i] = readPairFromFile(file);
    }

    file.close();
    return true;
}

int main() {
    Relation relation;
    relation.pairsCount = 0;

    addPair(relation, createPair(1, 2));
    addPair(relation, createPair(3, 4));
    addPair(relation, createPair(5, 6));
    writeRelation("relation.txt", relation);

    Relation relation1;
    readRelation("relation.txt", relation1);
    for (int i = 0; i < relation1.pairsCount; i++) {
        std::cout << relation1.pairs[i].x << " " << relation1.pairs[i].y << std::endl;
    }
}