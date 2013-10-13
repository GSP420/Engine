// ScriptingCore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include "Script.h"
#include "Scriptingcore.h"

void ScriptingCore::Startup()
{ 
	// Initialize Core
}

void ScriptingCore::Update()
{
	/************************************************************************************
	 NO NEED TO UPDATE. CALL SCRIPTING CORE TO GET INFO FROM SCRIPT THEN SHUT DOWN CORE.
	*************************************************************************************/
}

void ScriptingCore::Shutdown()
{
	// Shutdown Core
	delete script;
}






