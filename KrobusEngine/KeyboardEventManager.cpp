#include "KeyboardEventManager.h"
#include "EVENT_TYPE.h"

KeyboardEventManager::~KeyboardEventManager() {
	for (StorageList::iterator it = SingleKeyManagers.begin(); it != SingleKeyManagers.end(); it++) {
		delete it->second;
	}
}

void KeyboardEventManager::ProcessKeyEvents() {
	for (StorageList::iterator it = SingleKeyManagers.begin(); it != SingleKeyManagers.end(); it++) {
		it->second->ProcessKeyEvent();
	}
}

void KeyboardEventManager::Register(Inputable* p, AZUL_KEY k, EVENT_TYPE e) {
	StorageList::iterator it = SingleKeyManagers.find(k);
	//if key manager isn't in list, create a new one
	if (it == SingleKeyManagers.end()) {
		SingleKeyEventManager* newKey = new SingleKeyEventManager(k);
		newKey->Register(p, e);
		SingleKeyManagers.insert(std::pair<AZUL_KEY, SingleKeyEventManager*>(k, newKey));
	}
	//else we just register the object to the existing key manager
	else {
		it->second->Register(p, e);
	}
}

void KeyboardEventManager::Deregister(Inputable* p, AZUL_KEY k, EVENT_TYPE e) {
	for (StorageList::iterator it = SingleKeyManagers.begin(); it != SingleKeyManagers.end(); it++) {
		if (it->first == k) {
			it->second->Deregister(p, e);
			break;
		}
	}
}