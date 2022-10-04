#include "Group.h"
#include "Student.h"
#include "Tutor.h"
#include <vector>
using namespace university;

Group::Group() {}

Tutor Group::GetTutor() { return tutor; }

unsigned long long Group::GetNumber() { return number; }

std::vector<Student> Group::GetStudents() { return students; }
