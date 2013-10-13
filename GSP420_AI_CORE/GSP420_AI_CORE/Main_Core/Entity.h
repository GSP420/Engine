// Entity.h

#pragma once
// #include "*header*.h"   include header for rendering class
#include <string>
#include"AI_Core/Agent.h"

class Entity
{
public:
	//pass animation through
	//*header* *animation*;	
	float position[3];
	int eID;					//animation ID
	Agent agentData;

	std::string type;
	std::string name;

	Entity *entNext;
	Entity *entPrev;

	Entity *typeNext;
	Entity *typePrev;

	Entity(void);
	~Entity(void);

	void Added();
	void Update();
	void Render();
	void Removed();

	//Getters
	//const RECT GetRect()const { return renderedItem.GetRect(); }
	const int GetID()const { return eID; }

	//Setters
	void SetID(int iD) { eID = iD; }
	void SetEntity(std::string name, std::string type);
};