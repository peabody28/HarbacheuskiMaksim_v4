#include "Person.h"
#include <string>
using namespace univ;


Person::Person(std::string _name) { name = _name; }

std::string Person::GetName() { return name; }