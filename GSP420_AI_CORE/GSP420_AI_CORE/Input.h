#define DIRECTINPUT_VERSION 0x0800
//constants for mouse buttons (NEW)
#define DIMOUSE_LEFTBUTTON   0
#define DIMOUSE_RIGHTBUTTON  1
#define DIMOUSE_MIDDLEBUTTON 2
#define DIMOUSE_4BUTTON      3
#define DIMOUSE_5BUTTON      4
#define DIMOUSE_6BUTTON      5
#define DIMOUSE_7BUTTON      6
#define DIMOUSE_8BUTTON      7
//vertex format for cursor (NEW)
#define D3DFVF_CURSORVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

#include <dinput.h>
#include<d3d9.h>
#pragma comment(lib, "dinput8.lib")

class Input
{
public:
							Input(void);
							~Input(void);


						//updates device status
	void					Update(void);
	void					Startup(HWND hWnd);
	void					ShutDown();


							//initializations
	bool					InitDirectInput(void);
	bool					InitKeyboard(HWND hWnd);
	bool					InitMouse(HWND hWnd);



							//Keystroke Checks
	bool					WPressed();
	bool					APressed();
	bool					SPressed();
	bool					DPressed();
	bool					SpaceBar();
	bool					EscPressed();
	bool					LBUTTONPressed();
	bool					RBUTTONPressed();
	bool					OnePressed();
	bool					TwoPressed();
	bool					ThreePressed();

							//Keyhold Checks

/*

							**********************************************************************************
							**************			HOLD CHECKS HAVE BEEN DEPRECATED			**************
							**********************************************************************************

	bool					WHeld();
	bool					AHeld();
	bool					SHeld();
	bool					DHeld();
	bool					SpaceBarHeld();
	bool					LBUTTONHeld();
	bool					RBUTTONHeld();
*/


						//draws mouse cursor
    void                 DrawCursor(void);
						//set new cursor
    void                 SetCursor(const char*,int,int,DWORD);
						//set cursor attributes
    void                 SetAttributes(bool,float);
						//set new cursor position
    void                 SetCursorPosition(float,float);
						//get relative movement
    float                GetRelativeX(void);
    float                GetRelativeY(void);
						//get wheel movement 
    float                GetRelativeZ(void);
						//get cursor position
    float                GetAbsoluteX(void);
    float                GetAbsoluteY(void);
						//check for mouse button
    bool                 MouseButtonDown(int);

private:

	LPDIRECTINPUT8			m_pDIObject;
	LPDIRECTINPUTDEVICE8	m_pDIKeyboardDevice;
	LPDIRECTINPUTDEVICE8	m_pDIMouseDevice;

	char					KeyBuffer[256];
	bool					KeyWasDown[10];
	bool					ButtonWasDown[2];
	
	//cursor texture
	LPDIRECT3DTEXTURE9   m_pCursorTexture;      
    //mouse state structure
    DIMOUSESTATE2        m_MouseState;
    bool                 m_bInverted;           //inverted y axis
    float                m_fSensitivity,        //mouse sensitivity
                         m_fCursorX,            //cursor position
                         m_fCursorY;
    int                  m_iHotSpotX,           //cursor hot spot
                         m_iHotSpotY;
    DWORD                m_dwAxes,              //number of axes
                         m_dwButtons,           //number of buttons
                         m_dwCursorColor,       //cursor color
                         m_dwScreenWidth,       //screen width
                         m_dwScreenHeight;      //screen height
};

struct D3DCURSORVERTEX
{
float fX,
      fY,
      fZ,
      fRHW;
DWORD dwColor;
float fU,
      fV;
};