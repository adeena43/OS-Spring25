#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "school.h"
#include "teacher.h"

class Course {
private:
    std::string name;
    std::vector<Student*> students;
    std::vector<Teacher*> teachers;

public:
    Course(const std::string& name);
    void enroll_Student(Student* student);
    void assign_Teacher(Teacher* teacher);
    void display_Students() const;
    void display_Teachers() const;
    std::string getName() const;
};

#endif

