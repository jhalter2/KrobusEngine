#ifndef _KeyboardEventManager
#define _KeyboardEventManager

#include <map>
#include "AzulCore.h"
#include "SingleKeyEventManager.h"

enum class EVENT_TYPE;

class KeyboardEventManager {
private:
	using StorageList = std::map<AZUL_KEY, SingleKeyEventManager*>;
	StorageList SingleKeyManagers;
public:
	KeyboardEventManager() = default;
	KeyboardEventManager(const KeyboardEventManager&) = delete;
	KeyboardEventManager& operator=(const KeyboardEventManager&) = delete;
	~KeyboardEventManager();

	void ProcessKeyEvents();

	void Register(Inputable* p, AZUL_KEY k, EVENT_TYPE e);
	void Deregister(Inputable* p, AZUL_KEY k, EVENT_TYPE e);
};

#endif _KeyboardEventManager
