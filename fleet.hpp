#ifndef FLEET_HPP
#define FLEET_HPP

#include "Rocket.hpp"
#include "Streamer.hpp"
#include "Palmtree.hpp"

class Fleet {
private:
    std::vector<Rocket*> rockets;  // Vector of rockets

public:
    Fleet();  // Constructor
    ~Fleet();  // Destructor

    void Birth(float initial_up_force);  // Birth new rockets
    void Step();  // Update rockets' positions
    void Cull();  // Remove expired rockets
    void Draw();  // Draw rockets on the screen
};

#endif
