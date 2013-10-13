#pragma once
/*
* this is a placeholed agent class. The main core should use this, or provide us with one
* that has the same functionality. 
*/

class Agent
{
	private:
		float orientation;
		float rotation;
		float position[3];
		float velocity[3];
		float destination[3];
		int		agentId;
	public:
		Agent();
		float getOrientation();
		float getRotation();
		void setRotation(float);
		void getPosition(float[3]);
		void setPosition(float[3]);
		void getVelocity(float[3]);
		void setVelocity(float[3]);
		void getDestination(float[3]);
		void setDestination(float[3]);
		void setAgentId(int);
		void getAgentId(int);
};