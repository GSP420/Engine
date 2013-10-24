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

void AISystem::registerAgent(Agent* agent)
{	// add a new agent to the AI system
	agent->setAgentId(id++);
	agents[id] = new GenericEnemy(agent);
}

void AISystem::unregisterAgent(Agent* agent)
{	//remove an agent, typically because it is destroyed
	int temp = 0;
	agent->getAgentId(temp);
	delete agents[temp];
	agents.erase(temp);
}

void AISystem::regeisterPlayer(Agent* playerAgent)
{
	player = playerAgent;
}