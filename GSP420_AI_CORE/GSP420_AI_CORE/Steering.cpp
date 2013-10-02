#include "Steering.h"

//match velocity to that of the target, made for 3D, can be 2D
void Steering::MatchVelocity(Agent* currentAgent, Agent* targetAgent)
{
	float targetVelocity[3];
	targetAgent->getVelocity(targetVelocity);
	currentAgent->setVelocity(targetVelocity);
}

//turn towards target, *****INCOMPLETE*****
void Steering::RotationAlign(Agent* currentAgent, Agent* targetAgent)
{
	currentAgent->setRotation(targetAgent->getOrientation() - currentAgent->getOrientation());
	//now need to put the rotation value in the range of -PI and PI
	
}

void Steering::Seek(Agent* currentAgent, Agent* targetAgent)
{
	float targetPosition[3];
	targetAgent->getPosition(targetPosition);
	currentAgent->setDestination(targetPosition);
}

void Steering::Seek(Agent* currentAgent, float targetPosition[3])
{
	currentAgent->setDestination(targetPosition);
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

	fleeVector[0] = ((xDirection) ? selfPosition[0] + 5 : selfPosition[0] - 5); 
	fleeVector[1] = ((yDirection) ? selfPosition[1] + 5 : selfPosition[1] - 5);
	fleeVector[2] = ((zDirection) ? selfPosition[2] + 5 : selfPosition[2] - 5);

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

	float slow = 1.0f, fast = 3.0f;						//Speeds need to be adjusted once a base speed is decided upon			?????
	float close = 1.0f, far = 10.0f;					//Distances need to be determined once a unit distance is decided upon	?????

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