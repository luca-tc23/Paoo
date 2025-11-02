#include "Student.h"
#include <utility>

Student::Student(const std::string& n, int count)
    : name(n), gradeCount(count), grades(new int[count]) {
    std::cout << "Constructor pentru " << name << "\n";
    for (int i = 0; i < gradeCount; ++i)
        grades[i] = 0;
}

Student::~Student() {
    std::cout << "Destructor pentru " << name << "\n";
    delete[] grades;
}

Student::Student(const Student& other)
    : name(other.name), gradeCount(other.gradeCount), grades(new int[other.gradeCount]) {
    std::cout << "Copy constructor pentru " << name << "\n";
    for (int i = 0; i < gradeCount; ++i)
        grades[i] = other.grades[i];
}

Student::Student(Student&& other) noexcept
    : name(std::move(other.name)), grades(other.grades), gradeCount(other.gradeCount) {
    std::cout << "Move constructor pentru " << name << "\n";
    other.grades = nullptr;
    other.gradeCount = 0;
}

void Student::setGrade(int index, int value) {
    if (index >= 0 && index < gradeCount)
        grades[index] = value;
}

void Student::showGrades() const {
    std::cout << "Notele studentului " << name << ": ";
    for (int i = 0; i < gradeCount; ++i)
        std::cout << grades[i] << " ";
    std::cout << "\n";
}
