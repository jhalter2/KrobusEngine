#ifndef _KeyboardEventManager
#define _KeyboardEventManager

#include <map>
#include "SingleKeyEventManager.h"

enum class EVENT_TYPE;

class KeyboardEventManager {
private:
	using StorageList = std::map<char, SingleKeyEventManager*>;
	StorageList SingleKeyManagers;
public:
	KeyboardEventManager() = default;
	KeyboardEventManager(const KeyboardEventManager&) = delete;
	KeyboardEventManager& operator=(const KeyboardEventManager&) = delete;
	~KeyboardEventManager();

	void ProcessKeyEvents();

	void Register(Inputable* p, char k, EVENT_TYPE e);
	void Deregister(Inputable* p, char k, EVENT_TYPE e);
};

#endif _KeyboardEventManager
