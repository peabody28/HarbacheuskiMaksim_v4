// number 11
// Человек, ВУЗ, специальность, курс, куратор, группа, студент
#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "Tutor.h"
#include "University.h"

int main()
{
    Course first = Course(1);
    Course second = Course(2);
    std::vector<Course*> courses;
    courses.push_back(&first);
    courses.push_back(&second);

    Speciality sp = Speciality(courses);
    Group gr = Group(&sp);
    Tutor t = Tutor(&gr, "Alex");

    Student st = Student(&gr, "Max");

    std::vector<Student*> students;
    students.push_back(&st);

    University u = University(students);

    std::cout << st.GetName() << std::endl;

    std::cout << st.GetGroup()->GetSpeciality()->GetCourses()[0]->GetNumber() << std::endl;
    std::cout << st.GetGroup()->GetSpeciality()->GetCourses()[1]->GetNumber() << std::endl;

    return 0;
}