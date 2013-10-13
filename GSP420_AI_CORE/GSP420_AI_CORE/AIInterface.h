#pragma once
#include"Main_Core/ICore.h"
#include"AI_Core/AISystem.h"
#include"AI_Core/Agent.h"



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

