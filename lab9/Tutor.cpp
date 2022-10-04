#include "Tutor.h"
using namespace univ;


Tutor::Tutor(Group* _group, std::string _name) : Person(_name) { group = _group; }

Group* Tutor::GetGroup() { return group; }