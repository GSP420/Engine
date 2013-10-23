#pragma once
#include "PhysicsInterface.h"



PhysicsInterface::PhysicsInterface(){
}

PhysicsInterface::~PhysicsInterface(){
}

void PhysicsInterface::Startup(float SceneSize)
{
	core = &Core;
	//core->velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//core->acceleration = D3DXVECTOR3(0.0f, core->GRAVITY, 0.0f);
	timeUntilUpdate = 0.0f;

	_octree = new Octree(D3DXVECTOR3(-SceneSize / 2, -SceneSize / 2, SceneSize / 2),
						D3DXVECTOR3(SceneSize / 2, SceneSize / 2, SceneSize / 2),
						1);
}

void PhysicsInterface::Update(float dt)
{
	float TOI;
	core->Accelerate(dt);
	_octree->advance(core->boxes, _octree, dt, timeUntilUpdate);

	//Loop through the boxes to change position and check collision
	for(unsigned int i = 0; i < core->boxes.size(); i++)
	{
		core->boxes[i]->minPoint += core->boxes[i]->velocity;
		core->boxes[i]->maxPoint += core->boxes[i]->velocity;

		//Narrow phase collision detection
		if(core->boxes[i]->useContinuousDetection)
		{
			//box has continuous detection toggled on, so determine if we've already found a collision for it in broad phase
			collide.sweptCCD(i, core->boxes, _octree, TOI);
		}
		else
		{
			collide.CollisionDetection(core->boxes, _octree, false);
		}
	}

	//After calling update, core._collisions.collisionList will contain information about all the collisions that occurred and can be used
	//by the designer to resolve the collisions.
}

void PhysicsInterface::Shutdown()
{
	for(unsigned int i = 0; i < core->boxes.size(); i++)
		delete core->boxes[i];

	 delete _octree;
}

bool PhysicsInterface::RayCast3D(D3DXVECTOR3 startPoint, D3DXVECTOR3 directionVector, list<AABB> collidables, int maxTestLimit, RayCastContact &contactOutput)
{
	return core->RayCast(startPoint, directionVector, collidables, maxTestLimit, contactOutput);
}

bool PhysicsInterface::RayCast2D(D3DXVECTOR2 startPoint, D3DXVECTOR2 directionVector, list<AABB> collidables, int maxTestLimit, RayCastContact &contactOutput)
{
	return core->RayCast(startPoint, directionVector, collidables, maxTestLimit, contactOutput);
}

void PhysicsInterface::setAccel(D3DXVECTOR3 acceleration, string ID)
{
	core->SetAcceleration(acceleration, ID);
}


D3DXVECTOR3 PhysicsInterface::getAccel(string ID)
{
	return core->GetAcceleration(ID);
}


void PhysicsInterface::setVel(D3DXVECTOR3 Vel, string ID)
{
	core->SetVelocity(Vel, ID);
}


D3DXVECTOR3 PhysicsInterface::getVel(string ID)
{
	return core->GetVelocity(ID);
}


void PhysicsInterface::setAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint)
{
	core->SetAABB(minPoint, maxPoint);	
}


void PhysicsInterface::setAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint, bool useCCD)
{
	core->SetAABB(minPoint, maxPoint, useCCD);	
}


void PhysicsInterface::setAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint, string ID)
{
	core->SetAABB(minPoint, maxPoint, ID);	
}


void PhysicsInterface::setAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint, bool useCCD, string ID)
{	
	core->SetAABB(minPoint, maxPoint, useCCD, ID);	
}