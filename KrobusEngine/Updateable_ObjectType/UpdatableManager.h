#ifndef _UpdatableManager
#define _UpdatableManager

#include <list>
class Updatable;

class UpdatableManager {
private:
	using StorageList = std::list<Updatable*>;
	StorageList storageList;
public:
	UpdatableManager() = default;
	UpdatableManager(const UpdatableManager&) = delete;
	UpdatableManager& operator=(const UpdatableManager&) = delete;
	~UpdatableManager();

	void ProcessElements();

	using StorageListRef = StorageList::iterator;
	StorageListRef ref;
	StorageListRef Register(Updatable* up);
	void Deregister(StorageListRef r);
};

#endif _UpdatableManager
