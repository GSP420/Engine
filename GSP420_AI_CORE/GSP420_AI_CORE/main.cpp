#include "MainCore.h"
#include <iostream>
using namespace std;

//window handle
HWND hWnd;
HINSTANCE dInstance;
bool running;

//graphics stuff
LPDIRECT3D9			pD3DObject;
LPDIRECT3DDEVICE9	pD3DDevice;
LPD3DXFONT			pFont;
bool Wireframe = false;
float yAngle = 0;
int NumVertices = 6;
const int NumMeshes = 1;
const int AUTHORS = 29;
void Init(int widht, int height);

char* authors[AUTHORS] = {
						"Alex Larioza",
						"Alexander Hunsiker",
						"Andrew Ebert",
						"Antwan Wynn",
						"Brandon Manuel",
						"Christopher Cone",
						"Cody Bennett",
						"Darion Wallace",
						"David Emerson",
						"Eric Bailey",
						"Erick Garcia",
						"John Berg",
						"John Bohlier",
						"Jordan Swanson",
						"Josh Goldsmith",
						"Joshua Archer",
						"Joshua Murrill",
						"Justin Porras",
						"Latisha Harris",
						"Mark Kirol",
						"Michael Sanders",
						"Michael Young",
						"Miguel Testa",
						"Nathanael Blanchard",
						"Sean Palmer",
						"Stephen Roebuck",
						"Zachary Gauld",
					};

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
		1920, 1080,
		NULL,
		NULL,
		dInstance,
		NULL);


	// Display the window
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);

	int width;
	int height;
	bool windowed;

	//default window size
	width = 1920;
	height = 1080;
	windowed = true;

	Init(width, height);
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
	EntityManager* entity_core = main_core->GetEntityManager();
	Clock* clock_manager = main_core->GetClock();

	
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
		scale[i] = .1;
	}

	//setup for player
	//DO SOMETHING HERE
	Entity* player;
	player = new Entity;
	player->SetEntity("player", "player");
	//REPLACE 0'S WITH POSITION VALUES
	pos[0] = -3, pos[1] = 2.5, pos[2] = 20;
	scale[0] = .1, scale[1] = .1, scale[2] = .1; 
	player->agentData.setPosition(pos);
	player->agentData.setRotation(rot);
	player->agentData.setScale(scale);
	physics_core->setAABB(D3DXVECTOR3(/*FILL IN*/), D3DXVECTOR3(/*FILL IN*/), "player");
	ai_core->regeisterPlayer(&player->agentData);

	//setup for enemy
	//DO SOMETHING HERE
	Entity* enemy;
	enemy = new Entity;
	enemy->SetEntity("enemy", "basic");
	//REPLACE 0'S WITH POSITION VALUES
	pos[0] = -3, pos[1] = 2.5, pos[2] = 20;
	scale[0] = .1, scale[1] = .1, scale[2] = .1; 
	enemy->agentData.setPosition(pos);
	enemy->agentData.setRotation(rot);
	enemy->agentData.setScale(scale);
	physics_core->setAABB(D3DXVECTOR3(/*FILL IN*/), D3DXVECTOR3(/*FILL IN*/), "enemy");
	ai_core->registerAgent(&enemy->agentData); //look at removing the 0 here for a behavior isnt needed as AI sits, it automatically cycles through all states of an enemy already
			
			
	//setup for platforms
	//DO SOMETHING HERE
	Entity* platform;
	platform = new Entity;
	platform->SetEntity("platform", "platform");
	//REPLACE 0'S WITH POSITION VALUES
	pos[0] = 0, pos[1] = 0, pos[2] = 20; //THIS WILL MOST LIKELY BE REMOVED AS MULTIPLE PLATFORMS NEED DIFFERENT POSITION AND ROTATION VALUES, DO BEFORE RENDERING WHEN CREATEING MULTIPLES OF THIS MESH
	scale[0] = 100, scale[1] = .01, scale[2] = .1; 
	platform->agentData.setPosition(pos);
	platform->agentData.setRotation(rot);
	platform->agentData.setScale(scale);
	physics_core->setAABB(D3DXVECTOR3(/*FILL IN*/), D3DXVECTOR3(/*FILL IN*/), "platform");
	
	//load the mesh model to use
	Meshes cube;
	cube.load_meshes("cube.X", pD3DDevice);
	//cube.set_meshes(pos, rot, scale);
	//camera setup
	//DO SOMETHING HERE
	Camera camera;
	camera.Init();
	camera.SetAR(width, height);
	
	//tex to use to write
	Text gText;
	D3DXCreateFont(pD3DDevice, 30, 0, FW_BOLD, 0, false, 
                  DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY,
                  DEFAULT_PITCH | FF_DONTCARE, TEXT("Times New Roman"), 
                  &pFont);
	gText.Init(22, pD3DDevice);

	//light setup
	//DO SOMETHING HERE
	//graphics_core->PointLight(
		//D3DXVECTOR3(/*FILL IN*/),	//position
		//D3DXCOLOR(1, 1, 1, 1),		//diffuse
		//D3DXCOLOR(1, 1, 1, 1));		//ambient
			
			
			
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
	int gameState = 1;
	/*
	gamestate to tell the engine what state the game is in. Menu, Game Logic, Credtis, etc.
	swtich cases to switch between the different states running the appropiate functions
	state 1 - Menu
	state 2 - Game Logic
	state 3 - Credits
	state 4 - shutdown application
	*/
	MSG  msg;
    msg.message = WM_NULL;
	char str[128];
	RECT rect;

	while(msg.message != WM_QUIT)
	{
		// If there are Window messages then process them.
		if(PeekMessage( &msg, 0, 0, 0, PM_REMOVE ))
		{
            TranslateMessage( &msg );
            DispatchMessage( &msg );
		}
		// Otherwise, do animation/game stuff.
		else
        {
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
				//DO SOMETHING HERE
				
				pD3DDevice->BeginScene();
				pD3DDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0) , 1.0f, 0);
				
				GetClientRect(hWnd, &rect);
				sprintf(str, "Engine Demo");
				pFont->DrawText(NULL, str, -1, &rect,
						DT_TOP | DT_CENTER | DT_NOCLIP , D3DCOLOR_ARGB(255, 
						255, 
						255, 
						255			
						));

				gText.DisplayText("Play Demo - (1)", width / 2, height * 0.25f, 50, 25, WHITE);
				gText.DisplayText("Credits - (2)", width / 2, height * 0.5f, 50, 25, WHITE);
				gText.DisplayText("Exit Demo - (3)", width / 2, height * 0.75f, 50, 25, WHITE);
				pD3DDevice->EndScene();
				pD3DDevice->Present(0, 0, 0, 0);
				main_core->Update(enemy, gameState);

				if(input_core->OnePressed())
				{
					gameState = 2;
				}

				if(input_core->TwoPressed())
				{
					gameState = 3;
				}

				if(input_core->ThreePressed())
				{
					gameState = 4;
				}

				break;
			case (2)://game logic state
				float temp[3];
				float temp2[3];
				player->agentData.getPosition(temp);
				if(temp[1] <= 101)
					jump = false;

				if(input_core->EscPressed()) gameState = 1;

				if(input_core->APressed())
				{
					player->agentData.getPosition(temp);
					player->agentData.getAcceleration(temp2);
					temp[0] -= .2f;
					player->agentData.setPosition(temp);
					/*
					temp2[0] -= .1f;
					physics_core->setAccel(temp2, "player");
					D3DXVECTOR3 vec;
					vec = physics_core->getVel("player");
					player->agentData.setAcceleration(temp2);
					temp[0] += vec.x;
					temp[1] += vec.y;
					temp[2] += vec.z;
					player->agentData.setPosition(temp);
					*/
				}

				if(input_core->DPressed())
				{
					player->agentData.getPosition(temp);
					player->agentData.getAcceleration(temp2);
					temp[0] += .2f;
					player->agentData.setPosition(temp);
					/*
					temp2[0] += .1f;
					physics_core->setAccel(temp2, "player");
					D3DXVECTOR3 vec;
					vec = physics_core->getVel("player");
					player->agentData.setAcceleration(temp2);
					temp[0] += vec.x;
					temp[1] += vec.y;
					temp[2] += vec.z;
					player->agentData.setPosition(temp);
					*/
				}

				if(!jump)
				{
					if(input_core->SpaceBar())
					{
						jump = true;
						player->agentData.getPosition(temp);
						player->agentData.getAcceleration(temp2);
						/*
						temp2[1] += 1.0f;
						physics_core->setAccel(temp2, "player");
						D3DXVECTOR3 vec;
						vec = physics_core->getVel("player");
						player->agentData.setAcceleration(temp2);
						temp[0] += vec.x;
						temp[1] += vec.y;
						temp[2] += vec.z;
						player->agentData.setPosition(temp);
						*/
					}
				}

				//update
				main_core->Update(enemy, gameState);

				
				if (Wireframe)
				{
					pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
				}
				else
				{
					pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				}
				pD3DDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0) , 1.0f, 0);
				camera.dxSetProjection(pD3DDevice);
				camera.dxSetView(pD3DDevice);
				pD3DDevice->BeginScene();

				enemy->agentData.getPosition(pos);
				enemy->agentData.getScale(scale);
				enemy->agentData.getRotation(rot);
				cube.set_meshes(pos, rot, scale);
				cube.draw_meshes(pD3DDevice);

				player->agentData.getPosition(pos);
				player->agentData.getScale(scale);
				player->agentData.getRotation(rot);
				cube.set_meshes(pos, rot, scale);
				cube.draw_meshes(pD3DDevice);

				platform->agentData.getPosition(pos);
				platform->agentData.getScale(scale);
				platform->agentData.getRotation(rot);
				cube.set_meshes(pos, rot, scale);
				cube.draw_meshes(pD3DDevice);

				GetClientRect(hWnd, &rect);
				sprintf(str, "GSP 420 Running Demo");
				pFont->DrawText(NULL, str, -1, &rect,
						DT_TOP | DT_LEFT | DT_NOCLIP , D3DCOLOR_ARGB(255, 
						255, 
						255, 
						255			
						));
				pD3DDevice->EndScene();
				pD3DDevice->Present(0, 0, 0, 0);
				break;
			case (3)://credits state
				//setup credits with UI and Graphics
				//loop till gameState changes
				//update
				pD3DDevice->BeginScene();
				pD3DDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(122, 0, 0) , 1.0f, 0);
				
				GetClientRect(hWnd, &rect);

				pFont->DrawText(NULL, str, -1, &rect,
						DT_TOP | DT_CENTER | DT_NOCLIP , D3DCOLOR_ARGB(255, 
						255, 
						255, 
						255			
						));

				gText.DisplayText("CREDITS:", width / 2, 35, 50, 25, WHITE);

				for (int i = 0; i < AUTHORS; i++)
				{
					gText.DisplayText(authors[i], width / 2, i * 25 + 60, 100, 10, WHITE);
				}

				
				pD3DDevice->EndScene();
				pD3DDevice->Present(0, 0, 0, 0);
				main_core->Update(enemy, gameState);

				if(input_core->EscPressed()) gameState = 1;

				break;
			case (4):	//shutdown application
				//shutdown
				main_core->Shutdown();
				pD3DDevice->Release();
				pD3DObject->Release();
				//destroy application
				msg.message = WM_QUIT;
				break;
			}
		}	
	}
	return (int)msg.wParam;
}

void Init(int width, int height) 
{
	// create direct3d object
	pD3DObject = Direct3DCreate9(D3D_SDK_VERSION);

	if (pD3DObject) {

		// create direct3d device
		D3DPRESENT_PARAMETERS d3dpp;
		d3dpp.BackBufferCount = 1;
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
		d3dpp.BackBufferWidth = width;
		d3dpp.BackBufferHeight = height;
		d3dpp.Windowed = true;
		d3dpp.hDeviceWindow = hWnd;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
		d3dpp.MultiSampleQuality = 0;
		d3dpp.EnableAutoDepthStencil = true;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
		d3dpp.Flags = 0;
		d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

		pD3DObject->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&pD3DDevice);


		// set render states
		pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

		pD3DDevice->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(100, 100, 100) );

		D3DXCreateFont(pD3DDevice, 30, 0, FW_BOLD, 0, false, 
                  DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY,
                  DEFAULT_PITCH | FF_DONTCARE, TEXT("Times New Roman"), 
                  &pFont);

	}
}