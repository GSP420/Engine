//#include"ICore.h"
#include"AISystem.h"
#include"Agent.h"



class AIInterface
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

void AIInterface::Startup(Agent* player)
{
	AI = new AISystem(player);	
}

void AIInterface::Update()
{
	AI->AI_Update();
}

void AIInterface::Shutdown()
{

}

void AIInterface::Register(GenericEnemy entity, Behavior* behavior)
{
	AI->registerAgent(entity, behavior);
}

void AIInterface::Unregister(GenericEnemy entity)
{
	AI->unregisterAgent(entity);
}