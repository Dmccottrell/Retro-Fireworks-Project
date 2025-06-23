#include "Sparkler.hpp"

void Sparkler::Trigger(std::vector<Rocket *> &v)
{
    // Create and configure a new Sparkler rocket
    Rocket *r = new Rocket();
    r->SetPosition(30, 30);  // Example position for Sparkler
    r->SetForce(0, -4);      // Example force for Sparkler
    r->SetAgeLimit(90);

    v.push_back(r);
}
