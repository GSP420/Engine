// ScriptingCore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include "Script.h"
#include "Scriptingcore.h"
ScriptingCore *script;

int _tmain(int argc, _TCHAR* argv[])
{
	
	Script scripted; // SCRIPT CLASS OBJECT TO HOLD VALUES FROM LUA SCRIPTS

	//cout << "Lua Scripting Test Project\n\n";

	string sName = "script.lua";

	//printf("Loading Script \"%s\"........\n\n", sName.c_str());

	 if(scripted.loadScript(sName.c_str()) == false)
		return 1;

	string name = scripted.getGlobalString("PROGRAM_NAME");
	
	//printf("Script Name: %s\n", name.c_str());
	string version = scripted.getGlobalString("PROGRAM_VERSION");
	//printf("Version: %s\n\n", version.c_str());

	//GRAPHICS CORE VARIABLES (sWidth, sHeight, sColor,sFScreen)
	int sWidth = (int)scripted.getGlobalNumber("SCREENWIDTH");
	int sHeight = (int)scripted.getGlobalNumber("SCREENHEIGHT");
	int sColor = (int)scripted.getGlobalNumber("COLORDEPTH");
	bool sFScreen = scripted.getGlobalBoolean("FULLSCREEN");
	

	//AUDIO CORE VARIABLES (sMusicVolume, sSoundVolume)
	int sMusicVolume = (int)scripted.getGlobalNumber("MUSIC_VOLUME");
	int sSoundVolume = (int)scripted.getGlobalNumber("SOUND_VOLUME");
	

	//PHYSICS CORE VARIABLES (sGravity, sMaxVelocity, sMaxAcceleration)
	int sGravity = (int)scripted.getGlobalNumber("GRAVITY");
	int sMaxVelocity = (int)scripted.getGlobalNumber("MAX_VELOCITY");
	int sMaxAcceleration = (int)scripted.getGlobalNumber("MAX_ACCELERATION");
	
	// DISPLAYS VALUES TO SCREEN FOR TEST
	/*printf("Screen Resolution: %ix%i @ %ibit color\n", sWidth, sHeight, sColor);
	printf("Full Screen: %s\n\n", (sFScreen)?"true":"false");
	printf("Music Volume : %i\n\n", sMusicVolume);
	printf("Sound Volume : %i\n\n", sSoundVolume);
	printf("Gravity : %i\n\n", sGravity);
	printf("Maximum Velocity : %i\n\n", sMaxVelocity);
	printf("Maximum Acceleration : %i\n\n", sMaxAcceleration);*/

	system("pause");

	return 0;
	
};