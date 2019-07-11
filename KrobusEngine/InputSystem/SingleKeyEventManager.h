#ifndef _SingleKeyEventManager
#define _SingleKeyEventManager

#include <list>

class Inputable;
enum class EVENT_TYPE;

class SingleKeyEventManager {
private:
	using StorageList = std::list<Inputable*>;
	StorageList KeyPressCollection;
	StorageList KeyReleaseCollection;
	char Key;
	bool pressed = false;
public:
	SingleKeyEventManager() = delete;
	SingleKeyEventManager(char k);
	SingleKeyEventManager(const SingleKeyEventManager&) = delete;
	SingleKeyEventManager& operator= (const SingleKeyEventManager&) = delete;
	~SingleKeyEventManager();

	void ProcessKeyEvent();

	void Register(Inputable* in, EVENT_TYPE e);
	void Deregister(Inputable* in, EVENT_TYPE e);
};

#endif _SingleKeyEventManager
