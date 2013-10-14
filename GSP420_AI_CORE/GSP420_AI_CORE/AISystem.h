#pragma once
/*
*	This is the main class for the AI Core. As enemies (or other agents) are instantiated
*	in the main game loop, a distinct behavior object is created for each one and then
*	registered with this object. Also, when this AISystem object is instantiated, it will
*	take a reference to the player that it can use to help the agents make judgments about
*	what actions to take and what states to be in.
*
*	Author: Stephen Roebuck
*/
#include <iostream>
#include <hash_map>
#include <time.h>

#include "GenericEnemy.h"

using namespace std;
using namespace stdext;

class AISystem
{
	private:
		Agent* player;
		int	id;
		hash_map<int, Behavior*> agents;					// a list of registered behaviors for
		hash_map<int, Behavior*>::iterator agentIterator;	// list iterator

	public:
		AISystem(Agent*);					// constructor
		void AI_Update();					// called to update all agents
		void registerAgent(GenericEnemy entity, Behavior*);	// register an agent with the AI system
		void unregisterAgent(GenericEnemy entity);			// remove an agent from the AI system
};

AISystem::AISystem(Agent* playerAgent)
{	
	player = playerAgent;
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