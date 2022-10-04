#pragma once
#include "Speciality.h"

namespace univ
{
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
}


