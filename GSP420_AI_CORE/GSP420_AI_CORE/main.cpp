#include "AISystem.h"

void main()
{
	Agent player = Agent();					// player object
	AISystem ai_sys = AISystem(&player);	// init AI subsystem
	
	// this would typically be done in a loop, creating several enemy IDs

	Agent enemy = Agent();								// enemy object
	ai_sys.registerAgent(0,new GenericEnemy(&enemy));	// register enemy ID 0

	// run a couple of updates, to make sure it is all working
	ai_sys.AI_Update();
	ai_sys.AI_Update();
	ai_sys.AI_Update();

	// oh, lets say the enemy ID 0 is now dead, the player killed it
	ai_sys.unregisterAgent(0);	// destroy the enemy bahavior object enemy ID 0

	// run update again, just to make sure nothing crashes
	ai_sys.AI_Update();

}