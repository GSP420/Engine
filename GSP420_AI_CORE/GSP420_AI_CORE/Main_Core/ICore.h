// interface for ICore 
// Startup() :void
// Update() :void
// Render() :void
// Shutdown() :void
// virtual members 
#pragma once
#include <iostream>
using namespace std;

class ICore {
public:
	//starts the core interface
	virtual void Startup(void*) = 0;
	//updates the core interface
	virtual void Update(void*) = 0;
	//shutdowns the core interface
	virtual void Shutdown(void*) = 0;
};