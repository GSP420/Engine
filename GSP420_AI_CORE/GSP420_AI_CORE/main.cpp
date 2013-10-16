#include "MainCore.h"
#include "AISystem.h"
#include "PhysicsInterface.h"
#include "DXManager.h"
#include "UI.h"
#include <Windows.h>
#include <iostream>
using namespace std;

bool running;


int main(int argc, char **argv)
{
	// Main core test
	MainCore* main_core = new MainCore();

	// AI test
	Agent* player = new Agent();
	AISystem* ai_core = new AISystem(player);

	// Physics Test
	PhysicsInterface* phys_core = new PhysicsInterface();

	// Graphics test
	DXManager* graphics_core = new DXManager();

	// UI test
	UI* ui_core = new UI();

	// Audio test
	//

	// Input test
	//

}

