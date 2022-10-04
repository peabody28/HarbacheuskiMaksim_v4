#pragma once
#include "Person.h"
#include "Group.h"

namespace univ
{
	class Tutor : public Person
	{
	private:
		Group* group;
	public:
		Tutor() {}

		Tutor(Group* _group, std::string _name);

		Group* GetGroup();

		~Tutor() {}
	};
}

