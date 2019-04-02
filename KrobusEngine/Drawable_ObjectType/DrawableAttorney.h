#ifndef _DrawableAttorney
#define _DrawableAttorney

#include "Drawable.h"

class DrawableAttorney {
public:
	class GameLoop
	{
	private:
		friend class DrawableManager;
		static void Draw(Drawable* pMgr) { pMgr->Draw(); }
		static void Draw2D(Drawable* pMgr) { pMgr->Draw2D(); }
	};

public:
	class Registration {
		friend class DrawRegistrationCommand;
		friend class DrawDeregistrationCommand;
	private:
		static void SceneRegistration(Drawable* pMgr) { pMgr->SceneRegistration(); }
		static void SceneDeregistration(Drawable* pMgr) { pMgr->SceneDeregistration(); }
	};
};
#endif _DrawableAttorney
