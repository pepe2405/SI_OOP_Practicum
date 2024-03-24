#include <iostream>
#include <fstream>

constexpr size_t MAX_NAME_LENGTH = 8;
constexpr size_t MAX_FILE_PATH_LENGTH = 256;

struct Color {
    char name[MAX_NAME_LENGTH];
    int code;
};

constexpr Color ERROR_COLOR = {"ERROR", -1};

// Task 1
void readColor(Color& color) {
    std::cin >> color.name >> color.code;
}

Color *readColors(size_t n) {
    Color *colors = new Color[n];

    for (size_t i = 0; i < n; i++) {
        readColor(colors[i]);
    }

    return colors;
}

void saveColors(const char *filePath, const Color *colors, size_t size) {
    if (!filePath) {
        std::cout << "No file path" << std::endl;
        return;
    }

    if (!colors) {
        std::cout << "No colors" << std::endl;
        return;
    }

    std::ofstream file(filePath, std::ios::binary |std::ios::app);
    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return;
    }

    file.write((const char *) colors, size * sizeof(Color));
    file.close();
}

// Task 2
size_t getFileSize(std::ifstream &file) {
    size_t currentPos = file.tellg();

    file.seekg(0, std::ios::end);
    size_t size = file.tellg();

    file.seekg(currentPos);
    return size;
}

size_t colorsInFile(const char *filePath) {
    if (!filePath) {
        return 0;
    }

    std::ifstream file(filePath);
    if (!file.is_open()) {
        return 0;
    }

    size_t fileSize = getFileSize(file);
    file.close();

    return fileSize / sizeof(Color);
}

// first way
Color findColorByName(const char *name, const char *filePath) {
    if (!name || !filePath) {
        return ERROR_COLOR;
    }

    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        return ERROR_COLOR;
    }

    Color color;
    while (true) {
        file.read((char *) &color, sizeof(Color));
        if (file.eof()) {
            break;
        }

        if (strcmp(color.name, name) == 0) {
            file.close();
            return color;
        }
    }

    return ERROR_COLOR;
}

// second way
Color *readColors(const char *filePath) {
    if (!filePath) {
        return nullptr;
    }

    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        return nullptr;
    }

    size_t size = getFileSize(file) / sizeof(Color);
    Color *colors = new Color[size];

    file.read((char *) colors, size * sizeof(Color));
    file.close();

    return colors;
}

Color findColorByName2(const char *name, const char *filePath) {
    if (!name || !filePath) {
        return ERROR_COLOR;
    }

    Color *colors = readColors(filePath);
    if (!colors) {
        return ERROR_COLOR;
    }

    size_t size = colorsInFile(filePath);
    for (size_t i = 0; i < size; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            Color color = colors[i];
            delete[] colors;
            return color;
        }
    }

    delete[] colors;
    return ERROR_COLOR;
}

int main() {
    size_t n;
    char filePath[MAX_FILE_PATH_LENGTH];

    std::cin >> n >> filePath;

    Color *colors = readColors(n);
    saveColors(filePath, colors, n);

    delete[] colors;

    // task 2
    char name[MAX_NAME_LENGTH];
    std::cin >> name;

    Color color = findColorByName(name, filePath);
    // Color color = findColorByName2(name, filePath);
    std::cout << color.name << " " << color.code << std::endl;

    return 0;
}