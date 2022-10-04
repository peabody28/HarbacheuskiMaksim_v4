#pragma once
#include <vector>
#include "Student.h"

class University
{
private:
	std::vector<Student*> students;
public:
	University() {}

	University(std::vector<Student*> _students);

	std::vector<Student*> GetStudents();

	~University() {}
};

