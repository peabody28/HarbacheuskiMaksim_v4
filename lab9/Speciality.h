#pragma once
#include <string>
#include <vector>
#include "University.h"
#include "Course.h"

namespace university
{
	class Speciality
	{
	protected:
		std::string title;
		University university;
		std::vector<std::vector<std::string>, unsigned int> courseSciences;
	public:
		Speciality();
		Speciality(std::string _title, University _university, std::vector<std::vector<std::string>, unsigned int> _courseSciences);
		std::string GetTitle();
		std::vector<std::string> GetSciences(Course course);
		University GetUniversity();
	};
}