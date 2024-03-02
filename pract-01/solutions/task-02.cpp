#include <iostream>

const int MAX_SIZE = 16;

enum class DayOfWeek {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

struct Event {
    char name[MAX_SIZE + 1];
    DayOfWeek day;
    int duration;
};

void printEvent(const Event &event) {
    std::cout << "name: " << event.name << std::endl;
    std::cout << "day: ";

    switch (event.day) {
        case DayOfWeek::MONDAY:
            std::cout << "Monday";
            break;
        case DayOfWeek::TUESDAY:
            std::cout << "Tuesday";
            break;
        case DayOfWeek::WEDNESDAY:
            std::cout << "Wednesday";
            break;
        case DayOfWeek::THURSDAY:
            std::cout << "Thursday";
            break;
        case DayOfWeek::FRIDAY:
            std::cout << "Friday";
            break;
        case DayOfWeek::SATURDAY:
            std::cout << "Saturday";
            break;
        case DayOfWeek::SUNDAY:
            std::cout << "Sunday";
            break;
    }

    std::cout << std::endl;
    std::cout << "duration: " << event.duration << std::endl;
}

void printEventsOn(DayOfWeek day, const Event *events, int size) {
    if (!events || size < 0) {
        return;
    }

    for (int i = 0; i < size; i++) {
        if (events[i].day == day) {
            printEvent(events[i]);
        }
    }
}