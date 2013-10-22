#pragma once
#include "PhysicsCore.h"
#include "PhysicsUtils.h"

class PhysicsCollision
{
public:
	PhysicsCollision(void);
	~PhysicsCollision(void);

	D3DXVECTOR3 ObjectDistance(D3DXVECTOR3, D3DXVECTOR3);
	
	bool PhysicsCollision::sweptCCD(int boxIndex, vector<AABB*> boxes, Octree* octree, float &timeOfImpact);
	bool CollisionDetection(vector<AABB*> &boxes, Octree* octree, bool test_z_axis);
};



