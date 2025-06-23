#include "DoubleStreamer.hpp"

void DoubleStreamer::Trigger(std::vector<Rocket *> &v) {
    // Implementation for DoubleStreamer's Trigger
    Rocket *newRocket1 = new Streamer();
    Rocket *newRocket2 = new Streamer();

    newRocket1->SetPosition(this->position.x, this->position.y);
    newRocket2->SetPosition(this->position.x, this->position.y);

    v.push_back(newRocket1);
    v.push_back(newRocket2);
}
