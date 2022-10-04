#include "Tutor.h"
#include "Person.h"
#include <string>
using namespace university;

Tutor::Tutor() {}

Tutor::Tutor(unsigned int _age, std::string _name, std::string _science, unsigned int _experience) : Person(_age, _name)
{
	science = _science;
	experience = _experience;
}

std::string Tutor::GetScience() { return science; }

unsigned int Tutor::GetExperience() { return experience; }
