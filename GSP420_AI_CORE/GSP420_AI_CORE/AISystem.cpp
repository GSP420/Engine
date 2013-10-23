#include "AISystem.h"

AISystem::AISystem()
{	
	srand(time(NULL));
	id = 0;
}

void AISystem::AI_Update()
{	// called during main update loop, causes all agents to update
	if(agents.size() > 0)
	{
		// loop through all the behaviors in the agents map, and have them "behave"
		for(agentIterator = agents.begin(); agentIterator != agents.end(); agentIterator++)
		{
			Behavior* currentBehavior = agentIterator->second;
			currentBehavior->assessEnvironment(player);
			currentBehavior->behave();
		}
	}
}

void AISystem::registerAgent(GenericEnemy agent, Behavior* behavior)
{	// add a new agent to the AI system
	agent.self->setAgentId(id++);
	agents[id] = behavior;
}

void AISystem::unregisterAgent(GenericEnemy agent)
{	//remove an agent, typically because it is destroyed
	int temp = 0;
	agent.self->getAgentId(temp);
	delete agents[temp];
	agents.erase(temp);
}

void AISystem::regeisterPlayer(Agent* playerAgent)
{
	player = playerAgent;
}