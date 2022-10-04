#include "University.h"

University::University(std::vector<Student*> _sts) { students = _sts; }

std::vector<Student*> University::GetStudents() { return students; }