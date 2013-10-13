#pragma once
#include "AI_Core/State.h"
#include "AI_Core/Steering.h"

class Evade : public State
{
	private:
		Agent* self;
		Agent* target;
	public:
		Evade(Agent*, Agent*);
		void enter();
		void enact();
		void exit();
		float getRandomPosition();
};