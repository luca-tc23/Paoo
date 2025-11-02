#pragma once
#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int* grades;
    int gradeCount;

public:
    Student(const std::string& n, int count);
    ~Student();
    Student(const Student& other);
    Student(Student&& other) noexcept;

    void setGrade(int index, int value);
    void showGrades() const;

    const std::string& getName() const { return name; }
};
