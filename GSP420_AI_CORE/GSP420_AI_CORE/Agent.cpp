#include "Agent.h"

Agent::Agent()
{
	orientation = 0;
	rotation = 0;

	position[0] = 0;
	position[1] = 0;
	position[2] = 0;

	velocity[0] = 0;
	velocity[1] = 0;
	velocity[2] = 0;

	destination[0] = 0;
	destination[1] = 0;
	destination[2] = 0;
}

float Agent::getOrientation()
{
	return orientation;
}

float Agent::getRotation()
{
	return rotation;
}

void Agent::setRotation(float source)
{
	rotation = source;
}

void Agent::getPosition(float destination[3])
{
	destination[0] = position[0];
	destination[1] = position[1];
	destination[2] = position[2];
}

void Agent::setPosition(float source[3])
{
	position[0] = source[0];
	position[1] = source[1];
	position[2] = source[2];
}

void Agent::getVelocity(float destination[3])
{
	destination[0] = velocity[0];
	destination[1] = velocity[1];
	destination[2] = velocity[2];
}

void Agent::setVelocity(float source[3])
{
	velocity[0] = source[0];
	velocity[1] = source[1];
	velocity[2] = source[2];
}

void Agent::getDestination(float tDestination[3])
{
	tDestination[0] = destination[0];
	tDestination[1] = destination[1];
	tDestination[2] = destination[2];
}

void Agent::setDestination(float source[3])
{
	destination[0] = source[0];
	destination[1] = source[1];
	destination[2] = source[2];
}