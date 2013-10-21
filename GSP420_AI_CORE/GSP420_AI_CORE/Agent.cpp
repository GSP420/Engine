#include "Agent.h"

Agent::Agent()
{
	rotation[0] = 0;
	rotation[1] = 0;
	rotation[2] = 0;

	position[0] = 0;
	position[1] = 0;
	position[2] = 0;

	velocity[0] = 0;
	velocity[1] = 0;
	velocity[2] = 0;

	destination[0] = 0;
	destination[1] = 0;
	destination[2] = 0;

	agentId = 0;
}

void Agent::getRotation(float rot[3])
{
	rot[0] = rotation[0];
	rot[1] = rotation[1];
	rot[2] = rotation[2];
}

void Agent::setRotation(float source[3])
{
	rotation[0] = source[0];
	rotation[1] = source[1];
	rotation[2] = source[2];
}

void Agent::getPosition(float source[3])
{
	source[0] = position[0];
	source[1] = position[1];
	source[2] = position[2];
}

void Agent::setPosition(float source[3])
{
	position[0] = source[0];
	position[1] = source[1];
	position[2] = source[2];
}

void Agent::getVelocity(float source[3])
{
	source[0] = velocity[0];
	source[1] = velocity[1];
	source[2] = velocity[2];
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

void Agent::setAgentId(int id)
{
	agentId = id;
}

void Agent::getAgentId(int id)
{
	id = agentId;
}

void Agent::getAcceleration(float accel[3])
{
	accel[0] = acceleration[0];
	accel[0] = acceleration[0];
	accel[0] = acceleration[0];
}

void Agent::setAcceleration(float accel[3])
{
	acceleration[0] = accel[0];
	acceleration[1] = accel[1];
	acceleration[2] = accel[2];
}