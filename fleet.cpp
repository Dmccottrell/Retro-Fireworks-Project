#include "Fleet.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>  

// Constructor
Fleet::Fleet() {}

// Destructor
Fleet::~Fleet() {
    // Delete all rockets from the vector to avoid memory leaks
    for (Rocket* r : rockets) {
        delete r;
    }
    rockets.clear();
}

// Birth new rockets (using the initial force)
void Fleet::Birth(float initial_up_force) {
    Rocket* r = new Streamer();  // Create a new Streamer rocket (or any derived class)
    r->SetPosition(rand() % 80, 24);  // Set random position (within bounds of terminal screen)
    r->SetForce(0, -initial_up_force);  // Set upward force
    rockets.push_back(r);  // Add to fleet
}

// Update rocket positions
void Fleet::Step() {
    for (Rocket* r : rockets) {
        r->Step(rockets);  // Move all rockets
    }
}

// Remove rockets that are no longer alive
void Fleet::Cull() {
    rockets.erase(std::remove_if(rockets.begin(), rockets.end(), [](Rocket* r) {
        bool alive = r->IsAlive();
        if (!alive) delete r;  // Delete the rocket if it's no longer alive
        return !alive;
    }), rockets.end());
}

// Draw all rockets on the screen
void Fleet::Draw() {
    for (Rocket* r : rockets) {
        r->Draw();
    }
}
