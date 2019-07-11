//manager class for generating individual input managers
//as needed by the user. This class maintains a map of
//individual key managers that will track events 
//regarding their own specific keys. 
//When the user registers an object
//for key inputs based on a specific key, this class will
//create a specific key manager to watch for events on that
//single key. It will add that to its map of single key
//managers. The ProcessEvents functions gets called 
//during the Update part of the engine loop and will
//call the process events for each single key manager
//in the map

#include "KeyboardEventManager.h"
#include "EVENT_TYPE.h"

KeyboardEventManager::~KeyboardEventManager() {
	for (StorageList::iterator it = SingleKeyManagers.begin(); it != SingleKeyManagers.end(); it++) {
		delete it->second;
	}
}

//calls ProcessKeyEvent() for every single key manager
//currently in the map
void KeyboardEventManager::ProcessKeyEvents() {
	for (StorageList::iterator it = SingleKeyManagers.begin(); it != SingleKeyManagers.end(); it++) {
		it->second->ProcessKeyEvent();
	}
}

void KeyboardEventManager::Register(Inputable* p, char k, EVENT_TYPE e) {
	StorageList::iterator it = SingleKeyManagers.find(k);
	//if key manager isn't in list, create a new one
	if (it == SingleKeyManagers.end()) {
		SingleKeyEventManager* newKey = new SingleKeyEventManager(k);
		newKey->Register(p, e);
		SingleKeyManagers.insert(std::pair<char, SingleKeyEventManager*>(k, newKey));
	}
	//else we just register the object to the existing key manager
	else {
		it->second->Register(p, e);
	}
}

void KeyboardEventManager::Deregister(Inputable* p, char k, EVENT_TYPE e) {
	for (StorageList::iterator it = SingleKeyManagers.begin(); it != SingleKeyManagers.end(); it++) {
		if (it->first == k) {
			it->second->Deregister(p, e);
			break;
		}
	}
}
