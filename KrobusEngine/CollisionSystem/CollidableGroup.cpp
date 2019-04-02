#include "CollidableGroup.h"
#include "Drawable.h"
#include "AzulCore.h"

CollidableGroup::~CollidableGroup() {
	DebugMsg::out("CollidableGroup deleted\n");
}

CollidableGroup::StorageListRef CollidableGroup::Register(Collidable* dr) {
	return ref = storageList.insert(storageList.end(), dr);
}

void CollidableGroup::Deregister(StorageListRef r) {
	storageList.erase(r);
}

const CollidableGroup::CollidableCollection& CollidableGroup::GetColliderCollection() {
	return storageList;
}
