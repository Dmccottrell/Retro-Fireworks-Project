#include "fw.hpp"
#include "Streamer.hpp"
#include "Palmtree.hpp"
#include <ncurses.h>
#include <vector>

float Rocket::gravity = 1.0;

Rocket::Rocket() {
    this->SetAgeLimit(__INT_MAX__);
    this->SetTriggerAge(__INT_MAX__);
    this->SetPosition(0, 0);
    this->SetForce(0, 0);
    this->age = 0;
}

Rocket::~Rocket() {}

void Rocket::SetTriggerAge(int i) {
    this->trigger_age = i;
}

void Rocket::SetAgeLimit(int i) {
    this->age_limit = i;
}

void Rocket::SetPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}

void Rocket::SetForce(float x, float y) {
    this->force.x = x;
    this->force.y = y;
}

void Rocket::Draw() {
    mvaddch(this->position.y, this->position.x, '*');
}

void Rocket::Step(std::vector<Rocket *> &v) {
    for (auto &r : v) {
        r->position.x += r->force.x;
        r->position.y += r->force.y;
        r->force.y -= Rocket::gravity;
        r->age++;
    }
}

bool Rocket::IsAlive() {
    return this->age <= this->age_limit;
}

bool Rocket::IsTriggered() {
    return this->age == this->trigger_age;
}

void Rocket::SetGravity(float g) {
    Rocket::gravity = g;
}
