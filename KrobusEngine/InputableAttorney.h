#ifndef _InputableAttorney
#define _InputableAttorney

#include "Inputable.h"

class InputableAttorney {
public:
	class Registration {
		friend class InputRegistrationCommand;
		friend class InputDeregistrationCommand;
		friend class SingleKeyEventManager;
	private:
		static void SceneRegistration(Inputable* pMgr, AZUL_KEY k, EVENT_TYPE e) { pMgr->SceneRegistration(k, e); }
		static void SceneDeregistration(Inputable* pMgr, AZUL_KEY k, EVENT_TYPE e) { pMgr->SceneDeregistration(k, e); }
	};

	friend class SingleKeyEventManager;
	static void KeyPressed(Inputable* pMgr, AZUL_KEY k) { pMgr->KeyPressed(k); }
	static void KeyReleased(Inputable* pMgr, AZUL_KEY k) { pMgr->KeyReleased(k); }
};

#endif _InputableAttorney
