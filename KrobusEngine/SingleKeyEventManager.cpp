#include "SingleKeyEventManager.h"
#include "Inputable.h"
#include "EVENT_TYPE.h"
#include "InputableAttorney.h"

//each single key manager handles only 1 key
SingleKeyEventManager::SingleKeyEventManager(AZUL_KEY k) : Key(k) {}

SingleKeyEventManager::~SingleKeyEventManager() {
	DebugMsg::out("SingleKeyEventManager deleted\n");
}

void SingleKeyEventManager::ProcessKeyEvent() {
	//process keypress and keyrelease events for our specified key
	if (Keyboard::GetKeyState(Key) == true && pressed == false) {
		//DebugMsg::out("Key Pressed\n");
		for (StorageList::iterator it = KeyPressCollection.begin(); it != KeyPressCollection.end(); it++) {
			InputableAttorney::KeyPressed((*it), Key);
		}
		pressed = true;
	}
	else if (Keyboard::GetKeyState(Key) == false && pressed == true) {
		//DebugMsg::out("Key Released\n");
		for (StorageList::iterator it = KeyReleaseCollection.begin(); it != KeyReleaseCollection.end(); it++) {
			InputableAttorney::KeyReleased((*it), Key);
		}
		pressed = false;
	}
}

void SingleKeyEventManager::Register(Inputable* in, EVENT_TYPE e) {
	if ((int)e == 0) KeyPressCollection.push_front(in);
	else KeyReleaseCollection.push_front(in);
}

void SingleKeyEventManager::Deregister(Inputable* in, EVENT_TYPE e) {
	if ((int)e == 0) KeyPressCollection.remove(in);
	else KeyReleaseCollection.remove(in);
}