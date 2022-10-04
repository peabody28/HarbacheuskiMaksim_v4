#include "Student.h"
using namespace univ;


Student::Student(Group* _gr, std::string _name) : Person(_name) { group = _gr; }

Group* Student::GetGroup() { return group; }