#include "Course.h"
#include "Speciality.h"
#include "University.h"
#include <vector>
#include <string>
using namespace university;

Speciality::Speciality() {}

Speciality::Speciality(std::string _title, University _university, std::vector<std::vector<std::string>, unsigned int> _courseSciences)
{
	title = _title;
	courseSciences = _courseSciences;
	university = _university;
}
	
std::string Speciality::GetTitle() { return title; }

std::vector<std::string> Speciality::GetSciences(Course course) { return courseSciences[course.GetNumber()]; }

University Speciality::GetUniversity() { return university; }


