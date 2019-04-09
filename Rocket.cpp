#include "Rocket.hpp"
#include <limits>
#include <vector>
#include <fstream>
#include <curses.h>

void Rocket::SetTriggerAge(int i)
{
	this->trigger_age = i;
}
void Rocket::SetAgeLimit(int i)
{
	this->age_limit = i;
}
void Rocket::SetPosition(Rocket &other)
{
	this->position.x = other.position.x;
	this->position.y = other.position.y;
}
void Rocket::SetForce(float x, float y)
{
	this->force.x = x;
	this->force.y = y;
}
void Rocket::Draw()
{
	mvaddch(this->position.y, this->position.x, 'x');
}
void Rocket::Step()
{

}
int Rocket::GetAge()
{
	return age;
}
bool Rocket::IsAlive()
{
	if(this->age<= age_limit){
		return true;
	}
	else{
		return false;
	}
		return true;
}
bool Rocket::IsTriggered()
{
	if(this->age >= this->trigger_age){
		return true;
	}
	else{
		return false;
	}

	return false;
}
void Rocket::SetGravity(float g)
{
	gravity = g;
}
void Rocket::SetLogFile(std::ofstream *log_file){
	log_file = log_file;
}
void Rocket::SetVector(std::vector<Rocket *> *rockety)
{
	rockets = rockety;
}
void Rocket::Trigger(){}



