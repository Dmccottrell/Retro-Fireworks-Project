#include <vector>
#include "Palmtree.hpp"
	
	

void Palmtree::Trigger(std::vector<Rocket *> & v)
{
	Palmtree *p = new Palmtree;
	v.push_back(p);
}