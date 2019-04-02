#ifndef _SingleKeyEventManager
#define _SingleKeyEventManager

#include "AzulCore.h"
#include <list>

class Inputable;
enum class EVENT_TYPE;

class SingleKeyEventManager {
private:
	using StorageList = std::list<Inputable*>;
	StorageList KeyPressCollection;
	StorageList KeyReleaseCollection;
	AZUL_KEY Key;
	bool pressed = false;
public:
	SingleKeyEventManager() = delete;
	SingleKeyEventManager(AZUL_KEY k);
	SingleKeyEventManager(const SingleKeyEventManager&) = delete;
	SingleKeyEventManager& operator= (const SingleKeyEventManager&) = delete;
	~SingleKeyEventManager();

	void ProcessKeyEvent();

	//using StorageListRef = StorageList::iterator;
	//StorageListRef ref;
	void Register(Inputable* in, EVENT_TYPE e);
	void Deregister(Inputable* in, EVENT_TYPE e);
};

#endif _SingleKeyEventManager
