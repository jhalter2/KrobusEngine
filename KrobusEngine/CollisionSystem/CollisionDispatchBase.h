#ifndef _CollisionDispatchBase
#define _CollisionDispatchBase

class Collidable;

class CollisionDispatchBase {
public:
	virtual void ProcessCallbacks(Collidable*, Collidable*) {};
};

#endif _CollisionDispatchBase
