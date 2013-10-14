#pragma once

#include <direct.h>
#include <d3dx9tex.h>
#include <Windows.h>
#include <string>
#include "UIElement.h"

using namespace std;

class UIElement
{

public:
	
	UIElement(void);
	~UIElement(void);

	// To manipulate the 2D variables
	void twoDimMeasure(int,int,int);
	bool isActive;
	void switchActive();

	// Handling of 3D variables
	void ModelMeasure(float);

	// Handling of font creation
	bool init(DWORD size, LPDIRECT3DDEVICE9 device);

public:
	// handling of the 2D data
	IDirect3DSurface9* surface; // Need a surface to draw 2D

	// SrcRect is what 2d requires 
	RECT srcRect; //source location in the loaded surface
	RECT destRect;//destination location on the screen
	int width;
	int height;
	int imageScale;
	std::string s2DLocation;
	
	// handling of the 3D mesh data
	LPD3DXMESH mesh; // the model mesh
	DWORD materialCount; // number of materials returned when loading

	LPDIRECT3DTEXTURE9* textures; 
	D3DMATERIAL9* materials; 
	LPD3DXBUFFER materialBuffer;  

	// Kept here just in case there is a need for them
	D3DXMATRIX transMatrix;		// the translation matrix
	D3DXMATRIX rotationMatrix;	// the rotation matrix
	D3DXMATRIX scaleMatrix;		// the scale matrix

	// Kept here just in case there is a need for them
	float dscale;				
	D3DXVECTOR3 scale;			//the models scale
	D3DXVECTOR3 position;		//the models position
	D3DXVECTOR3 rotation;		//the models rotation
	std::string s3dLocation;
	
	// handling of the text data
	D3DXVECTOR3 color;
	DWORD size;
	char text;
	std::string fontLocation;
	std::string textLocation;
};

