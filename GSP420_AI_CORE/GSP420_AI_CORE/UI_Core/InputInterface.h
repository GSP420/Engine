#pragma once
#include "Main_Core\ICore.h"
#include "Input.h"
class InputInterface : public ICore
{
public:
	void Startup();
	void Update();
	void Shutdown();

	
							//Keystroke Checks
	bool					WPressed();
	bool					APressed();
	bool					SPressed();
	bool					DPressed();
	bool					SpaceBar();
	bool					LBUTTONPressed();
	bool					RBUTTONPressed();

							//Keyhold Checks
	bool					WHeld();
	bool					AHeld();
	bool					SHeld();
	bool					DHeld();
	bool					SpaceBarHeld();
	bool					LBUTTONHeld();
	bool					RBUTTONHeld();

private:
	static Input*	input;
};

