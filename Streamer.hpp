#ifndef STREAMER_HPP
#define STREAMER_HPP

#include "Rocket.hpp"
#include <vector>

// Streamer class inherits from Rocket
class Streamer : public Rocket {
public:
    void Trigger(std::vector<Rocket*>& v) override;  // Override Trigger method
    void Draw() override;  // Override Draw method
};

#endif
