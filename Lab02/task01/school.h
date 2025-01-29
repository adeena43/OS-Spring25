#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>

class Course; 

class Student {
private:
    std::string name;
    std::vector<Course*> courses;

public:
    Student(const std::string& name);
    void enroll(Course* course);
    void display_Courses() const;
    std::string getName() const;
};

#endif

