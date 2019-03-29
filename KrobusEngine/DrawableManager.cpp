#include "DrawableManager.h"
#include "Drawable.h"
#include "AzulCore.h"
#include "DrawableAttorney.h"

DrawableManager::~DrawableManager() {
	DebugMsg::out("drawable manager deleted\n");
}

void DrawableManager::ProcessElements() {
	for (StorageList::iterator it = storageList.begin(); it != storageList.end(); it++) {
		DrawableAttorney::GameLoop::Draw(*it);
		DrawableAttorney::GameLoop::Draw2D(*it);
	}
}

DrawableManager::StorageListRef DrawableManager::Register(Drawable* dr) {
	return ref = storageList.insert(storageList.end(), dr);
}

void DrawableManager::Deregister(StorageListRef r) {
	storageList.erase(r);
}