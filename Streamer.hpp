#pragma once
#include <vector>
#include "Rocket.hpp"

class Streamer : public Rocket
{
public:
    virtual void Trigger(std::vector<Rocket *> &v);  // Override the trigger action for Streamer
};
