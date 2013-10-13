#include "Evade.h"
#include <stdlib.h> 

Evade::Evade(Agent* selfAgent, Agent* targetAgent)
{
	self	= selfAgent;
	target	= targetAgent;
}

void Evade::enter()
{
}

void Evade::enact()
{
	Steering::Flee(self, target);
}

void Evade::exit()
{
}

