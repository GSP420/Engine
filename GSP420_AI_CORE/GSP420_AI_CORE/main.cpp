#include "MainCore.h"
#include <iostream>
using namespace std;

//window handle
HWND hWnd;
HINSTANCE dInstance;
bool running;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
        switch(msg)
        {
			case WM_CLOSE:
			case WM_DESTROY:
				PostQuitMessage(0);
				break;
			default:
				return DefWindowProc(hwnd, msg, wParam, lParam);
        }
        return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	dInstance = hInstance;
	// Windows structure
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = dInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = "gameDemoWindow";
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	// register a new type of window
	if (!RegisterClassEx(&wcex))
    {
        MessageBox(
        NULL,
        "Window Error",
        "Could not create window",
        NULL);
    }

	static TCHAR szWindowClass[] = "gameDemoWindow";
	static TCHAR szTitle[] = "Game Demo";

	hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 100,
		NULL,
		NULL,
		dInstance,
		NULL
	);

	// Display the window
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);

	int width;
	int height;
	bool windowed;

	//default window size
	width = 800;
	height = 600;
	windowed = true;

	//create engine, using MainCore to instantiate a singelton of each otehr core
	MainCore* main_core = new MainCore();
	main_core->Startup(hWnd, width, height, windowed);
	//create pointer to access each core through MainCore
	AISystem* ai_core = main_core->GetAIManager();
	Sound* sound_core = main_core->GetAudioCoreSound();
	SoundEffect* sfx_core = main_core->GetAudioCoreSoundEffect();
	PhysicsInterface* physics_core = main_core->GetPhysicsManager();
	Input* input_core = main_core->GetInputManager();
	UI* ui_core = main_core->GetUIManager();
	ScriptingCore* script_core = main_core->GetScriptManager();
	CoreManager* graphics_core = main_core->GetGraphicsManager();
	EntityManager* entity_core = main_core->GetEntityManager();
	Clock* clock_manager = main_core->GetClock();

	

	
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
		case (1)://menu state
			/*
			TO DO IN CASE 1
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
				
				main_core->Update(NULL, gameState);
			}
			break;
		case (2)://game logic state
			/*
			TO DO IN CASE 2
			setup UI and Graphics for game logic
			*/
			//load music stream
			sound_core->Load("Song1.ogg");
			//load sound effect
			sfx_core = new SoundEffect("Jump.wav"); //#5 to play
			

			
			//variables used for entity setups
			LPCSTR fileName;
			float pos[3];
			float rot[3];
			float scale[3];
			for(int i = 0; i < 3; i++)
			{
				pos[i] = 0;
				rot[i] = 0;
				scale[i] = 1;
			}

			//setup for player
			//DO SOMETHING HERE
			Entity* player;
			player = new Entity;
			player->SetEntity("player", "player");
			//REPLACE 0'S WITH POSITION VALUES
			pos[0] = 0, pos[1] = 0, pos[2] = 0;
			player->agentData.setPosition(pos);
			player->agentData.setRotation(rot);
			physics_core->setAABB(D3DXVECTOR3(/*FILL IN*/), D3DXVECTOR3(/*FILL IN*/), "player");
			ai_core->regeisterPlayer(&player->agentData);
			fileName = "rectangle.x";
			graphics_core->loadMesh(fileName);
			graphics_core->setMeshes(pos, rot, scale);

			//setup for enemy
			//DO SOMETHING HERE
			Entity* enemy;
			enemy = new Entity;
			enemy->SetEntity("enemy", "basic");
			//REPLACE 0'S WITH POSITION VALUES
			pos[0] = 0, pos[1] = 0, pos[2] = 0;
			enemy->agentData.setPosition(pos);
			enemy->agentData.setRotation(rot);
			physics_core->setAABB(D3DXVECTOR3(/*FILL IN*/), D3DXVECTOR3(/*FILL IN*/), "enemy");
			ai_core->registerAgent(GenericEnemy(&enemy->agentData), 0); //look at removing the 0 here for a behavior isnt needed as AI sits, it automatically cycles through all states of an enemy already
			fileName = "cube.x";
			graphics_core->loadMesh(fileName);
			graphics_core->setMeshes(pos, rot, scale);
			
			//setup for platforms
			//DO SOMETHING HERE
			Entity* platform;
			platform = new Entity;
			platform->SetEntity("platform", "platform");
			//REPLACE 0'S WITH POSITION VALUES
			pos[0] = 0, pos[1] = 0, pos[2] = 0; //THIS WILL MOST LIKELY BE REMOVED AS MULTIPLE PLATFORMS NEED DIFFERENT POSITION AND ROTATION VALUES, DO BEFORE RENDERING WHEN CREATEING MULTIPLES OF THIS MESH
			platform->agentData.setPosition(pos);
			platform->agentData.setRotation(rot);
			physics_core->setAABB(D3DXVECTOR3(/*FILL IN*/), D3DXVECTOR3(/*FILL IN*/), "platform");
			fileName = "platform.x";
			graphics_core->loadMesh(fileName);
			graphics_core->setMeshes(pos, rot, scale);

			//camera setup
			//DO SOMETHING HERE
			graphics_core->CamInit(
				D3DXVECTOR3(/*FILL IN*/),	//position
				D3DXVECTOR3(/*FILL IN*/),	//look
				D3DXVECTOR3(0, 1, 0),		//up
				1.13f,						//FoV
				width/height,				//Aspect
				1.0f,						//near place
				1000.0f);					//far plane

			//light setup
			//DO SOMETHING HERE
			graphics_core->PointLight(
				D3DXVECTOR3(/*FILL IN*/),	//position
				D3DXCOLOR(1, 1, 1, 1),		//diffuse
				D3DXCOLOR(1, 1, 1, 1));		//ambient
			
			
			
			/*
			TEST THIS CHANGE WHERE NEEDED IF NEEDED
			Z AXIS LOCKED AT 50 FOR PLAYER AND GAME OBJECTS
			Z AXIS LOCKED AT 10 FOR CAMERA
			X AXIS AT 100 FOR BASE LINE OF DEMO
			X AXIS MATCHING PLAYER FOR CAMERA
			Y AXIS AT 100 FOR BASE LINE OF DEMO
			Y AXIS + 25 ABOVE PLAYER
			*/
			//variables for game loop
			bool jump;
			jump = false;
			float time;
			while(gameState == 2)
			{
				D3DXVECTOR3 temp;
				D3DXVECTOR3 temp2;
				player->agentData.getPosition(temp);
				if(temp.y <= 101)
					jump = false;
				if(input_core->APressed())
				{
					player->agentData.getPosition(temp);
					player->agentData.getAcceleration(temp2);
					temp2.x -= 5.0f;
					physics_core->setAccel(temp2);
					temp2 = physics_core->getVel();
					player->agentData.setAcceleration(temp2);
					player->agentData.setPosition(temp + temp2);
				}
				if(input_core->DPressed())
				{
					player->agentData.getPosition(temp);
					player->agentData.getAcceleration(temp2);
					temp2.x += 5.0f;
					physics_core->setAccel(temp2);
					temp2 = physics_core->getVel();
					player->agentData.setAcceleration(temp2);
					player->agentData.setPosition(temp + temp2);
				}
				if(!jump)
				{
					if(input_core->SpaceBar())
					{
						jump = true;
						player->agentData.getPosition(temp);
						player->agentData.getAcceleration(temp2);
						temp2.y += 15.0f;
						physics_core->setAccel(temp2);
						temp2 = physics_core->getVel();
						player->agentData.setAcceleration(temp2);
						player->agentData.setPosition(temp + temp2);
						sfx_core[5].Play();
					}
				}
			
				//update
				main_core->Update(enemy, gameState);
			}
			
			//
			break;
		case (3)://credits state
			//setup credits with UI and Graphics
			//loop till gameState changes
			while(gameState == 3)
			{
				//update
				main_core->Update(NULL, gameState);
			}
			break;
		case (4):	//shutdown application
			
			//shutdown
			main_core->Shutdown();
			//destroy application
			PostQuitMessage(0);
			break;
			
		continue;
	}
	while(gameState != 4);
	return 0;
}