#include "Sparkler.hpp"
#include <curses.h>

void Sparkler::Draw()
{
    int a = this->GetAge();

    if ((a % 2) == 0) {
        mvaddch(this->position.y, this->position.x, 'x');
    } else {
        mvaddch(this->position.y, this->position.x, '+');
    }
}
