#pragma once
#include <string>

namespace univ
{
	class Person
	{
	protected:
		std::string name;
	public:
		Person() {}

		Person(std::string _name);

		std::string GetName();

		~Person() {}
	};
}

