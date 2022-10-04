#pragma once

namespace university
{
	class Course
	{
	protected:
		unsigned int number;
	public:
		Course();
		Course(unsigned int _number);
		unsigned int GetNumber();
	};
}
