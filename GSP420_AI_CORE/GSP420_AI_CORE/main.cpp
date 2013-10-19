#include "MainCore.h"
#include <Windows.h>
#include <iostream>
using namespace std;

bool running;


int main(int argc, char **argv)
{
	//window handle
	HWND hWnd;
	//create engine, using MainCore to instantiate a singelton of each otehr core
	MainCore* main_core = new MainCore();
	//create pointer to access each core through MainCore
	AISystem* ai_core = main_core->GetAIManager();
	Sound* sound_core = main_core->GetAudioCoreSound();
	SoundEffect* sfx_core = main_core->GetAudioCoreSoundEffect();
	PhysicsInterface* phsics_core = main_core->GetPhysicsManager();
	Input* input_core = main_core->GetInputManager();
	UI* ui_core = main_core->GetUIManager();
	ScriptingCore* script_core = main_core->GetScriptManager();
	CoreManager* graphics_core = main_core->GetGraphicsManager();

	/*
	gamestate to tell the engine what state the game is in. Menu, Game Logic, Credtis, etc.
	swtich cases to switch between the different states running the appropiate functions
	state 1 - Menu
	state 2 - Game Logic
	state 3 - Credits
	state 4 - shutdown application
	*/
	int gameState = 1;
	do
	switch(gameState)
	{
		case 1://menu state
			/*
			setup menu with UI and Graphics
			update
			render
			loop till user input to change gamestate
			*/
			
			while(gameState == 1)
			{
				//DO SOMETHING HERE
				//graphics_core->SetText(); //fill in the parameters for the Demo Name here
				//graphics_core->SetText(); //fill in the parameters for a pressed keyboard button to play the demo here
				//graphics_core->SetText(); //fill in the parameters for a pressed keyboard button to display credits here
				//graphics_core->SetText(); //fill in the parameters for a pressed keyboard button to exit program here
				
				main_core->Update();
			}
			break;
		case 2://game logic state
			/*
			setup UI and Graphics for game logic
			create assets - game objects, sounds, whatever used load and create if need to create
			create camera
			
			*/
			//loop till gameState changes
			//DO SOMETHING HERE
			//graphics_core->loadMesh(); //load mesh for player here
			Entity* player;
			player = new Entity;
			ai_core->regeisterPlayer(&player->agentData);
			while(gameState == 1)
			{
				//update
				main_core->Update();
			}
			break;
		case 3://credits state
			
			//setup credits with UI and Graphics
			//loop till gameState changes
			while(gameState == 1)
			{
				//update
				main_core->Update();
			}
			break;
		case 4://shutdown application
			{
				//shutdown
				main_core->Shutdown();
				//destroy application
				PostQuitMessage(0);
			}
			break;
		continue;
	}
	while(gameState != 4);
	
}