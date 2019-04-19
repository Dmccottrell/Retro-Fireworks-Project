#include <curses.h>

#include "Sparkler.hpp"


void Sparkler::Draw()
{
	if((this->age = 0)){
		mvaddch(this->position.y, this->position.x, 'x');
		mvaddch(this->position.y, this->position.x, '+');

	}
}