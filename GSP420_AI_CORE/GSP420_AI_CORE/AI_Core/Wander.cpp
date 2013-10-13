#include "Wander.h"
#include <stdlib.h> 
#include <iostream> 

Wander::Wander(Agent* selfAgent, Agent* targetAgent)
{
	self	= selfAgent;
	target	= targetAgent;	// for this state, we don't actually use the target, which is the player.
							// but it is important to use it here just as an example, because most
							// states will actually care about the player
}

void Wander::enter()
{

}

void Wander::enact()
{
	// generate a random spot to move too
	float randomOffset[3];
	randomOffset[0] = getRandomPosition();
	randomOffset[1] = getRandomPosition();
	randomOffset[2] = getRandomPosition();

	// seek to that spot
	Steering::Seek(self,randomOffset);

	//debug logging
		std::cout << "Enemy position: " << randomOffset[0] << " , " << randomOffset[1] << " , " << randomOffset[2] << std::endl;
		system("pause");
	//end debug logging
}

void Wander::exit()
{// we won't use this either, but we need to override it because it is a virtual method
}

float Wander::getRandomPosition()
{
	// get a random offset from 1 to 10 and then randmoly make it negative or positive
	return (float)(rand() % 10 + 1) * (((rand() % 2) > 0) ? 1 : -1);
}