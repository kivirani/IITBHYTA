#include <cstring>

#include <ppl.hh>

class Location
{
public:
	string name;
	string id;
	Constraint_System invariants;
	Constraint_System rate;
};
