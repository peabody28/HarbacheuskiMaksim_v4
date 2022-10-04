#pragma once
#include "Speciality.h"
#include "Course.h"
#include "Person.h"
#include <string>

namespace university
{
	class Student : public Person
	{
	private:
		Speciality speciality;
		Course currentCourse;
		float rating;
	public:
		Student();
		Student(unsigned int _age, std::string _name, Speciality _speciality, Course _course, float _rating);
		float GetRating();
		Course GetCurrentCourse();
		Speciality GetSpeciality();
	};
}