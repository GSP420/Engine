#pragma once
/*
* this is a placeholed agent class. The main core should use this, or provide us with one
* that has the same functionality. 
*/

class Agent
{
	private:
		float	rotation[3];
		float	position[3];
		float	velocity[3];
		float	destination[3];
		int		agentId;
		float	acceleration[3];
		float	scale[3];
	public:
		Agent();
		void getRotation(float[3]);
		void setRotation(float[3]);
		void getPosition(float[3]);
		void setPosition(float[3]);
		void getVelocity(float[3]);
		void setVelocity(float[3]);
		void getDestination(float[3]);
		void setDestination(float[3]);
		void getAcceleration(float[3]);
		void setAcceleration(float[3]);
		void setAgentId(int);
		void getAgentId(int);
		void setScale(float[3]);
		void getScale(float[3]);
};