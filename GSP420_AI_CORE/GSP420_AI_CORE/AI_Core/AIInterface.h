#pragma once
#include"ICore.h"
#include"AISystem.h"
#include"Agent.h"



class AIInterface : public ICore
{
public:
	void Startup(Agent* player);
	void Update();
	void Shutdown();
	void Register(GenericEnemy entity, Behavior* behavior);
	void Unregister(GenericEnemy entity);
private:
	static AISystem*	AI;
};

