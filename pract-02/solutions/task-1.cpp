#include <iostream>
#include <fstream>

int countCharsIgnoringWhitespace(const char *filePath) {
    if (!filePath) {
        return -1;
    }

    std::ifstream file(filePath);
    if (!file.is_open()) {
        return -1;
    }

    int count = 0;
    while (true) {
        char c = file.get();
        if (file.eof()) {
            break;
        }

        if (c != ' ' && c != '\n') {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    std::cout << countCharsIgnoringWhitespace("task-1.cpp") << std::endl;
    return 0;
}