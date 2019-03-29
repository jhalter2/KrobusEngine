#ifndef _CollidableAttorney
#define _CollidableAttorney

#include "Collidable.h"

class CollidableAttorney {
public:
	class Registration {
		friend class CollisionRegistrationCommand;
		friend class CollisionDeregistrationCommand;
	private:
		static void SceneRegistration(Collidable* pMgr) { pMgr->SceneRegistration(); }
		static void SceneDeregistration(Collidable* pMgr) { pMgr->SceneDeregistration(); }
	};
};

#endif _CollidableAttorney
