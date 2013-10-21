#include "Input.h"
#include <direct.h>

//Macro needed to reply whether or not a key being checked was pressed
#define KEYDOWN(name, key) (name[key] & 0x80)

//Macro to check whether or not a mouse button was pressed
#define BUTTONDOWN(name, key) (name.rgbButtons[key] & 0x80)

Input::Input(void)
{
	for(int i = 0; i < sizeof(KeyWasDown);i++)
	{
		KeyWasDown[i] = false;
	}

	for(int j = 0; j < sizeof(ButtonWasDown);j++)
	{
		ButtonWasDown[j] = false;
	}	
}//Input


bool Input::InitDirectInput(void)
{
	HRESULT hr;
	hr = DirectInput8Create(GetModuleHandle(NULL),DIRECTINPUT_VERSION,IID_IDirectInput8,(void**)&m_pDIObject,NULL);
if(FAILED(hr))
 {
 MessageBox(NULL,"DirectInput8Create() failed!","InitDirectInput()",MB_OK);
 return false;
 }

return true;
}//InitDirectInput

bool Input::InitKeyboard(HWND hWnd)
{
	HRESULT hr;
	hr = m_pDIObject->CreateDevice(GUID_SysKeyboard,&m_pDIKeyboardDevice,NULL);
if(FAILED(hr))
 {
 MessageBox(NULL,"CreateDevice() failed!","InitKeyboard()",MB_OK);
 return false;
 }

	hr = m_pDIKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
if(FAILED(hr))
 {
 MessageBox(NULL,"SetDataFormat() failed!","InitKeyboard()",MB_OK);
 return false;
 }

	hr = m_pDIKeyboardDevice->SetCooperativeLevel(NULL,DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
if(FAILED(hr))
 {
 MessageBox(NULL,"SetCooperativeLevel() failed!","InitKeyboard()",MB_OK);
 return false;
 }

	hr = m_pDIKeyboardDevice->Acquire();
if(FAILED(hr))
 {
 MessageBox(NULL,"Acquire() failed!","InitKeyboard()",MB_OK);
 return false;
 }

return true;
}//InitKeyboard

bool Input::InitMouse(HWND hWnd)
{
//device capabilities
DIDEVCAPS MouseCapabilities; 
	
	HRESULT hr;

	hr = m_pDIObject->CreateDevice(GUID_SysMouse,&m_pDIMouseDevice,NULL);
if(FAILED(hr))
 {
 MessageBox(NULL,"CreateDevice() failed!","InitMouse()",MB_OK);
 return false;
 }

	hr = m_pDIMouseDevice->SetDataFormat(&c_dfDIMouse2);
if(FAILED(hr))
 {
 MessageBox(NULL,"SetDataFormat() failed!","InitMouse()",MB_OK);
 return false;
 }

	hr = m_pDIMouseDevice->SetCooperativeLevel(NULL,DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
if(FAILED(hr))
 {
 MessageBox(NULL,"SetCooperativeLevel() failed!","InitMouse()",MB_OK);
 return false;
 }

	hr = m_pDIMouseDevice->Acquire();
if(FAILED(hr))
 {
 MessageBox(NULL,"Acquire() failed!","InitMouse()",MB_OK);
 return false;
 }

MouseCapabilities.dwSize = sizeof(MouseCapabilities);
m_pDIMouseDevice->GetCapabilities(&MouseCapabilities);

if(!(MouseCapabilities.dwFlags & DIDC_ATTACHED))
 {
 MessageBox(NULL,"Mouse is currently not attached!","InitMouse()",MB_OK);
 return false;
 }

m_dwAxes = MouseCapabilities.dwAxes;
m_dwButtons = MouseCapabilities.dwButtons;

//SetCursor("arrow.bmp",0,0,0xffffffff);
//SetAttributes(false,1.0f);

return true;
}//InitMouse
Input::~Input(void)
{

}//~Input

void Input::Update(void)
{
	HRESULT hr;
	hr = m_pDIKeyboardDevice->GetDeviceState(sizeof(KeyBuffer),(LPVOID)&KeyBuffer);
if(FAILED(hr))
 {
 MessageBox(NULL,"GetDeviceState() failed!","Update()",MB_OK);

 }

if(DIERR_INPUTLOST == m_pDIMouseDevice->GetDeviceState(sizeof(m_MouseState),(LPVOID)&m_MouseState))
{
 m_pDIMouseDevice->Acquire();
}


}//Update
void Input::Startup(HWND hWnd)
{
	m_pDIObject = NULL;
	m_pDIKeyboardDevice = NULL;
	m_pDIMouseDevice = NULL;
	
	//Clears the buffer before use
	ZeroMemory(&KeyBuffer, 256);

	bool result = false;
	
	result = InitDirectInput();

	if(!result)
	{
		MessageBox (NULL, "InitDirectInput Failed", "ERROR", MB_OK);
	}
	
	result = false;
	result = InitKeyboard(hWnd);
	if(!result)
	{
		MessageBox (NULL, "InitKeyboard Failed", "ERROR", MB_OK);
	}

	result = false;
	result = InitMouse(hWnd);
	if(!result)
	{
		MessageBox (NULL, "InitMouse Failed", "Error", MB_OK);
	}
}
void Input::ShutDown()
{
	
	if(m_pDIKeyboardDevice != NULL)
 {
 m_pDIKeyboardDevice->Unacquire();
 m_pDIKeyboardDevice->Release();
 m_pDIKeyboardDevice = NULL;
 }

if(m_pDIObject != NULL)
 {
 m_pDIObject->Release();
 m_pDIObject = NULL;

 if(m_pDIMouseDevice != NULL)
 {
 m_pDIMouseDevice->Unacquire();
 m_pDIMouseDevice->Release();
 m_pDIMouseDevice = NULL;
 }
 }
}

#pragma region KeyInput

bool Input::WPressed()
{
	if (KEYDOWN(KeyBuffer, DIK_W))
	{
		KeyWasDown[0] = true;
		return false;
	}

	if (!KEYDOWN(KeyBuffer, DIK_W) && KeyWasDown[0])
	{
		KeyWasDown[0] = false;
		return true;
	}

	return false;
} 

bool Input::APressed()
{
	if (KEYDOWN(KeyBuffer, DIK_A))
	{
		KeyWasDown[1] = true;
		return false;
	}

	if (!KEYDOWN(KeyBuffer, DIK_A) && KeyWasDown[1])
	{
		KeyWasDown[1] = false;
		return true;
	}

	return false;
}

bool Input::SPressed()
{
	if (KEYDOWN(KeyBuffer, DIK_S))
	{
		KeyWasDown[2] = true;
		return false;
	}

	if (!KEYDOWN(KeyBuffer, DIK_S) && KeyWasDown[2])
	{
		KeyWasDown[2] = false;
		return true;
	}

	return false;
}

bool Input::DPressed()
{
	if (KEYDOWN(KeyBuffer, DIK_D))
	{
		KeyWasDown[3] = true;
		return false;
	}

	if (!KEYDOWN(KeyBuffer, DIK_D) && KeyWasDown[3])
	{
		KeyWasDown[3] = false;
		return true;
	}

	return false;
}

bool Input::SpaceBar()
{
	if (KEYDOWN(KeyBuffer, DIK_SPACE))
	{
		KeyWasDown[4] = true;
		return false;
	}

	if (!KEYDOWN(KeyBuffer, DIK_SPACE) && KeyWasDown[4])
	{
		KeyWasDown[4] = false;
		return true;
	}

	return false;
}
#pragma endregion KeyInput

/*
#pragma region KeyHeldDown

							**********************************************************************************
							**************			KEY HELD DOWN HAS BEEN DEPRECATED			**************
							**********************************************************************************
bool Input::WHeld()
{
	if (KEYDOWN(KeyBuffer, DIK_W))
	{
		return true; 
	}
	return false;
}

bool Input::AHeld()
{
	if (KEYDOWN(KeyBuffer, DIK_A))
	{
		return true;		
	}
	return false;
}

bool Input::SHeld()
{
	if (KEYDOWN(KeyBuffer, DIK_S))
	{
		return true;
	}
	return false;
}

bool Input::DHeld()
{
	if (KEYDOWN(KeyBuffer, DIK_D))
	{
		return true;
	}
	return false;
}

bool Input::SpaceBarHeld()
{
	if (KEYDOWN(KeyBuffer, DIK_SPACE))
	{
		return true;
	}
	return false;
}
#pragma endregion KeyHeldDown
*/
#pragma region MouseInput

bool Input::LBUTTONPressed()
{
	//Check the mouse left button is pressed or not
	if (BUTTONDOWN(m_MouseState, 0))
	{
		ButtonWasDown[0] = true;
		return false;
	}
	
	if (!BUTTONDOWN(m_MouseState,0) && ButtonWasDown[0])
	{
		ButtonWasDown[0] = false;
		return true;
	}

	return false;
}

bool Input::RBUTTONPressed()
{
   //Check the mouse right button is pressed or not
	if (BUTTONDOWN(m_MouseState, 1))
	{
		ButtonWasDown[1] = true;
		return false;
	}
	
	if (!BUTTONDOWN(m_MouseState,1) && ButtonWasDown[1])
	{
		ButtonWasDown[1] = false;
		return true;
	}

	return false;
}

/*

							**********************************************************************************
							**************			MOUSE HELD DOWN HAS BEEN DEPRECATED			**************
							**********************************************************************************

bool Input::LBUTTONHeld()

{
	if (KEYDOWN(KeyBuffer, VK_LBUTTON))
	{
		return true;
	}
	return false;
}

bool Input::RBUTTONHeld()

{
	if (KEYDOWN(KeyBuffer, VK_RBUTTON))
	{
		return true;
	}
	return false;
}
*/


#pragma endregion MouseInput



