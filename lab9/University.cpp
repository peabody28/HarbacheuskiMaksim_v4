#include <string>
#include "University.h"

using namespace university;

University::University() {}

University::University(std::string _title)
{
	title = _title;
}

std::string University::GetTitle() { return title; }
