#pragma once
#include "Speciality.h"
class Group
{
private:
	Speciality* speciality;
public:
	Group() {}

	Group(Speciality* spec);

	Speciality* GetSpeciality();

	~Group() {}
};

