#include "Student.h"
#include "Speciality.h"
#include "Person.h"
#include "Course.h"
#include <string>
using namespace university;

Student::Student() {}

Student::Student(unsigned int _age, std::string _name, Speciality _speciality, Course _course, float _rating) : Person(_age, _name)
{
	currentCourse = _course;
	rating = _rating;
	speciality = speciality;
}

float Student::GetRating() { return rating; }

Course Student::GetCurrentCourse() { return currentCourse; }

Speciality Student::GetSpeciality() { return speciality; }
