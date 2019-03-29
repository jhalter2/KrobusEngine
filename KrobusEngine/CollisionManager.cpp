#include "CollisionManager.h"
#include "AzulCore.h"
#include "CollidableGroup.h"
#include "CollisionTestCommandBase.h"

CollisionManager::CollisionManager() {
	ColGroupCollection = CollidableGroupCollection(5);
}

CollisionManager::~CollisionManager() {
	for (CollidableGroupCollection::iterator it = ColGroupCollection.begin(); it != ColGroupCollection.end(); ++it) {
		delete (*it);
	}
	DebugMsg::out("collision manager deleted\n");
}

CollidableGroup* CollisionManager::GetColGroup(PWTypeID id) {
	return ColGroupCollection[id];
}

void CollisionManager::SetGroupForTypeID(CollisionManager::PWTypeID ind) {
	if (ColGroupCollection[ind] == nullptr)
		ColGroupCollection[ind] = new CollidableGroup();
}

void CollisionManager::ProcessCollisions() {
	for (CollisionManager::CollisionTestCommands::iterator it = colTestCommands.begin(); it != colTestCommands.end(); ++it)
	{
		(*it)->Execute();
	}
}