#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>

class Course; 

class Teacher {
private:
    std::string name;
    std::vector<Course*> courses;

public:
    Teacher(const std::string& name);
    void assign_Course(Course* course);
    void display_Courses() const;
    std::string getName() const;
};

#endif

