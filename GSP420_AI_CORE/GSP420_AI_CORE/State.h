#pragma once
/*
*	This is a generic state class. this calls should be subclassed and have it's methods overridden.
*	for example, an idle state would essentially do nothing, a seek state could seek toward the player
*	a retreat state could move away from the player, etc. the behaviors of each would be defined in the
*	enact() method of the state.
*
*	Author: Stephen Roebuck
*/

class State
{
	public:
		virtual void enter() = 0;	// called when this state is being entered
		virtual void enact() = 0;	// behave according to the current state
		virtual void exit() = 0;	// called when this state is being exited
};