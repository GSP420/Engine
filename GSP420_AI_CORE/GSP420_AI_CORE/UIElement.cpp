#include "UIElement.h"


UIElement::UIElement(void)
{
	mesh = NULL; // For 3D
	surface = NULL; // For 2D
	isActive = false;
}


UIElement::~UIElement(void)
{
	
	// Delete the model
	if (mesh){
		mesh->Release();
	}
	
	// Delete the material buffer
	if (materialBuffer)
		materialBuffer->Release();

	// Delete the materials
	if (materials){
		delete[] materials;
	}

	// Delete the textures
	if (textures){
		delete[] textures;
	}

	// Deals with the 2D surface
	if( surface != NULL) 
	{
        surface->Release();
		surface = NULL;
	}
}

// This program is used to access the variables within the storeData class
void UIElement::twoDimMeasure(int Height, int Width, int ImageScale)
{
	height = Height;
	width = Width;
	imageScale = ImageScale;
}

// utilized for the variables related to 3D 
void UIElement::ModelMeasure(float fScale)
{
	// d for holding data
	dscale = fScale;
}

/*// Responsible for the font of the text
bool UIElement::init(DWORD size, LPDIRECT3DDEVICE9 device)
{	

	// Create a font
	D3DXCreateFont(device,     //D3D Device
                    size,               //Font height
                    0,                //Font width
                    FW_NORMAL,        //Font Weight
                    1,                //MipLevels
                    false,            //Italic
                    DEFAULT_CHARSET,  //CharSet
                    OUT_DEFAULT_PRECIS, //OutputPrecision
                    ANTIALIASED_QUALITY, //Quality
                    DEFAULT_PITCH|FF_DONTCARE,//PitchAndFamily
                    "Arial",          //pFacename,
                    &g_font);         //ppFont

	return true;
}
*/

void UIElement::switchActive()
{
	if(isActive)
	{
		isActive = false;
	}
	else if(!isActive)
	{
		isActive = true;
	}
}