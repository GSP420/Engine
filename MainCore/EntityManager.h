#pragma once
#include <map>
#include <stack>
#include "Entity.h"

class EntityManager
{
private:
	// holds the most recently added entity
	Entity *entFirst;
	// holds entities to be added next frame
	std::stack<Entity*> toAdd;
	// holds entities to be removed next frame
	std::stack<Entity*> toRemove;
	// holds entities recently added type
	std::map <std::string, Entity*> typeFirst;
	// holds individual entity instances
	std::map <std::string, Entity*> instances;
	
	int entCount;

	// adds entity to update list
	void AddUpdate(Entity *e);
	// removes entity from update list
	void RemoveUpdate(Entity *e);
	// adds type to list
	void AddType(Entity *e);
	// removes type from list
	void RemoveType(Entity *e);
	// adds instance
	void AddInstance(Entity *e);
	// removes instance
	void RemoveInstance(Entity *e);

public:
	EntityManager(void);
	~EntityManager(void);

	// updates all of the entities
	void Update(void);
	// renders all of the entities
	void Render(void);

	// adds an entity at the end of the frame
	Entity* Add(Entity *e);
	// removes an entity at the end of the frame
	Entity* Remove(Entity *e);
	// gets all entities of the specified type
	std::stack<Entity*> GetTypes(std::string type);
	// gets the entity with the instance name
	Entity* GetInstance(std::string name);
	// get entity count
	int Count(void) { return this->entCount; }
};

