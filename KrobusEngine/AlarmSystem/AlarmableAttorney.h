#ifndef _AlarmableAttorney
#define _AlarmableAttorney

#include "Alarmable.h"

//attorney code for wrapper access

class AlarmableAttorney {
public:
	class Registration {
		friend class AlarmableManager;
		friend class AlarmRegistrationCommand;
		friend class AlarmDeregistrationCommand;
	private:
		static void SceneRegistration(Alarmable* pMgr, float t, AlarmableManager::ALARM_ID id) { pMgr->AlarmRegistration(t, id); }
		static void SceneDeregistration(Alarmable* pMgr, AlarmableManager::ALARM_ID id) { pMgr->AlarmDeregistration(id); }
		static float GetTime(Alarmable* pMgr) { return pMgr->time; }
	};

	friend class AlarmableManager;
	static void TriggerAlarm(Alarmable* pMgr, AlarmableManager::ALARM_ID id) { pMgr->TriggerAlarm(id); }
};

#endif _AlarmableAttorney
