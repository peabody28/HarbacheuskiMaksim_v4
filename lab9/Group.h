#pragma once
#include <vector>
#include "Tutor.h"
#include "Student.h"

namespace university
{
	class Group
	{
	private:
		unsigned long long number;
		Tutor tutor;
		std::vector<Student> students;
	public:
		Group();
		Group(unsigned int _number, Tutor _tutor, std::vector<Student> _students);
		Tutor GetTutor();
		unsigned long long GetNumber();
		std::vector<Student> GetStudents();
	};
}