#include "course.h"
#include <iostream>

Course::Course(const std::string& name) : name(name) {}

void Course::enroll_Student(Student* student) {
    students.push_back(student);
    student->enroll(this);
}

void Course::assign_Teacher(Teacher* teacher) {
    teachers.push_back(teacher);
    teacher->assign_Course(this);
}

void Course::display_Students() const {
    std::cout << "Course: " << name << " has the following students enrolled:\n";
    for (const auto& student : students) {
        std::cout << "- " << student->getName() << "\n";
    }
}

void Course::display_Teachers() const {
    std::cout << "Course: " << name << " is taught by:\n";
    for (const auto& teacher : teachers) {
        std::cout << "- " << teacher->getName() << "\n";
    }
}

std::string Course::getName() const {
    return name;
}

