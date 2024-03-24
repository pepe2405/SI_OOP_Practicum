#include <iostream>
#include <cstring>
#include <fstream>

constexpr short NAME_LEN = 21;
constexpr short DESCRIPTION_LEN = 129;
constexpr short TASKS_COUNT = 10;


class Task {
private:
    char name[NAME_LEN];
    char description[DESCRIPTION_LEN];
    unsigned points;

public:
    Task() : points(0) {
        name[0] = '\0';
        description[0] = '\0';
    }

    Task(const char *name, const char *description, unsigned points) : points(points) {
        setName(name);
        setDescription(description);
    }

    const char *getName() const {
        return name;
    }

    const char *getDescription() const {
        return description;
    }

    unsigned getPoints() const {
        return points;
    }

    void setName(const char *name) {
        if (!name) {
            return;
        }

        strncpy(this->name, name, NAME_LEN);
    }

    void setDescription(const char *description) {
        if (!description) {
            return;
        }

        strncpy(this->description, description, DESCRIPTION_LEN);
    }

    void setPoints(unsigned points) {
        this->points = points;
    }

    void saveToBinary(const char *filePath) {
        if (!filePath) {
            return;
        }

        std::ofstream file(filePath, std::ios::binary);
        if (!file.is_open()) {
            return;
        }

        file.write((const char *) this, sizeof(Task));
        file.close();
    }

    void readFromBinary(const char *filePath) {
        if (!filePath) {
            return;
        }

        std::ifstream file(filePath, std::ios::binary);
        if (!file.is_open()) {
            return;
        }

        file.read((char *) this, sizeof(Task));
        file.close();
    }

    void print() const {
        std::cout << "Name: " << name << std::endl
                  << "Description: " << description << std::endl
                  << "Points: " << points << std::endl;
    }
};

class Test {
private:
    Task tasks[TASKS_COUNT];
    unsigned minPoints;


public:
    Test(const Task* tasks, unsigned minPoints) : minPoints(minPoints) {
        setTasks(tasks);
    }

    const Task *getTasks() const {
        return tasks;
    }

    unsigned getMinPoints() const {
        return minPoints;
    }

    // assume that the tasks array is always of size TASKS_COUNT
    void setTasks(const Task *tasks) {
        if(!tasks) {
            return;
        }

        for (int i = 0; i < TASKS_COUNT; i++) {
            this->tasks[i] = tasks[i];
        }
    }

    void setMinPoints(unsigned minPoints) {
        this->minPoints = minPoints;
    }

    unsigned getMaxPoints() const {
        unsigned maxPoints = 0;
        for (int i = 0; i < TASKS_COUNT; i++) {
            maxPoints += tasks[i].getPoints();
        }

        return maxPoints;
    }

    void print() const {
        std::cout << "TEST" << std::endl;
        for (int i = 0; i < TASKS_COUNT; i++) {
            tasks[i].print();
        }

        std::cout << "Min points: " << minPoints << std::endl;
    }

    void saveToBinary(const char *filePath) {
        if (!filePath) {
            return;
        }

        std::ofstream file(filePath, std::ios::binary);
        if (!file.is_open()) {
            return;
        }

        file.write((const char *) this, sizeof(Test));
        file.close();
    }

    void readFromBinary(const char *filePath) {
        if (!filePath) {
            return;
        }

        std::ifstream file(filePath, std::ios::binary);
        if (!file.is_open()) {
            return;
        }

        file.read((char *) this, sizeof(Test));
        file.close();
    }
};