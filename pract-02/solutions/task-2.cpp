#include <iostream>
#include <fstream>

constexpr char FILE_PATH[] = "result.txt";

void saveSumAndProduct(const char *filePath, int a, int b, int c) {
    if (!filePath) {
        return;
    }

    std::ofstream file(filePath);
    if (!file.is_open()) {
        return;
    }

    file << a + b + c << " " << a * b * c;
    file.close();
}

void readDiff(const char *filePath) {
    if (!filePath) {
        return;
    }

    std::ifstream file(filePath);
    if (!file.is_open()) {
        return;
    }

    int a, b;
    file >> a >> b;

    file.close();
    std::cout << a - b;
}

int main() {
    saveSumAndProduct(FILE_PATH, 2, 4, 8);
    readDiff(FILE_PATH);
}