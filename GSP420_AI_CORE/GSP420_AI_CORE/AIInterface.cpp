#include"AIInterface.h"



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