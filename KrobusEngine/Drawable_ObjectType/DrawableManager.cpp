//central manager for processing draw commands.
//any objects registered for Drawing on the screen
//will have their Draw functions called here. The
//draw update is called from the engine Update loop

#include "DrawableManager.h"
#include "Drawable.h"
#include "DrawableAttorney.h"

void DrawableManager::ProcessElements() {
	//draw elements
	for (StorageList::iterator it = storageList.begin(); it != storageList.end(); it++) {
		DrawableAttorney::GameLoop::Draw(*it);
	}
}

DrawableManager::StorageListRef DrawableManager::Register(Drawable* dr) {
	return ref = storageList.insert(storageList.end(), dr);
}

void DrawableManager::Deregister(StorageListRef r) {
	storageList.erase(r);
}
