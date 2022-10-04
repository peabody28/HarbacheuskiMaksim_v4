#pragma once
#include "Person.h"
#include <string>
#include "Group.h"

class Student : public Person
{
private:
	Group* group;
public:
	Student() {}

	Student(Group* _spec, std::string _name);

	Group* GetGroup();

	~Student() {}
};

