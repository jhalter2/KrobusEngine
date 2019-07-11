//the single key event managers monitor and process
//press/release events for a specific key. They are created
//by and managed by the KeyboardEventManager class

#include "SingleKeyEventManager.h"
#include "Inputable.h"
#include "EVENT_TYPE.h"
#include "InputableAttorney.h"
#include <Windows.h>

//each single key manager handles only 1 key
SingleKeyEventManager::SingleKeyEventManager(char k) : Key(k) {}

SingleKeyEventManager::~SingleKeyEventManager() {
	//DebugMsg::out("SingleKeyEventManager deleted\n");
}

void SingleKeyEventManager::ProcessKeyEvent() {
	//process keypress and keyrelease events for our specified key
	if ((GetKeyState(Key) & 0x08000) && pressed == false) {
		//DebugMsg::out("Key Pressed\n");
		for (StorageList::iterator it = KeyPressCollection.begin(); it != KeyPressCollection.end(); it++) {
			InputableAttorney::KeyPressed((*it), Key);
		}
		pressed = true;
	}
	else if ((GetKeyState(Key) & 0x08000) && pressed == true) {
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
