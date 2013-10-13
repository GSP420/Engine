#pragma once
//used for rotational calculations, mainly for 3D
#define PI ((float)3.141592654f)
#define ToRadian(degree) ((degree) * (PI / 180.0f))
#define ToDegree(radian) ((radian) * (180.0f / PI))

#include "Agent.h"

class Steering
{
public:
	static void MatchVelocity(Agent*, Agent*);	//use to match velocity
	static void RotationAlign(Agent*, Agent*);	//use to face target like a turret
	static void Seek(Agent*, Agent*);
	static void Seek(Agent*, float[3]);
	static void Flee(Agent*, Agent*);
	static void Arrive(Agent*, Agent*);
};
