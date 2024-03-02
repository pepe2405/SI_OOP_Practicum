const int NAME_LENGTH = 16;
const int MAX_STUDENTS = 20;

enum class Major {
    SI,
    KN,
    IS,
    I,
    AD,
    M,
    PM,
    S
};

struct Student {
    char name[NAME_LENGTH + 1];
    int age;
    Major major;
};

struct Course {
    Student students[MAX_STUDENTS];
    int studentsCount;
};

int groupByMajor(const Course &course, Major major, Student *studentsByMajor) {
    if (!studentsByMajor) {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < course.studentsCount; i++) {
        if (course.students[i].major == major) {
            studentsByMajor[count++] = course.students[i];
        }
    }

    return count;
}