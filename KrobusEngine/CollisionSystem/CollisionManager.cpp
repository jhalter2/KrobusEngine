//Central manager for collision pipeline.
//updates the axis aligned bounding box for
//object groups and also executes the queue of
//collision test commands. Processing here is called
//in the Update loop of the engine

#include "CollisionManager.h"
#include "CollidableGroup.h"
#include "CollisionTestCommandBase.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeBSphere.h"
#include "Visualizer.h"
#include "PWMathTools.h"

CollisionManager::CollisionManager() {
	ColGroupCollection = CollidableGroupCollection(5);
}

CollisionManager::~CollisionManager() {
	for (CollidableGroupCollection::iterator it = ColGroupCollection.begin(); it != ColGroupCollection.end(); ++it) {
		delete (*it);
	}
	ColGroupCollection.clear();
	for (CollisionTestCommands::iterator it = colTestCommands.begin(); it != colTestCommands.end(); ++it) {
		
		delete (*it);
	}
	colTestCommands.clear();
	//DebugMsg::out("collision manager deleted\n");
}

CollidableGroup* CollisionManager::GetColGroup(PWTypeID id) {
	return ColGroupCollection[id];
}

//set a group collision ID if a specific object group
//does not already have a set ID
//
//NOTE: type IDs persist between scenes and will remain
//the same until the engine shutsdown. They are otherwise
//arbitrary.

void CollisionManager::SetGroupForTypeID(CollisionManager::PWTypeID ind) {
	if (ColGroupCollection[ind] == nullptr)
	{
		ColGroupCollection[ind] = new CollidableGroup();
	}
}

//update the group axis aligned bounding boxes
//before proceeding to the collision testing

void CollisionManager::ProcessCollisions() {
	//update group aabb here to avoid repeat work
	UpdateGroupAABB();
	for (CollisionManager::CollisionTestCommands::iterator it = colTestCommands.begin(); it != colTestCommands.end(); ++it)
	{
		(*it)->Execute();
	}
}

//each object of the same type (that has also been registered
//for collision) will have an axis aligned bounding box around
//all objects of that type. This is done to optimize collision
//testing 

void CollisionManager::UpdateGroupAABB() {
	//update the group's aabb for spatial partitioning
	for (CollidableGroupCollection::iterator it = ColGroupCollection.begin(); it != ColGroupCollection.end(); ++it) {
		if ((*it) != nullptr && (*it)->storageList.size() != 0) {
			(*it)->UpdateAABB();
		}
		else {
			break;
		}
	}
}
