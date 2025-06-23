#include "Streamer.hpp"
#include <ncurses.h>
#include <iostream>

// Implement the Trigger method for Streamer
void Streamer::Trigger(std::vector<Rocket*>& v) {
    Rocket* r = new Streamer();  // Create a new Streamer rocket
    v.push_back(r);  // Add it to the rockets vector
}

// Implement the Draw method for Streamer
void Streamer::Draw() {
    mvaddch(this->position.y, this->position.x, '*');  // Display Streamer rocket as an asterisk
}
