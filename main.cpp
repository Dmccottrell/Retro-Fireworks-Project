#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <algorithm>  // Added for std::remove_if
#include "fw.hpp"
#include "Streamer.hpp"
#include "Palmtree.hpp"
#include "DoubleStreamer.hpp"
#include "fleet.hpp"

// Initialize the Rocket class (with the gravity and initial setup)
float Rocket::gravity = 0.1;  // Adjust gravity for smoother motion

// Constructor: Initializes the rocket with default values
Rocket::Rocket() {
    this->SetAgeLimit(__INT_MAX__);  // Max possible age limit
    this->SetTriggerAge(__INT_MAX__);  // Max possible trigger age
    this->SetPosition(0, 0);  // Set initial position
    this->SetForce(0, 0);  // Set initial force
    this->age = 0;  // Age starts at 0
}

Rocket::~Rocket() {
    // No special cleanup needed as of now
}

// Setters and Getters
void Rocket::SetTriggerAge(int i) { this->trigger_age = i; }
void Rocket::SetAgeLimit(int i) { this->age_limit = i; }

void Rocket::SetPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}

void Rocket::SetForce(float x, float y) {
    this->force.x = x;
    this->force.y = y;
}

// Drawing the rocket on the screen at its current position
void Rocket::Draw() {
    mvaddch(this->position.y, this->position.x, '*');  // Display the rocket as an asterisk using ncurses
}

// Update the rocket's position, applying gravity
void Rocket::Step(std::vector<Rocket *> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        v.at(i)->position.x += v.at(i)->force.x;  // Move based on force
        v.at(i)->position.y += v.at(i)->force.y;  // Apply force to position

        // Apply gravity to the vertical force (y-direction)
        v.at(i)->force.y -= v.at(i)->gravity;

        // Increment the rocket's age
        v.at(i)->age += 1;
    }
}

// Check if the rocket is alive based on age and age limit
bool Rocket::IsAlive() {
    return (this->age <= this->age_limit);
}

// Check if the rocket has triggered based on its age
bool Rocket::IsTriggered() {
    return (this->age == this->trigger_age);
}

// Set global gravity for all rockets
void Rocket::SetGravity(float g) {
    gravity = g;
}

// Trigger a new rocket
void Rocket::Trigger(std::vector<Rocket *> &v) {
    Rocket *r = new Streamer();  // Create a new rocket (using derived class)
    v.push_back(r);  // Add it to the rockets vector
}

// Main simulation
int main() {
    // Initialize ncurses for terminal display
    initscr();
    noecho();
    curs_set(0);  // Hide cursor

    // Seed the random number generator
    srand(time(0));

    // Create a vector to store all fireworks (rockets)
    std::vector<Rocket*> fireworks;

    // Set initial upward force for rockets
    float initial_up_force = 2.0;

    // Main loop for updating and displaying the rockets
    for (int age = 0; age < 100; age++) {  // Run simulation for 100 iterations
        // Clear screen each frame
        clear();

        // Create new rockets every frame
        Rocket* newRocket = new Streamer();  // Use derived class
        newRocket->SetPosition(rand() % COLS, LINES - 1);  // Position rocket at the bottom
        newRocket->SetForce(0, initial_up_force);  // Set initial upward force
        fireworks.push_back(newRocket);  // Add rocket to fireworks

        // Update the rockets, trigger any new ones if needed
        for (auto& rocket : fireworks) {
            rocket->Step(fireworks);  // Update each rocket
        }

        // Draw the rockets on the screen
        for (auto& rocket : fireworks) {
            rocket->Draw();  // Draw each rocket at its position
        }

        // Cull rockets that have exceeded their age limit or are out of bounds
        fireworks.erase(std::remove_if(fireworks.begin(), fireworks.end(), [](Rocket* r) {
            return !r->IsAlive() || r->GetPosition().y >= LINES;
        }), fireworks.end());

        // Refresh screen to show the latest rocket positions
        refresh();

        // Sleep for 100 milliseconds for smooth animation
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // End ncurses mode
    endwin();

    // Clean up allocated memory
    for (Rocket* rocket : fireworks) {
        delete rocket;
    }

    return 0;
}
