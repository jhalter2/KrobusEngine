#ifndef _CollidableGroup
#define _CollidableGroup

#include <list>

class Collidable;

class CollidableGroup {
public:
	CollidableGroup() = default;
	CollidableGroup(const CollidableGroup&) = delete;
	CollidableGroup& operator=(const CollidableGroup&) = delete;
	~CollidableGroup();

	using CollidableCollection = std::list<Collidable*>;
	CollidableCollection storageList;

	using StorageListRef = CollidableCollection::iterator;
	StorageListRef ref;
	StorageListRef Register(Collidable* cl);
	void Deregister(StorageListRef r);
	const CollidableCollection& GetColliderCollection();

};

#endif _CollidableGroup
