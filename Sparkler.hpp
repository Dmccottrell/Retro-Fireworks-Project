#pragma once
#include "Rocket.hpp"
#include <vector>

class Sparkler : public Rocket
{
public:
    virtual void Trigger(std::vector<Rocket *> &v);
};
