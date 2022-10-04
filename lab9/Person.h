#pragma once
#include <string>

namespace university
{
	class Person
	{
	private:
		unsigned int age;
		std::string name;
	public:
		Person();
		Person(unsigned int _age, std::string _name);
		unsigned int GetAge();
		std::string GetName();
	};
}