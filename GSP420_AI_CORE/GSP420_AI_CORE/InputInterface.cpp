#include "UI_Core\InputInterface.h"


void InputInterface::Startup()
{
	input = new Input();	
}

void InputInterface::Update()
{
	input->Update();
}

void InputInterface::Shutdown()
{
	input->ShutDown();
}


							//Keystroke Checks
	bool					InputInterface::WPressed()
		{

	}
	bool					InputInterface::APressed(){

	}
	bool					InputInterface::SPressed(){

	}
	bool					InputInterface::DPressed(){

	}
	bool					InputInterface::SpaceBar(){

	}
	bool					InputInterface::LBUTTONPressed(){

	}
	bool					InputInterface::RBUTTONPressed(){

	}

							//Keyhold Checks
	bool					InputInterface::WHeld()
	{

	}
	bool					InputInterface::AHeld(){

	}
	bool					InputInterface::SHeld(){

	}
	bool					InputInterface::DHeld(){

	}
	bool					InputInterface::SpaceBarHeld(){

	}
	bool					InputInterface::LBUTTONHeld(){

	}
	bool					InputInterface::RBUTTONHeld(){

	}