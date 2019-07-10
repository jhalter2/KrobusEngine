//This is the test command that gets called
//when checking for collision between two
//different types of game objects. The intersect
//tests get passed to the math tool which has the
//actual math for detecting collision between the 
//different collision volumes
//
//NOTE: detection is broken up into 4 different tests
//which is done for optimization purposes. Here's a
//bit of a breakdown of that process
//
//TEST 1: tests for collision between the axis aligned bounding boxes
//that surround entire groups of objects. This saves greatly on calculations
//because it allows me to only do 1 collision test between two different groups
//of, for example, 4 objects each, rather than 16 tests for each 
//individual object.
//
//TEST 2: If the two group bounding boxes collide, then
//test for individual bounding sphere intersections
//of group 1 objects compared to group 2's axis aligned
//bounding box. This comes out to 5 total collision tests
//but also bounding sphere collisions are fairly cheap tests
//since they are just spheres.
//
//TEST 3: If one of the bounding spheres of the first group
//collide with the bounding box of the second group, then test
//collisions for the bounding spheres of every member of both groups.
//This comes out to 16 collision tests but it's still cheaper
//because detecting collision between two spheres in 3D space is
//(relatively) cheap
//
//TEST 4: If a pair of individual bounding spheres collide, then
//test the user chosen collision volumes of those two objects.
//The collision volumes can be any of the 3 choices and if the math
//returns true, then the collision function is called for the objects.

#include "CollisionTestPairCommand.h"
#include "CollidableGroup.h"
#include "CollisionDispatchBase.h"
#include "PWMathTools.h"
#include "CollisionVolume.h"
#include "GameObject.h"
#include "Visualizer.h"

CollisionTestPairCommand::CollisionTestPairCommand(CollidableGroup* g1, CollidableGroup* g2, CollisionDispatchBase* pd)
	: pG1(g1), pG2(g2), pDispatch(pd)
{ }

CollisionTestPairCommand::~CollisionTestPairCommand()
{
	delete pDispatch;
}

void CollisionTestPairCommand::Execute()
{
	//1. test both group AABBs for intersect
	if (PWMathTools::Intersect(pG1->GetAABB(), pG2->GetAABB())) {
		//2. test each member's bsphere of group 1 against group 2's AABB
		const CollidableGroup::CollidableCollection& Collection1 = pG1->GetColliderCollection();
		for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++)
		{
			const CollisionVolume& bs1 = (*it1)->GetBSphere();
			if (PWMathTools::Intersect(bs1, pG2->GetAABB())) {
				//3. test the bsphere of each member of group 1 against the bsphere of each member of group 2
				const CollidableGroup::CollidableCollection& Collection2 = pG2->GetColliderCollection();
				for (auto it2 = Collection2.begin(); it2 != Collection2.end(); it2++)
				{
					const CollisionVolume& bs2 = (*it2)->GetBSphere();
					if (PWMathTools::Intersect(bs1, bs2))
					{
						//4. test the collision volumes of the two objects whose bspheres intersected
						const CollisionVolume& cv1 = (*it1)->GetCollisionVolume();
						const CollisionVolume& cv2 = (*it2)->GetCollisionVolume();
						if (PWMathTools::Intersect(cv1, cv2))
						{
							pDispatch->ProcessCallbacks(*it1, *it2);
						
						}
					}
				}
			}
		}
	}
}
