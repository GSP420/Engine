#include "GenericEnemy.h"

GenericEnemy::GenericEnemy(Agent* selfAgent)
{
	self = selfAgent;
	currentState = NULL;
}

GenericEnemy::~GenericEnemy()
{
	if(currentState != NULL) delete currentState;
}

void GenericEnemy::assessEnvironment(void* player)
{
	// here you would check things like distance to player and decide what type of state to change to
	// because we only have one state for now, we'll just switch to that state. the enter and exit
	// methods are also currently superfluous, but are still used to show how the pattern would look
	// like for more complex behavior assesments.

	Agent* target = (Agent *)player;

	//clear out the state buffer, this needs to be done everytime through the loop
	if(currentState != NULL) 
	{
		currentState->exit();
		delete currentState;
	}

	float me[3];
	float you[3];

	self->getPosition(me);
	target->getPosition(you);

	int distance = this->distance(me, you);

	if(distance > 100)
	{
		currentState = new Wander(self, (Agent*)player);
		currentState->enter();
	}
	else
	{
		if(distance < 10)
		{
			currentState = new Evade(self, (Agent*)player);
			currentState->enter();
		}
		else
		{
			currentState = new Pursue(self, (Agent*)player);
			currentState->enter();
		}
	}
}

void GenericEnemy::behave()
{
	// whatever state we chose, perform the actions associated with it
	currentState->enact();
}

int GenericEnemy::distance(float me[3], float you[3])
{
	//TODO: actual math. Maybe physics can provide this for us?
	return 101;
}