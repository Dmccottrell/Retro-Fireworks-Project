#include "Streamer.hpp"
#include "Sparkler.hpp"
#include <cmath>

void Streamer::Trigger(std::vector<Rocket *> &v)
{
    for (int i = 0; i < 8; i++) {
        Rocket *s = new Sparkler;  // Create a new Sparkler rocket
        *s = Rocket();  // Copy the base Rocket object to the Sparkler

        // Set direction based on the value of i (directional movement)
        if (i == 0) {
            s->SetForce(this->force.x, this->force.y - 2);
        } else if (i == 1) {
            s->SetForce(this->force.x + sqrt(2), this->force.y - sqrt(2));
        } else if (i == 2) {
            s->SetForce(this->force.x + 2, this->force.y);
        } else if (i == 3) {
            s->SetForce(this->force.x + sqrt(2), this->force.y + sqrt(2));
        } else if (i == 4) {
            s->SetForce(this->force.x, this->force.y + 2);
        } else if (i == 5) {
            s->SetForce(this->force.x - sqrt(2), this->force.y + sqrt(2));
        } else if (i == 6) {
            s->SetForce(this->force.x - 2, this->force.y);
        } else if (i == 7) {
            s->SetForce(this->force.x - sqrt(2), this->force.y - sqrt(2));
        }

        s->SetAgeLimit(40);  // Set the sparkler's age limit
        s->SetPosition(*this);  // Set the sparkler's position based on the parent rocket
        v.push_back(s);  // Add the sparkler to the rocket list
    }
}
