#include "InputInterface.h"
#include "UI_Core\Input.h"

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

