/************************************************************
*File: PhysicsCore.h
*Programmer: GSP 420 Group G: Physics
*Purpose: contains data that will be the foundation for the 
*rest of the Physics core for the game engine
*Date:9/17/13
************************************************************/

#pragma once

#include "PhysicsUtils.h"
#include "Octree.h"

using namespace std;




class PhysicsCore
{
public:
	static const float GRAVITY;
	static const float FRICTION;	//friction coefficient that may need changed after testing	

	vector<AABB*> boxes;
	vector<D3DXVECTOR3> velocities;
	vector<D3DXVECTOR3> accelerations;
	//D3DXVECTOR3 velocity;
	//D3DXVECTOR3 acceleration;
	D3DXVECTOR3 cur_Acceleration;
	D3DXVECTOR3 cur_Velocity;
	D3DXVECTOR3 new_Velocity;
	collisionInfo* _collisionInfo;
	collisions* _collisions;
	RayCastContact* _rayCastContact;

	PhysicsCore(void);
	~PhysicsCore(void);

	void Accelerate(float delta_Time);
	bool RayCast(D3DXVECTOR3 startPoint, D3DXVECTOR3 directionVector, list<AABB> collidables, int maxTestLimit, RayCastContact &contactOutput);
	bool RayCast(D3DXVECTOR2 startPoint, D3DXVECTOR2 directionVector, list<AABB> collidables, int maxTestLimit, RayCastContact &contactOutput);
	void CollisionMaskLayers();
	D3DXVECTOR3 GetVelocity(string ID);
	void SetVelocity(D3DXVECTOR3 Vel, string ID);
	D3DXVECTOR3 GetAcceleration(string ID);
	void SetAcceleration(D3DXVECTOR3 accel, string ID);
	void SetAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint);
	void SetAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint, bool useCCD);
	void SetAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint, string ID);
	void SetAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint, bool useCCD, string ID);
};

extern Octree* _octree;
extern PhysicsCore* core;
	

