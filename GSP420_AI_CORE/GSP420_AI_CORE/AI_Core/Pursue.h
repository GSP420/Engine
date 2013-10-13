#pragma once
/*
*	Persue takes a players location, predicts its position in a few frames, based on its velocity,
*	and current direction of movement and makes the enemy agent seek to that location.
*	written by Mark Kirol
*/

#include "State.h"
#include "Steering.h"

class Pursue : public State
{
	private:
		Agent* self;
		Agent* target;	
	public:
		Pursue(Agent*, Agent*);
		void enter();
		void enact();
		void exit();
};
