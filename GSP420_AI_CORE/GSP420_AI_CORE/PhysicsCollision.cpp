#include "PhysicsCollision.h"


PhysicsCollision::PhysicsCollision(void)
{
}


PhysicsCollision::~PhysicsCollision(void)
{
}


D3DXVECTOR3 PhysicsCollision::ObjectDistance(D3DXVECTOR3 Obj1, D3DXVECTOR3 Obj2)
{
	/******************************************************
	*	Function Name:		ObjectDistance()
	*	Programmer:			Nathanael Blanchard
	*
	*	Finds distance between two objects
	******************************************************/
	D3DXVECTOR3 dist;
	dist = Obj2 - Obj1;
	return(dist);
}

bool PhysicsCollision::sweptCCD(int boxIndex, vector<AABB*> boxes, Octree* octree, float &timeOfImpact)
{
	/******************************************************
	*	Function Name:		sweptCCD()
	*	Programmer:			Josh Archer
	*
	*	Determines if there was a collision at any point
	*	between the previous position and current position
	*	of two AABB's.
	*	
	*	Also assigns a normalized time of impact value
	*	to pass-by-reference parameter "timeOfImpact"
	*
	******************************************************/

	vector<AABBPair> bps;
	bool collisionOccurred = false;

	

	_octree->potentialBoxBoxCollision(bps, boxes, octree);
	for(unsigned int i = 0; i < boxes.size(); i++) 
	{
		AABBPair bp = bps[i];
		AABB* boxA = bp.aabb1;
		AABB* boxB = bp.aabb2;
		if(i == boxIndex)
		{
			//skip this check
		}
		else
		{
			
			//Check if box A and box B were already overlapping in their previous positions:
			D3DXVECTOR3 AB_separation = boxA->centerPointPrevious - boxB->centerPointPrevious;

			if(		(fabs(AB_separation.x) <= fabs(boxA->extent().x + boxB->extent().x))
				&&	(fabs(AB_separation.y) <= fabs(boxA->extent().y + boxB->extent().y))
				&&	(fabs(AB_separation.z) <= fabs(boxA->extent().z + boxB->extent().z))		)
			{
				//The boxes were already overlapping at their previous positions
			
				collisionOccurred = true;
				core->_collisions->currentCollision.boxA_ID					=	boxA->ID;
				core->_collisions->currentCollision.boxB_ID					=	boxB->ID;
				core->_collisions->currentCollision.impactPoint.x			=	-FLT_MAX;
				core->_collisions->currentCollision.impactPoint.y			=	-FLT_MAX;
				core->_collisions->currentCollision.impactPoint.z			=	-FLT_MAX;
				core->_collisions->currentCollision.timeOfImpact				=	0.0f;
				core->_collisions->currentCollision.boxA_movementVector		=	boxA->center() - boxA->centerPointPrevious;
				core->_collisions->currentCollision.boxB_movementVector		=	boxB->center() - boxB->centerPointPrevious;
			
				core->_collisions->addToList();

				timeOfImpact = 0.0f;
			}

			//We know they weren't overlapping at thier previous positions, so let's set up for detecting potential times of impact 
	
	
			D3DXVECTOR3 displacementA = boxA->center() - boxA->centerPointPrevious;		//Displacement of box A between previous and current positions
			D3DXVECTOR3 displacementB = boxB->center() - boxB->centerPointPrevious;		//Displacement of box B between previous and current positions

			D3DXVECTOR3 relativeVelocity = displacementB - displacementA;		//Relative velocity between box A and box B
	
			D3DXVECTOR3 aMin = boxA->centerPointPrevious - boxA->extent();		//Previous min point of box A
			D3DXVECTOR3 aMax = boxA->centerPointPrevious + boxA->extent();		//Previous max point of box A

			D3DXVECTOR3 bMin = boxB->centerPointPrevious - boxB->extent();		//Previous min point of box B
			D3DXVECTOR3 bMax = boxB->centerPointPrevious + boxB->extent();		//Previous max point of box B
	
			//First time of overlap along all axes
			D3DXVECTOR3 t0;
			t0.x, t0.y, t0.z = 0, 0, 0;
			//Last time of overlap along all axes
			D3DXVECTOR3 t1;
			t1.x, t1.y, t1.z = 1, 1, 1;

			for(int i = 0; i < 3; i++)
			{
				if(i == 0)
				{
					//Test x axis

					//Test for earliest time of impact:
					if(		(aMax.x < bMin.x)	&&	(relativeVelocity.x < 0)	)
					{
						t0.x = (aMax.x - bMin.x) / relativeVelocity.x;		//Potential time of impact, normalized
					}
					else if(		(bMax.x < aMin.x)	&&	(relativeVelocity.x > 0)	)
					{
						t0.x = (aMin.x - bMax.x) / relativeVelocity.x;		//Potential time of impact, normalized
					}

					//Test for last time of impact:
					if(		(bMax.x > aMin.x)	&&	(relativeVelocity.x < 0)	)
					{
						t1.x = (aMin.x - bMax.x) / relativeVelocity.x;		//Potential time of impact, normalized
					}
					else if(		(aMax.x > bMin.x)	&&	(relativeVelocity.x > 0)		)
					{
						t1.x = (aMax.x - bMin.x) / relativeVelocity.x;
					}
				}
				else if(i == 1)
				{
					//Test y axis

					//Test for earliest time of impact:
					if(		(aMax.y < bMin.y)	&&	(relativeVelocity.y < 0)	)
					{
						t0.y = (aMax.y - bMin.y) / relativeVelocity.y;		//Potential time of impact, normalized
					}
					else if(		(bMax.y < aMin.y)	&&	(relativeVelocity.y > 0)	)
					{
						t0.y = (aMin.y - bMax.y) / relativeVelocity.y;		//Potential time of impact, normalized
					}

					//Test for last time of impact:
					if(		(bMax.y > aMin.y)	&&	(relativeVelocity.y < 0)	)
					{
						t1.y = (aMin.y - bMax.y) / relativeVelocity.y;		//Potential time of impact, normalized
					}
					else if(		(aMax.y > bMin.y)	&&	(relativeVelocity.y > 0)		)
					{
						t1.y = (aMax.y - bMin.y) / relativeVelocity.y;
					}
				}
				else
				{
					//Test z axis

					//Test for earliest time of impact:
					if(		(aMax.z < bMin.z)	&&	(relativeVelocity.z < 0)	)
					{
						t0.z = (aMax.z - bMin.z) / relativeVelocity.z;		//Potential time of impact, normalized
					}
					else if(		(bMax.z < aMin.z)	&&	(relativeVelocity.z > 0)	)
					{
						t0.z = (aMin.z - bMax.z) / relativeVelocity.z;		//Potential time of impact, normalized
					}

					//Test for last time of impact:
					if(		(bMax.z > aMin.z)	&&	(relativeVelocity.z < 0)	)
					{
						t1.z = (aMin.z - bMax.z) / relativeVelocity.z;		//Potential time of impact, normalized
					}
					else if(		(aMax.z > bMin.z)	&&	(relativeVelocity.z > 0)		)
					{
						t1.z = (aMax.z - bMin.z) / relativeVelocity.z;
					}
				}
			}

			float tMin, tMax;	//Store our earliest and latest impact times (normalized)
			//Potential time of first impact
			tMin = max(t0.x, max(t0.y, t0.z));
	
			//Potential time of last impact
			tMax = min(t1.x, min(t1.y, t1.z));

			//An impact has only occurred if the time of first impact is less than or equal to the time of last impact
			if(tMin <= tMax)
			{
				collisionOccurred = true;
				core->_collisions->currentCollision.boxA_ID					=	boxA->ID;
				core->_collisions->currentCollision.boxB_ID					=	boxB->ID;
				core->_collisions->currentCollision.impactPoint.x			=	-FLT_MAX;
				core->_collisions->currentCollision.impactPoint.y			=	-FLT_MAX;
				core->_collisions->currentCollision.impactPoint.z			=	-FLT_MAX;
				core->_collisions->currentCollision.timeOfImpact				=	tMin;
				core->_collisions->currentCollision.boxA_movementVector		=	boxA->center() - boxA->centerPointPrevious;
				core->_collisions->currentCollision.boxB_movementVector		=	boxB->center() - boxB->centerPointPrevious;
			
				core->_collisions->addToList();

				timeOfImpact = tMin;

			}
		}
	}

	if(collisionOccurred)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PhysicsCollision::CollisionDetection(vector<AABB*> &boxes, Octree* octree, bool test_z_axis)
{
	/******************************************************
	*	Function Name:		CollisionDetection()
	*	Programmer:			Josh Archer
	*
	*	Determines if a collision has taken place between
	*	two AABB's, and returns the appropriate boolean
	*	value.
	*
	*	Uses the Separating Axis Theorem for detection.
	*
	******************************************************/

	vector<AABBPair> bps;
	bool collisionOccurred = false;

	_octree->potentialBoxBoxCollision(bps, boxes, octree);
	for(unsigned int i = 0; i < bps.size(); i++) 
	{
		AABBPair bp = bps[i];
		
		AABB* shapeTwo = bp.aabb2;
		AABB* shapeOne = bp.aabb1;
		

		//Test shape projections along each axes for overlap. Function can exit as soon as a disjoint (non intersecting) projection is found
		if(shapeOne->maxPoint.x < shapeTwo->minPoint.x || shapeTwo->maxPoint.x < shapeOne->minPoint.x)
		{
			//The shapes' projections along the x-axis are disjoint, so the shapes are not colliding
		}
		else
		{
			if(shapeOne->maxPoint.y < shapeTwo->minPoint.y || shapeTwo->maxPoint.y < shapeOne->minPoint.y)
			{
				//The shapes' projection along the y-axis are disjoint, so the shapes are not colliding
			}
			else
			{
				if(test_z_axis)
				{
					//Collision detection along z axis is desired, so test the third axis for intersection:
					if(shapeOne->maxPoint.z < shapeTwo->minPoint.z || shapeTwo->maxPoint.z < shapeOne->minPoint.z)
					{
						//The shapes' projection along the z-axis are disjoint, so the shapes are not colliding
					}
					else
					{
						//The shapes' projection along all three axes are intersecting, so the shapes ARE colliding
						collisionOccurred	=	true;

						core->_collisions->currentCollision.boxA_ID					=	shapeOne->ID;
						core->_collisions->currentCollision.boxB_ID					=	shapeTwo->ID;
						core->_collisions->currentCollision.impactPoint.x			=	-FLT_MAX;
						core->_collisions->currentCollision.impactPoint.y			=	-FLT_MAX;
						core->_collisions->currentCollision.impactPoint.z			=	-FLT_MAX;
						core->_collisions->currentCollision.boxA_movementVector		=	shapeOne->center() - shapeOne->centerPointPrevious;
						core->_collisions->currentCollision.boxB_movementVector		=	shapeTwo->center() - shapeTwo->centerPointPrevious;
						core->_collisions->currentCollision.timeOfImpact				=	-FLT_MAX;

						core->_collisions->addToList();
					}
				}
				else
				{
					//Collision detection along z axis is NOT desired, and the shapes' projections along both the x and y axes are intersecting, so the shapes ARE colliding
					collisionOccurred	=	true;

					core->_collisions->currentCollision.boxA_ID					=	shapeOne->ID;
					core->_collisions->currentCollision.boxB_ID					=	shapeTwo->ID;
					core->_collisions->currentCollision.impactPoint.x			=	-FLT_MAX;
					core->_collisions->currentCollision.impactPoint.y			=	-FLT_MAX;
					core->_collisions->currentCollision.impactPoint.z			=	-FLT_MAX;
					core->_collisions->currentCollision.boxA_movementVector		=	shapeOne->center() - shapeOne->centerPointPrevious;
					core->_collisions->currentCollision.boxB_movementVector		=	shapeTwo->center() - shapeTwo->centerPointPrevious;
					core->_collisions->currentCollision.timeOfImpact				=	-FLT_MAX;

					core->_collisions->addToList();
				}
			}
		}
	}//End for loop
	if(collisionOccurred)
	{
		return true;
	}
	else
	{
		return false;
	}
}
