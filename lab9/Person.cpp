#include "Person.h"
#include <string>
using namespace university;

Person::Person() {}

Person::Person(unsigned int _age, std::string _name)
{
	age = _age;
	name = _name;
}

unsigned int Person::GetAge() { return age; }

std::string Person::GetName() { return name; }
