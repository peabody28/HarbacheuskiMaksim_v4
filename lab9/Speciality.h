#pragma once
#include <vector>
#include "Course.h"

class Speciality
{
private:
	std::vector<Course*> courses;
public:
	Speciality() {}

	Speciality(std::vector<Course*> _courses);

	std::vector<Course*> GetCourses();

	~Speciality() {}
};

