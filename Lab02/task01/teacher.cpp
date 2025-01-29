#include "course.h"
#include "teacher.h"
#include <iostream>

Teacher::Teacher(const std::string& name) : name(name) {}

void Teacher::assign_Course(Course* course) {
    courses.push_back(course);
}

void Teacher::display_Courses() const {
    std::cout << "Teacher: " << name << " is teaching:\n";
    for (const auto& course : courses) {
        std::cout << "- " << course->getName() << "\n";
    }
}

std::string Teacher::getName() const {
    return name;
}


































