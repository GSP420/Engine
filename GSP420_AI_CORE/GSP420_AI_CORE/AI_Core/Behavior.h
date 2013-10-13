#pragma once
/*
*	This is a generic behavior class the includes a very basic set of methods 
*	that are used to assess the agent's current environment and state, and then
*	act accordingly. This class is probably best used as a base class, with 
*	subclasses defining behavior specific to that behavior type. i.e., a genric
*	enemy would have basic idle, seek, evade type states, where a boss enemy
*	may include these, as well as more complex behaviors.
*
*	Author: Stephen Roebuck
*/

class Behavior
{
	public:
		virtual void assessEnvironment(void*) = 0;	// decide what state to be in
		virtual void behave() = 0;				// behave according to the current state
};