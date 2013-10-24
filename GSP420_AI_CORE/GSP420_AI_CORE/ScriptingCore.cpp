// ScriptingCore.cpp : Interface Class 
//
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include "Script.h"
#include "Scriptingcore.h"

ScriptingCore::ScriptingCore()
{
}

ScriptingCore::~ScriptingCore()
{
}

void ScriptingCore::Startup()
{ 
	// Initialize Core
	script = new Script();

	//Script file Name
	string sName = "script.lua";

	if(loadScript(sName.c_str()) == false)
		 cout << "Invalid Script File" << endl;
		//return 1;

	//GRAPHICS CORE VARIABLES (sWidth, sHeight, sColor,sFScreen)
	width = getGlobalNumber("SCREENWIDTH");
	height = getGlobalNumber("SCREENHEIGHT");
	color = getGlobalNumber("COLORDEPTH");
	fscreen = getGlobalBoolean("FULLSCREEN");
	

	//AUDIO CORE VARIABLES (sMusicVolume, sSoundVolume)
	musicVolume = getGlobalNumber("MUSIC_VOLUME");
	soundVolume = getGlobalNumber("SOUND_VOLUME");
	

	//PHYSICS CORE VARIABLES (sGravity, sMaxVelocity, sMaxAcceleration)
	gravity = (int)getGlobalNumber("GRAVITY");
	maxVelocity = (int)getGlobalNumber("MAX_VELOCITY");
	maxAcceleration = (int)getGlobalNumber("MAX_ACCELERATION");

}

void ScriptingCore::Update(std::string name)
{
	/************************************************************************************
	 NO NEED TO UPDATE. CALL SCRIPTING CORE TO GET INFO FROM SCRIPT THEN SHUT DOWN CORE.
	*************************************************************************************/

	script->runFunction(name);

}

void ScriptingCore::Shutdown()
{
	// Shutdown Core
	delete script;
}

/******************************************************************************************
ScriptingCore Functions call Script Class functions with the same name
******************************************************************************************/
bool ScriptingCore::loadScript(std::string scriptfile)
{
	bool value = script->loadScript(scriptfile);
	return value;
}


std::string ScriptingCore::getGlobalString(std::string name)
{
	std::string value = script->getGlobalString(name);
	
	return value;
}

void ScriptingCore::setGlobalString(std::string name, std::string value)
{
	script->setGlobalString(name,value);
}

double ScriptingCore::getGlobalNumber(std::string name)
{
	double value = script->getGlobalNumber(name);
	
	return value;
}

void ScriptingCore::setGlobalNumber(std::string name, double value)
{
	script->setGlobalNumber(name,value);
}

bool ScriptingCore::getGlobalBoolean(std::string name)
{
	bool value = script->getGlobalBoolean(name);
	
	return value;
}   

void ScriptingCore::setGlobalBoolean(std::string name, bool value)
{
	script->setGlobalBoolean(name,value);
}

void ScriptingCore::runFunction(std::string name)
{
	script->runFunction(name);
}



