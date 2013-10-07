#include "AIInterface.h"

void main()
{
	Agent player = Agent();// player object
	AIInterface ai_sys;
	ai_sys.Startup(&player);
	// this would typically be done in a loop, creating several enemy IDs

	Agent enemy = Agent();								// enemy object
	ai_sys.Register(new GenericEnemy(&enemy));	// register enemy ID 0

	// run a couple of updates, to make sure it is all working
	ai_sys.Update();
	ai_sys.Update();
	ai_sys.Update();

	// oh, lets say the enemy ID 0 is now dead, the player killed it
	ai_sys.Unregister(0);	// destroy the enemy bahavior object enemy ID 0

	// run update again, just to make sure nothing crashes
	ai_sys.Update();

}