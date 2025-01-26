#pragma once
#include <vector>
#include "Rocket.hpp"

class Palmtree : public Rocket
{
public:
    virtual void Trigger(std::vector<Rocket *> &v);  // Trigger action for Palmtree rocket
};
