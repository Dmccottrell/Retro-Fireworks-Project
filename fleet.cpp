#include "fleet.hpp"
#include <vector>
#include <ncurses.h>
#include "fw.hpp"
#include "Streamer.hpp"
#include "Palmtree.hpp"
#include <list>
#include <iostream>

/*
Erases rocket pointers from rockets vector
if rocket's age exceeds age limit.
*/
void Fleet::Cull()
{
	auto it = rockets.begin();

	if (it != rockets.end())
	{
		if (!((*it)->IsAlive()))
		{
			it = rockets.erase(it);
		}
		else
		{
			++it;
		}
	}
}

/*
Rockets are created and inserted into rockets vector.
*/
void Fleet::Birth(float initial_up_force)
{
	/*
	To keep rockets from birthing too fast,
	mod rand by 100, then say if int 15 or less,
	then birth. else, no.
	*/

	int birthR = rand() % 100;

	if (birthR <= 15)
	{
		for (int i = 0; i < birthR; i++)
		{
			Rocket *r = RocketFactory(initial_up_force);
			rockets.push_back(r);
		}
	}
}

/*
Iterates through vector of rockets to move each rocket.
If rocket is at trigger_age, rocket will trigger into new rockets.
Vector will combine with vector with new triggered rockets.
*/
void Fleet::Step()
{
	Rocket r;

	r.Step(rockets);

	if (r.IsTriggered())
	{
		std::vector<Rocket *> newRockets;

		r.Trigger(newRockets);

		rockets.insert(rockets.end(), newRockets.begin(), newRockets.end());
	}
}

/*
Iterates through rockets vector causes each rocket
to be drawn in terminal.
*/
void Fleet::Draw()
{
	for (size_t i = 0; i <= rockets.size(); i++)
	{
		Rocket r = *(rockets.at(i));

		r.Draw();
	}
}

/*
Creates new rocket pointer.
Sets rocket force using function parameter.
Returns rocket pointer.
*/
Rocket *Fleet::RocketFactory(float initial_up_force)
{
	Rocket *pr;
	int chooseType = rand() % 3;
	
	if ((chooseType = 1))
	{
		pr = new Palmtree;
		
	}
	else if ((chooseType = 2))
	{
		pr = new Streamer;
		
	}
	else if ((chooseType = 3))
	{
		pr = new DoubleStreamer;
		
	}


	(*pr).SetForce(initial_up_force, 4.0 + frand());
	
	//pushback or you can push it back in birth

	return pr;
}