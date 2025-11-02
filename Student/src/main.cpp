#include "Student.h"

Student createTempStudent() {
    Student temp("TempStudent", 3);
    temp.setGrade(0, 10);
    temp.setGrade(1, 9);
    temp.setGrade(2, 8);
    return temp;
}

int main() {
    std::cout << "=== Creare student s1 ===\n";
    Student s1("Ion", 3);
    s1.setGrade(0, 7);
    s1.setGrade(1, 8);
    s1.setGrade(2, 9);
    s1.showGrades();

    std::cout << "\n=== Copiere student s1 -> s2 ===\n";
    Student s2 = s1;
    s2.showGrades();

    std::cout << "\n=== Mutare student temporar -> s3 ===\n";
    Student s3 = createTempStudent();
    s3.showGrades();

    std::cout << "\n=== Sfârșit ===\n";
    return 0;
}
