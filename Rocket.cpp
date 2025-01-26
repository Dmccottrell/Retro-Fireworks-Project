#include "Rocket.hpp"
#include <curses.h>

float Rocket::gravity = 9.8;  // Default gravity value
std::ofstream *Rocket::log_file = nullptr;
std::vector<Rocket *> *Rocket::rockets = nullptr;

Rocket::Rocket()
{
    this->age = 0;
    this->age_limit = std::numeric_limits<int>::max();  // No age limit initially
    this->trigger_age = std::numeric_limits<int>::max();  // No trigger age initially
    this->position = {0, 0};
    this->force = {0, 0};
}

Rocket::~Rocket() {}

void Rocket::SetTriggerAge(int i) { this->trigger_age = i; }
void Rocket::SetAgeLimit(int i) { this->age_limit = i; }

void Rocket::SetPosition(Rocket &other)
{
    this->position = other.position;
}

void Rocket::SetPosition(float x, float y)
{
    this->position = {x, y};
}

void Rocket::SetForce(float x, float y)
{
    this->force = {x, y};
}

void Rocket::Draw()
{
    mvaddch(this->position.y, this->position.x, 'x');  // Draw rocket at position
}

void Rocket::Step() {
    // This function would typically update the rocket's position based on force,
    // but for now, it is empty in this class as derived classes may define it.
}

int Rocket::GetAge() { return this->age; }

bool Rocket::IsAlive()
{
    return this->age <= this->age_limit;
}

bool Rocket::IsTriggered()
{
    return this->age == this->trigger_age;
}

void Rocket::SetGravity(float g)
{
    gravity = g;
}

void Rocket::SetLogFile(std::ofstream *file)
{
    log_file = file;
}

void Rocket::SetVector(std::vector<Rocket *> *rocket_list)
{
    rockets = rocket_list;
}

void Rocket::Trigger()
{
    // Base class doesn't trigger anything, but derived classes will implement behavior.
}
