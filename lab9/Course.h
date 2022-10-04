#pragma once

namespace univ
{
	class Course
	{
	private:
		int number;
	public:
		Course() {}

		Course(int _num);

		int GetNumber();

		~Course() {}
	};
}


