#pragma once
/*
* This is a basic wandering state. the agent moves a random number of pixels
* between 1 and 10 in all directions.
*/

#include "AI_Core/State.h"
#include "AI_Core/Steering.h"

class Wander : public State
{
	private:
		Agent* self;
		Agent* target;
	public:
		Wander(Agent*, Agent*);
		void enter();
		void enact();
		void exit();
		float getRandomPosition();
};
