#include "Steering.h"

//match velocity to that of the target, made for 3D, can be 2D
void Steering::MatchVelocity(Agent* currentAgent, Agent* targetAgent)
{
	float targetVelocity[3];
	targetAgent->getVelocity(targetVelocity);
	currentAgent->setVelocity(targetVelocity);
}

void Steering::Seek(Agent* currentAgent, Agent* targetAgent)
{
	float targetPosition[3];
	float currentPosition[3];
	targetAgent->getPosition(targetPosition);
	currentAgent->getPosition(currentPosition);
	if((currentPosition[0] - targetPosition[0]) < 0)
	{
		targetPosition[0] -= .2;
		currentAgent->setPosition(targetPosition);
	}
	else
	{
		targetPosition[0] += .2;
		currentAgent->setPosition(targetPosition);
	}
}

void Steering::Seek(Agent* currentAgent, float targetPosition[3])
{
	float currentPosition[3];
	currentAgent->getPosition(currentPosition);
	if((currentPosition[0] - targetPosition[0]) < 0)
	{
		targetPosition[0] -= .2;
		currentAgent->setPosition(targetPosition);
	}
	else
	{
		targetPosition[0] += .2;
		currentAgent->setPosition(targetPosition);
	}
}

void Steering::Flee(Agent* currentAgent, Agent* targetAgent)
{
	float selfPosition[3];
	float playerPosition[3];

	currentAgent->getPosition(selfPosition);
	targetAgent->getPosition(playerPosition);

	bool xDirection = selfPosition[0] > playerPosition[0];
	bool yDirection = selfPosition[1] > playerPosition[1];
	bool zDirection = selfPosition[2] > playerPosition[2];

	float fleeVector[3];

	fleeVector[0] = ((xDirection) ? selfPosition[0] + .2 : selfPosition[0] - .2); 
	fleeVector[1] = ((yDirection) ? selfPosition[1] + 0 : selfPosition[1] - 0);
	fleeVector[2] = ((zDirection) ? selfPosition[2] + 0 : selfPosition[2] - 0);

	currentAgent->setDestination(fleeVector);
}

void Steering::Arrive(Agent* currentAgent, Agent* targetAgent)
{
	//	Arrive will adjust the agent's speed based on distance to the player
	//	Arrive written by Mark Kirol

	float selfPosition[3];
	float playerPosition[3];
	
	currentAgent->getPosition(selfPosition);
	targetAgent->getPosition(playerPosition);

	// calculate distance between the player and agent
	float distanceToTargetAgent[3] = {0.0f, 0.0f, 0.0f};
	for (int i = 0; i < 3; i++)
	{
		if (playerPosition[i] > selfPosition[i]) {distanceToTargetAgent[i] = playerPosition[i] - selfPosition[i];}
		else if (playerPosition[i] < selfPosition[i]) {distanceToTargetAgent[i] = selfPosition[i] - playerPosition[i];}
		else distanceToTargetAgent[i] = 0.0f;
	}

	float slow = .1f, fast = .2f;						//Speeds need to be adjusted once a base speed is decided upon			?????
	float close = .5f, far = 2.0f;					//Distances need to be determined once a unit distance is decided upon	?????

	// set speed in 3 dimensions based on distance in the 3 dimensions
	float arriveVelocity[3] = {0.0f, 0.0f, 0.0f};
	for (int j = 0; j < 3; j++)
	{
		if (distanceToTargetAgent[j] >= far) {arriveVelocity[j] = fast;}
		else if ((distanceToTargetAgent[j] > 0.0f) && (distanceToTargetAgent[0] < far)) {arriveVelocity[j] = slow;}
		else arriveVelocity[j] = 0.0f;
	}

	currentAgent->setVelocity(arriveVelocity);

	Seek(currentAgent, targetAgent);
}