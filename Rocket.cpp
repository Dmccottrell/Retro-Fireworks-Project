#include "Rocket.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

float Rocket::gravity = 1.0f;  // Default gravity for all rockets

// Constructor to initialize default values
Rocket::Rocket() {
    SetAgeLimit(__INT_MAX__);  // Max possible age limit
    SetTriggerAge(__INT_MAX__);  // Max possible trigger age
    SetPosition(0, 0);  // Set initial position
    SetForce(0, 0);  // Set initial force
    age = 0;  // Age starts at 0
}

Rocket::~Rocket() {
    // Destructor doesn't need any specific cleanup as of now
}

// Setters
void Rocket::SetTriggerAge(int i) { trigger_age = i; }
void Rocket::SetAgeLimit(int i) { age_limit = i; }
void Rocket::SetPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Rocket::SetForce(float x, float y) {
    force.x = x;
    force.y = y;
}

// Drawing the rocket on the screen (Override in derived classes)
void Rocket::Draw() {
    // This will be a placeholder, as Draw should be implemented in derived classes (e.g., Streamer, Palmtree)
    std::cout << "Drawing Rocket" << std::endl;
}

// Update the rocket's position, applying gravity
void Rocket::Step(std::vector<Rocket*>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        v.at(i)->position.x += v.at(i)->force.x;  // Move based on force
        v.at(i)->position.y += v.at(i)->force.y;  // Apply force to position

        // Apply gravity to the vertical force (y-direction)
        v.at(i)->force.y -= gravity;

        // Increment the rocket's age
        v.at(i)->age += 1;
    }
}

// Check if the rocket is alive based on age and age limit
bool Rocket::IsAlive() {
    return (age <= age_limit);
}

// Check if the rocket has triggered based on its age
bool Rocket::IsTriggered() {
    return (age == trigger_age);
}

// Set global gravity for all rockets
void Rocket::SetGravity(float g) {
    gravity = g;
}

// Trigger a new rocket
void Rocket::Trigger(std::vector<Rocket*>& v) {
    // Creating a new instance of Rocket (this might be overridden by derived classes)
    Rocket* r = new Rocket();
    v.push_back(r);  // Add it to the vector
}
