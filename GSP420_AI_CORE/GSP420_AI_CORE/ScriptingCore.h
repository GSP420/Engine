// *******************************
// Interface Class - ScriptingCore
// *******************************
#include <string>
#include "Script.h"
#pragma once
using namespace std;



class ScriptingCore
{
public:
	ScriptingCore();
	~ScriptingCore();

	void Startup();
	void Update();
	void Shutdown();


	
private:
	Script *script;
	int width;		// SCREEN WIDTH
	int height;		// SCREEN HEIGHT
	int color;		// COLORDEPTH
	bool fscreen;	// FULLSCREEN
	int musicVolume;	//MUSIC VOLUME
	int soundVolume;	// SOUND VOLUME
	int gravity;	//GRAVITY
	int maxAcceleration;	//MAXIMUM ACCELERATION
	int maxVelocity; // MAXIMUM VELOCITY

};

