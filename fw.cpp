#include "fw.hpp"
#include <curses.h>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iostream>
#include "Palmtree.hpp"
#include "Streamer.hpp"

float Rocket::gravity = 1.0; // Default gravity value, applied to all rockets

// Constructor: Initializes the rocket with default values
Rocket::Rocket()
{
    this->SetAgeLimit(__INT_MAX__);  // Set age limit to the maximum possible integer value
    this->SetTriggerAge(__INT_MAX__); // Set trigger age to maximum integer value
    this->SetPosition(0, 0);         // Set the initial position to (0, 0)
    this->SetForce(0, 0);            // Set the initial force (speed) to (0, 0)
    this->age = 0;                   // The rocket starts with age 0
}

Rocket::~Rocket()
{
    // Destructor for cleaning up resources (currently no special cleanup needed)
}

// Setter for the trigger age
void Rocket::SetTriggerAge(int i) { 
    this->trigger_age = i; 
}

// Setter for the age limit
void Rocket::SetAgeLimit(int i) { 
    this->age_limit = i; 
}

// Set the position of the rocket based on another rocket's position
void Rocket::SetPosition(Rocket &other)
{
    this->position.x = other.position.x;
    this->position.y = other.position.y;
}

// Set the rocket's position using specific x and y coordinates
void Rocket::SetPosition(float x, float y)
{
    this->position.x = x;
    this->position.y = y;
}

// Set the force (movement speed) applied to the rocket in x and y directions
void Rocket::SetForce(float x, float y)
{
    this->force.x = x;
    this->force.y = y;
}

// Draw the rocket on the screen at its current position
void Rocket::Draw()
{
    mvaddch(this->position.y, this->position.x, '*');  // Using curses library to draw rocket as an asterisk
}

// Update the rocket's position based on its force, and apply gravity
void Rocket::Step(std::vector<Rocket *> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        // Update the rocket's position based on its current force
        (v.at(i))->position.x += (v.at(i))->force.x;
        (v.at(i))->position.y += (v.at(i))->force.y;

        // Apply gravity to the rocket's vertical force (y direction)
        (v.at(i))->force.y -= (v.at(i))->gravity;

        // Increment the rocket's age by 1
        (v.at(i))->age += 1;
    }
}

// Check if the rocket is still alive based on its age and age limit
bool Rocket::IsAlive()
{
    return (this->age <= this->age_limit);  // Rocket is alive if its age is within the age limit
}

// Check if the rocket has triggered its event based on its age
bool Rocket::IsTriggered()
{
    return (this->age == this->trigger_age);  // Triggered if age matches the trigger age
}

// Set the global gravity value that will affect all rockets
void Rocket::SetGravity(float g)
{
    gravity = g;
}

// Trigger a new rocket and add it to the vector of rockets
void Rocket::Trigger(std::vector<Rocket *> &v)
{
    Rocket *r = new Rocket();  // Create a new Rocket object
    v.push_back(r);            // Add the new rocket to the vector of rockets
}
