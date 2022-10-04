#include "Group.h"

Group::Group(Speciality* spec) { speciality = spec; }

Speciality* Group::GetSpeciality() { return speciality; }