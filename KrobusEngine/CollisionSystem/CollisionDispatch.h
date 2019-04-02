#ifndef _CollisionDispatch
#define _CollisionDispatch

#include "CollisionDispatchBase.h"

template <typename C1, typename C2>
class CollisionDispatch : public CollisionDispatchBase
{
public:
	virtual void ProcessCallbacks(Collidable* c1, Collidable* c2)
	{
		//cast up to get original type
		C1* pDerCol1 = static_cast<C1*>(c1);
		C2* pDerCol2 = static_cast<C2*>(c2);

		pDerCol1->Collision(pDerCol2);
		pDerCol2->Collision(pDerCol1);
	}
};

#endif _CollisionDispatch
