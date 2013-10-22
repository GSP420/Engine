/****************************************************************************************
Example Pseudo Code
Main()
{
	PhysicsInterface physics;
	
	Startup()
	{
		physics.Startup();
	}

	Update()
	{
		physics.Update();
		{
			for(int i=0;i<physics.core._collisions->collisionList.size();i++)
			{
				//Pop the next collision off the stack
				physics.core._collisions->getNext();

				//Resolve collisions by accessing the following properties
				physics.core._collisions->currentCollision.boxA_ID;
				physics.core._collisions->currentCollision.boxB_ID;
				physics.core._collisions->currentCollision.boxA_movementVector;
				physics.core._collisions->currentCollision.boxB_movementVector;
				physics.core._collisions->currentCollision.impactPoint.x;
				physics.core._collisions->currentCollision.impactPoint.y;
				physics.core._collisions->currentCollision.impactPoint.z;
				physics.core._collisions->currentCollision.timeOfImpact;
			}
		}

		//Raycast example
		physics.RayCast3D(entity.position, entity.movementVector, physics.core.boxes, 15, 				physics.core._rayCastContact);

		//Returns true if a collision is detected along the ray
		//Assigns information about the collision to physics.core._rayCastContact struct
	}

	Shutdown()
	{
		physics.Shutdown();
	}
}
*******************************************************************************************/
#pragma once
#include "PhysicsCore.h"
#include "PhysicsCollision.h"
#include "PhysicsUtils.h"


struct PhysicsFloats
{
	float SCENE_SIZE;
};

class PhysicsInterface
{
public:

	void Startup(float SceneSize);
	void Update(float dt);
	void Shutdown();

	PhysicsInterface();
	~PhysicsInterface();

	bool RayCast3D(D3DXVECTOR3 startPoint, D3DXVECTOR3 directionVector, list<AABB> collidables, int maxTestLimit, RayCastContact &contactOutput);
	bool RayCast2D(D3DXVECTOR2 startPoint, D3DXVECTOR2 directionVector, list<AABB> collidables, int maxTestLimit, RayCastContact &contactOutput);
	void setAccel(D3DXVECTOR3 acceleration, string ID);
	void setAABB(D3DXVECTOR3 min, D3DXVECTOR3 max);
	void setAABB(D3DXVECTOR3 min, D3DXVECTOR3 max, bool useContinuousCollisionDetection);
	void setAABB(D3DXVECTOR3 min, D3DXVECTOR3 max, string ID);
	void setAABB(D3DXVECTOR3 minPoint, D3DXVECTOR3 maxPoint, bool useCCD, string ID);
	D3DXVECTOR3 getAccel(string ID);
	void setVel(D3DXVECTOR3 Vel, string ID);
	D3DXVECTOR3 getVel(string ID);

private:
	PhysicsCore Core;
	PhysicsCollision collide;
	float timeUntilUpdate;
};