#pragma once
#include <string>

namespace university
{
	class University
	{
	private:
		std::string title;
	public:
		University();
		University(std::string _title);
		std::string GetTitle();
	};
}