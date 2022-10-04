#pragma once
#include <string>
#include "Person.h"

namespace university
{
	class Tutor : public Person
	{
	private:
		std::string science;
		unsigned int experience;
	public:
		Tutor();
		Tutor(unsigned int _age, std::string _name, std::string _science, unsigned int _experience);
		std::string GetScience();
		unsigned int GetExperience();
	};
}
