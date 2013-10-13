#pragma once
/*
* This is a derived class that would actually be used in the main core.
* the main team would include this header and at that point able to create an instance of
* this behavior, which is just a "Generic Enemy" that wanders.
*/

#include "AI_Core/Behavior.h"
#include "AI_Core/Wander.h"
#include "AI_Core/Evade.h"
#include "AI_Core/Pursue.h"
#include <stdlib.h> 

class GenericEnemy : public Behavior
{
	private:
		
		State* currentState;
	public:
		GenericEnemy(Agent*);
		~GenericEnemy();
		void assessEnvironment(void* player);
		void behave();
		int distance(float[3],float[3]);
		Agent* self;
};
