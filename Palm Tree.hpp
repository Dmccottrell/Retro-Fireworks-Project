#pragma once
#include <vector>
#include <utility>
#include "Rocket.hpp"

class PalmTree : public Rocket
{
  public:
	~PalmTree();

	static std::vector<std::pair<float, float>> v1;
	virtual void Trigger();
};