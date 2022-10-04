#include "Group.h"
using namespace univ;


Group::Group(Speciality* spec) { speciality = spec; }

Speciality* Group::GetSpeciality() { return speciality; }