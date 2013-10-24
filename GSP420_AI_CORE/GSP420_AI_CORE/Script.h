/*
	Script.h - Simple access to the Lua library
*/

#pragma once

#include <iostream>
#include <string>
#include "lua.hpp"
#pragma comment(lib, "lua5.1.lib")

class Script 
{
	private:
		lua_State *luaState;

	public:
		Script();
		Script(std::string scriptfile);
		~Script();
		
		bool loadScript(std::string scriptfile);

		std::string getGlobalString(std::string name);
		void setGlobalString(std::string name, std::string value);
		
		double getGlobalNumber(std::string name);
		void setGlobalNumber(std::string name, double value);
		
		bool getGlobalBoolean(std::string name);
		void setGlobalBoolean(std::string name, bool value);
		
		void runFunction(std::string name);

		double sWidth; 
		double sHeight; 
		int sColor; 
		bool sFScreen; 

		//AUDIO CORE VARIABLES (sMusicVolume, sSoundVolume)
		float sMusicVolume; 
		float sSoundVolume; 
	

		//PHYSICS CORE VARIABLES (sGravity, sMaxVelocity, sMaxAcceleration)
		int sGravity; 
		int sMaxVelocity; 
		int sMaxAcceleration; 

};