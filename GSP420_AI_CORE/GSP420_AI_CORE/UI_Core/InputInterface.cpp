#include "InputInterface.h"


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
			return input->WPressed();

	}
	bool					InputInterface::APressed(){

		return input->APressed();

	}
	bool					InputInterface::SPressed(){

		return input->SPressed();

	}
	bool					InputInterface::DPressed(){

		return input->DPressed();

	}
	bool					InputInterface::SpaceBar(){

		return input->SpaceBar();

	}
	bool					InputInterface::LBUTTONPressed(){

		return input->LBUTTONPressed();

	}
	bool					InputInterface::RBUTTONPressed(){

		return input->RBUTTONPressed();

	}


	////////////NOT DONE YET//////
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