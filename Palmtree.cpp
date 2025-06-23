#include "Palmtree.hpp"
#include <iostream>
#include <ncurses.h>

// Implement the Trigger method for Palmtree
void Palmtree::Trigger(std::vector<Rocket*>& v) {
    Rocket* r = new Palmtree();  // Create a new Palmtree rocket
    v.push_back(r);  // Add it to the rockets vector
}

// Implement the Draw method for Palmtree
void Palmtree::Draw() {
    mvaddch(this->position.y, this->position.x, '@');  // Display Palmtree rocket as an at symbol
}
