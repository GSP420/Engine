#include "UI.h"

UI::UI(void)
{


}

UI::~UI(void)
{
}

void UI::update(int i)
{
	if(i > 0 && i < 11)
	{
	switch (i)
	{
	case 1:
		element[0].isActive = false;
		element[1].isActive = false;
		element[2].isActive = false;
		element[3].isActive = false;
		element[4].isActive = false;
		element[5].isActive = false;
		element[6].isActive = false;
		element[7].isActive = false;
		element[8].isActive = false;
		element[9].isActive = false;
		break;
	case 2:
		element[0].isActive = false;
		element[1].isActive = false;
		element[2].isActive = false;
		element[3].isActive = false;
		element[4].isActive = false;
		element[5].isActive = false;
		element[6].isActive = false;
		element[7].isActive = false;
		element[8].isActive = false;
		element[9].isActive = false;
		break;
	case 3:
		element[0].isActive = false;
		element[1].isActive = false;
		element[2].isActive = false;
		element[3].isActive = false;
		element[4].isActive = false;
		element[5].isActive = false;
		element[6].isActive = false;
		element[7].isActive = false;
		element[8].isActive = false;
		element[9].isActive = false;
		break;
	case 4:
		element[0].isActive = false;
		element[1].isActive = false;
		element[2].isActive = false;
		element[3].isActive = false;
		element[4].isActive = false;
		element[5].isActive = false;
		element[6].isActive = false;
		element[7].isActive = false;
		element[8].isActive = false;
		element[9].isActive = false;
		break;
	case 5:
		element[0].isActive = false;
		element[1].isActive = false;
		element[2].isActive = false;
		element[3].isActive = false;
		element[4].isActive = false;
		element[5].isActive = false;
		element[6].isActive = false;
		element[7].isActive = false;
		element[8].isActive = false;
		element[9].isActive = false;
		break;
	case 6:
		element[0].isActive = false;
		element[1].isActive = false;
		element[2].isActive = false;
		element[3].isActive = false;
		element[4].isActive = false;
		element[5].isActive = false;
		element[6].isActive = false;
		element[7].isActive = false;
		element[8].isActive = false;
		element[9].isActive = false;
		break;
	case 7:
		element[0].isActive = false;
		element[1].isActive = false;
		element[2].isActive = false;
		element[3].isActive = false;
		element[4].isActive = false;
		element[5].isActive = false;
		element[6].isActive = false;
		element[7].isActive = false;
		element[8].isActive = false;
		element[9].isActive = false;
		break;
	case 8:
		element[0].isActive = false;
		element[1].isActive = false;
		element[2].isActive = false;
		element[3].isActive = false;
		element[4].isActive = false;
		element[5].isActive = false;
		element[6].isActive = false;
		element[7].isActive = false;
		element[8].isActive = false;
		element[9].isActive = false;
		break;
	case 9:
		element[0].isActive = false;
		element[1].isActive = false;
		element[2].isActive = false;
		element[3].isActive = false;
		element[4].isActive = false;
		element[5].isActive = false;
		element[6].isActive = false;
		element[7].isActive = false;
		element[8].isActive = false;
		element[9].isActive = false;
		break;
	case 10:
		element[0].isActive = false;
		element[1].isActive = false;
		element[2].isActive = false;
		element[3].isActive = false;
		element[4].isActive = false;
		element[5].isActive = false;
		element[6].isActive = false;
		element[7].isActive = false;
		element[8].isActive = false;
		element[9].isActive = false;
		break;
	}
	}
}

void UI::draw()
{
	if(element[0].isActive);
	
	if(element[1].isActive);

	if(element[2].isActive);
	
	if(element[3].isActive);
	
	if(element[4].isActive);

	if(element[5].isActive);
	
	if(element[6].isActive);
	
	if(element[7].isActive);

	if(element[8].isActive);

	if(element[9].isActive);
}




// 2D overloaded functions
//***********************************************************************************

void UI::changeElement(int elementNumber, int dwidth, int dheight, int dimageScale)
{
	element[elementNumber].height = dheight;
	element[elementNumber].width = dwidth;
	element[elementNumber].imageScale = dimageScale;
}

void UI::changeElement(int elementNumber, std::string textureLocation)
{
	element[elementNumber].s2DLocation = textureLocation;
	
}

void UI::changeElement( int elementNumber, float s2dx, float s2dy)
{
 element[elementNumber].position.x = s2dx;
 element[elementNumber].position.y = s2dy;
}

// VECTOR3 function
void UI::changeElement(int elementNumber, std::string TDLocation, float xpos, float ypos, float zpos, float xrot, 
						float yrot, float zrot, float xscal, float yscal, float zscal)
{
	element[elementNumber].s3dLocation = TDLocation;

	element[elementNumber].position.x = xpos;
	element[elementNumber].position.y = ypos;
	element[elementNumber].position.z = zpos;

	element[elementNumber].rotation.x = xrot;
	element[elementNumber].rotation.y = yrot;
	element[elementNumber].rotation.z = zrot;
	
	element[elementNumber].scale.x = xscal;
	element[elementNumber].scale.y = yscal;
	element[elementNumber].scale.z = zscal;
}

// Text overload function
//*****************************************************************************************
void UI::changeElement(int elementNumber, std::string wordLocation, char itext)
{
	element[elementNumber].textLocation = wordLocation;
	element[elementNumber].text = itext;
}

void UI::changeElement(int elementNumber, std::string fLocation, int fontSize, float r, float g, float b)
{
	element[elementNumber].fontLocation = fLocation;
	element[elementNumber].size = fontSize;
	element[elementNumber].color.x = r;
	element[elementNumber].color.y = g;
	element[elementNumber].color.z = b;
}