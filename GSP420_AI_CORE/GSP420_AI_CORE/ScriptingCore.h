// *******************************
// Interface Class - ScriptingCore
// *******************************
#pragma once
#include <string>
#include "Script.h"
#include <string>
#include "lua.hpp"
#pragma comment(lib, "lua5.1.lib")
using namespace std;

class ScriptingCore
{
public:
	ScriptingCore();
	~ScriptingCore();

	void Startup();
	void Update(std::string);
	void Shutdown();
		
	bool loadScript(std::string scriptfile);

	std::string getGlobalString(std::string name);
	void setGlobalString(std::string name, std::string value);
		
	double getGlobalNumber(std::string name);
	void setGlobalNumber(std::string name, double value);
		
	bool getGlobalBoolean(std::string name);
	void setGlobalBoolean(std::string name, bool value);
		
	void runFunction(std::string name);

	Script *script; // Script class pointer to ScriptingCore object

	double width;		// SCREEN WIDTH
	double height;		// SCREEN HEIGHT
	int color;		// COLORDEPTH
	bool fscreen;	// FULLSCREEN
	float musicVolume;	//MUSIC VOLUME
	float soundVolume;	// SOUND VOLUME
	int gravity;	//GRAVITY
	int maxAcceleration;	//MAXIMUM ACCELERATION
	int maxVelocity; // MAXIMUM VELOCITY
	
private:
	lua_State *luaState;

	

};

