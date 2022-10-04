#include "Speciality.h"
using namespace univ;


Speciality::Speciality(std::vector<Course*> _courses) { courses = _courses; }

std::vector<Course*> Speciality::GetCourses() { return courses; }
