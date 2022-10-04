#include "Person.h"
#include <string>

Person::Person(std::string _name) { name = _name; }

std::string Person::GetName() { return name; }