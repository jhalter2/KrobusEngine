#ifndef _DrawableManager
#define _DrawableManager

#include <list>
class Drawable;

class DrawableManager {
private:
	using StorageList = std::list<Drawable*>;
	StorageList storageList;
public:
	DrawableManager() = default;
	DrawableManager(const DrawableManager&) = delete;
	DrawableManager& operator=(const DrawableManager&) = delete;
	~DrawableManager();

	void ProcessElements();

	using StorageListRef = StorageList::iterator;
	StorageListRef ref;
	StorageListRef Register(Drawable* dr);
	void Deregister(StorageListRef r);
};

#endif _DrawableManager
