#include "UpdatableManager.h"
#include "Updatable.h"
#include "AzulCore.h"
#include "UpdatableAttorney.h"

UpdatableManager::~UpdatableManager() {
	DebugMsg::out("updatable manager deleted\n");
}

void UpdatableManager::ProcessElements() {
	for (StorageList::iterator it = storageList.begin(); it != storageList.end(); it++) {
		UpdatableAttorney::GameLoop::Update(*it);
	}
}

UpdatableManager::StorageListRef UpdatableManager::Register(Updatable* up) {
	return ref = storageList.insert(storageList.end(), up);
}

void UpdatableManager::Deregister(StorageListRef r) {
	storageList.erase(r);
}