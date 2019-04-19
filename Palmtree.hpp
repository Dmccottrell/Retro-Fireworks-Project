#pragma once
#include <vector>
#include "fw.hpp"

class Palmtree : public Rocket
{
  public:
	virtual void Trigger(std::vector<Rocket *> & v);
};