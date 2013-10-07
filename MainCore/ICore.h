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
	virtual void Startup() = 0;
	//updates the core interface
	virtual void Update() = 0;
	//shutdowns the core interface
	virtual void Shutdown() = 0;
};