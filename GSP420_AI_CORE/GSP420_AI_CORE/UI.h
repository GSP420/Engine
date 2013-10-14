
#include <direct.h>
#include <d3dx9tex.h>
#include <Windows.h>
#include <string>
#include "UIElement.h"
#include <D3dx9math.h>
#include"ICore.h"

using namespace std;

class UI  : public ICore
{
public:
	UI(void);
	~UI(void);

	int maxElements;
	void switchActive();
	void update(int i);
	void draw();
	operator FLOAT* ();

	// 2d overload functions
	void changeElement(int element, std::string textureLocation);
	void changeElement(int element, int dwidth, int dheight, int dimageScale);
	void changeElement(int element, float s2dx, float s2dy);
	
	// 3d overload function
	void changeElement(int element, std::string s3dLocation, float xpos, float ypos, float zpos, float xrot, 
						float yrot, float zrot, float xscal, float yscal, float zscal);

	// text overload function
	void changeElement(int element, std::string textLocation, char text);
	void changeElement(int element, std::string fLocation, int size, float r, float g, float b); 
	int integer;
private:
	
	UIElement element[10]; 
};








