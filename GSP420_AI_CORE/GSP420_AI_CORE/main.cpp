#include "MainCore.h"
#include <Windows.h>
#include <iostream>
using namespace std;

bool running;

void InitWind();

int main(int argc, char **argv)
{
	//window handle
	HWND hWnd;
	int width;
	int height;
	bool windowed;
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

	//default window size
	width = 800;
	height = 600;
	windowed = true;

	main_core->Startup(hWnd, width, height, windowed);
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

void InitWindow(void)
{
	WNDCLASSEX wndClass;  
	ZeroMemory(&wndClass, sizeof(wndClass));

	// set up the window
	wndClass.cbSize			= sizeof(WNDCLASSEX);			// size of window structure
	wndClass.lpfnWndProc	= (WNDPROC)WndProc;				// message callback
	wndClass.lpszClassName	= WINDOW_TITLE;					// class name
	wndClass.hInstance		= g_hInstance;					// handle to the application
	wndClass.hCursor		= LoadCursor(NULL, IDC_ARROW);	// default cursor
	wndClass.hbrBackground	= (HBRUSH)(COLOR_WINDOWFRAME);	// background brush

	// register a new type of window
	RegisterClassEx(&wndClass);

	g_hWnd = CreateWindow(
		WINDOW_TITLE, WINDOW_TITLE, 							// window class name and title
		g_bWindowed ? WS_OVERLAPPEDWINDOW | WS_VISIBLE:(WS_POPUP | WS_VISIBLE),// window style
		CW_USEDEFAULT, CW_USEDEFAULT,							// x and y coordinates
		SCREEN_WIDTH, SCREEN_HEIGHT,							// width and height of window
		NULL, NULL,												// parent window and menu
		g_hInstance,											// handle to application
		NULL);

	// Display the window
	ShowWindow(g_hWnd, SW_SHOW);
	UpdateWindow(g_hWnd);
}