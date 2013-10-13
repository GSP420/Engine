#include "Main_Core/MainCore.h"
#include <Windows.h>
#include <iostream>
using namespace std;


MainCore *engine;
bool running;


int main(int argc, char **argv)
{
	engine = new MainCore();


	engine->Startup();


	// msg structure to catch window messages
	MSG msg; 
	ZeroMemory(&msg, sizeof(msg));


	// game loop
	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}


		engine->Update();


		// debug info
		system("cls");
		cout << "ELAPSED: " << engine->GetClock()->GetElapsed() << endl;
		cout << "FPS: " << engine->GetClock()->GetFPS() << endl;
		cout << "COUNT: " << engine->GetEntityManager()->Count() << endl;
	}


	engine->Shutdown();
}

