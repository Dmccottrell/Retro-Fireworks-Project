#include "DoubleStreamer.hpp"
#include <cmath>
#include <vector>
#include "Sparkler.hpp"

void DoubleStreamer::Trigger(std::vector<Rocket *> &v)
{
    // Trigger the Streamer functionality first
    Streamer::Trigger(v);

    // Create 8 more Sparkler rockets to form a "double streamer"
    for (int i = 0; i < 8; i++)
    {
        Rocket *s = new Sparkler();  // Create a new Sparkler object
        *s = Rocket();               // Initialize it with the base Rocket constructor

        // Set different forces based on the index to spread them out
        if (i == 0)
        {
            s->SetForce(this->force.x, this->force.y - 1);  // Move upwards
        }
        else if (i == 1)
        {
            s->SetForce(this->force.x + sqrt(2), this->force.y - sqrt(2));  // Diagonal top-right
        }
        else if (i == 2)
        {
            s->SetForce(this->force.x + 2, this->force.y);  // Move right
        }
        else if (i == 3)
        {
            s->SetForce(this->force.x + sqrt(2), this->force.y + sqrt(2));  // Diagonal bottom-right
        }
        else if (i == 4)
        {
            s->SetForce(this->force.x, this->force.y + 2);  // Move down
        }
        else if (i == 5)
        {
            s->SetForce(this->force.x - sqrt(2), this->force.y + sqrt(2));  // Diagonal bottom-left
        }
        else if (i == 6)
        {
            s->SetForce(this->force.x - 2, this->force.y);  // Move left
        }
        else if (i == 7)
        {
            s->SetForce(this->force.x - sqrt(2), this->force.y - sqrt(2));  // Diagonal top-left
        }

        // Set a limit on the rocket's age (to determine when it should be "destroyed")
        s->SetAgeLimit(40);
        s->SetPosition(*this);  // Set the new rocket's position to be the same as the DoubleStreamer

        v.push_back(s);  // Add the new rocket to the vector of rockets
    }
}
