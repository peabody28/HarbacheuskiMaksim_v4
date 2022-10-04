// number 11
// Человек, ВУЗ, специальность, курс, куратор, группа, студент
#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "Tutor.h"
#include "University.h"
using namespace univ;

int main()
{
    int courseCount;
    std::cout << "Input courses count:";
    std::cin >> courseCount;
    std::vector<Course*> courses;
    for (int i = 0; i < courseCount; i++)
        courses.push_back(new Course(i + 1));

    Speciality sp = Speciality(courses);
    Group gr = Group(&sp);

    std::cout << "Input tutor name:";
    std::string name;
    std::cin >> name;
    Tutor t = Tutor(&gr, name);

    std::cout << "Input student name:";
    std::cin >> name;
    Student st = Student(&gr, name);

    std::vector<Student*> students;
    students.push_back(&st);
    University u = University(students);

    for (auto student : u.GetStudents())
    {
        std::cout << "Student name: " << student->GetName() << std::endl;

        for (auto course : student->GetGroup()->GetSpeciality()->GetCourses())
            std::cout << course->GetNumber() << std::endl;
    }

    std::cout << "Tutor name: " << t.GetName() << std::endl;

    return 0;
}