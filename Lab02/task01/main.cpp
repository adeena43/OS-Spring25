#include <iostream>
#include "teacher.h"
#include "course.h"
#include "school.h"


int main() {
    Student st1("Sara");
    Student st2("Muneeb");
    Student st3("Adina");
    Teacher teacher1("hafsaa");
    Teacher teacher2("Omer");
    Course course1("Pai");
    Course course2("Prob");

    course1.enroll_Student(&st1);
    course1.enroll_Student(&st2);
    course2.enroll_Student(&st2);
    course2.enroll_Student(&st3);

    course1.assign_Teacher(&teacher1);
    course2.assign_Teacher(&teacher2);

    course1.display_Students();
    course1.display_Teachers();
    
    course2.display_Students();
    course2.display_Teachers();

    st1.display_Courses();
    st2.display_Courses();
    st3.display_Courses();

    teacher1.display_Courses();
    teacher2.display_Courses();

    return 0;
}

