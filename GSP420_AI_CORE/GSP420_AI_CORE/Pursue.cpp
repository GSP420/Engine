#include "Pursue.h"

Pursue::Pursue(Agent* currentAgent, Agent* targetAgent)
{
	self	= currentAgent;
	target	= targetAgent;
}

void Pursue::enter()
{
}

void Pursue::enact()
{
	float selfCurrentPosition[3] = {0.0f, 0.0f, 0.0f};
	float targetVelocity[3] = {0.0f, 0.0f, 0.0f};
	float targetCurrentPosition[3] = {0.0f, 0.0f, 0.0f};
	float targetFuturePosition[3] = {0.0f, 0.0f, 0.0f};	

	self->getPosition(selfCurrentPosition);
	target->getVelocity(targetVelocity);
	target->getPosition(targetCurrentPosition);
	target->getPosition(targetFuturePosition);	// initialize target's future position with target's current position until for loop runs

	float updateTime = 1 / 20;													// need to figure out how many updates per second????????

	// calculate the future position of target in 3D
	//for (int i = 0; i < 1; i++)
	//{
		if (targetFuturePosition[0] == selfCurrentPosition[0]) {targetFuturePosition[0] = targetCurrentPosition[0];}
		else targetFuturePosition[0] = targetCurrentPosition[0] + targetVelocity[0] * updateTime;
	//}

	Steering::Seek(self, targetFuturePosition);
}

void Pursue::exit()
{
}