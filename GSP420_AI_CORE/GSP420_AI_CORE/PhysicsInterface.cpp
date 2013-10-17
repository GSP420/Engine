#pragma once
#include "PhysicsInterface.h"


PhysicsInterface::PhysicsInterface(){
}

PhysicsInterface::~PhysicsInterface(){
}

void PhysicsInterface::Startup(float SceneSize)
{
	core.velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	core.acceleration = D3DXVECTOR3(0.0f, float(core.GRAVITY), 0.0f);
	timeUntilUpdate = 0.0f;

	collide._octree = new Octree(D3DXVECTOR3(-SceneSize / 2, -SceneSize / 2, SceneSize / 2),
						D3DXVECTOR3(SceneSize / 2, SceneSize / 2, SceneSize / 2),
						1.0f);
}

void PhysicsInterface::Update(float dt)
{
	float TOI;
	core.Accelerate(dt);
	collide._octree->advance(core.boxes, collide._octree, dt, timeUntilUpdate);

	//Loop through the boxes for broad phase
	for(int i = 0; i < core.boxes.size(); i++)
	{
		//Broad phase collision detection
		if(collide.CollisionDetection(core.boxes, collide._octree, true))
		{
			//this box collided with another box
		}
		else
		{
			//this box didnt collide with anything
		}
	}

	//Loop through the boxes a second time for narrow phase
	for(int i = 0; i < core.boxes.size(); i++)
	{
		//Narrow phase collision detection
		if(core.boxes[i]->useContinuousDetection)
		{
			//box has continuous detection toggled on, so determine if we've already found a collision for it in broad phase
			if(collide.sweptCCD(core.boxes, collide._octree, TOI))
			{
				//this box collided with another box
			}
			else
			{
				//this box didnt collide with anything
			}
		}
	}

	//After calling update, core._collisions.collisionList will contain information about all the collisions that occurred and can be used
	//by the designer to resolve the collisions.
}

void PhysicsInterface::Shutdown()
{
	for(unsigned int i = 0; i < core.boxes.size(); i++)
		delete core.boxes[i];

	 delete collide._octree;
}

bool PhysicsInterface::RayCast3D(D3DXVECTOR3 startPoint, D3DXVECTOR3 directionVector, list<AABB> collidables, int maxTestLimit, RayCastContact &contactOutput)
{
	return core.RayCast(startPoint, directionVector, collidables, maxTestLimit, contactOutput);
}

bool PhysicsInterface::RayCast2D(D3DXVECTOR2 startPoint, D3DXVECTOR2 directionVector, list<AABB> collidables, int maxTestLimit, RayCastContact &contactOutput)
{
	return core.RayCast(startPoint, directionVector, collidables, maxTestLimit, contactOutput);
}

void PhysicsInterface::setAccel(D3DXVECTOR3 acceleration)
{
	core.SetAcceleration(acceleration);
}


D3DXVECTOR3 PhysicsInterface::getAccel()
{
	return core.GetAcceleration();
}


void PhysicsInterface::setVel(D3DXVECTOR3 velocity)
{
	core.SetVelocity(velocity);
}


D3DXVECTOR3 PhysicsInterface::getVel()
{
	return core.velocity;
}


void PhysicsInterface::setAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint)
{
	core.SetAABB(minPoint, maxPoint);	
}


void PhysicsInterface::setAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint, bool useCCD)
{
	core.SetAABB(minPoint, maxPoint, useCCD);	
}


void PhysicsInterface::setAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint, string ID)
{
	core.SetAABB(minPoint, maxPoint, ID);	
}


void PhysicsInterface::setAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint, string ID, bool useCCD)
{
	core.SetAABB(minPoint, maxPoint, useCCD, ID);	
}