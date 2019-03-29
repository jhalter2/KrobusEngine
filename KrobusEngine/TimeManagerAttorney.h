#ifndef _TimeManagerAttorney
#define _TimeManagerAttorney

#include "TimeManager.h"

class TimeManagerAttorney {
	friend class KrobusEngine;

private:
	static void ProcessTime(float sys_time) { TimeManager::ProcessTime(sys_time); };
	static void Terminate() { TimeManager::Terminate(); }
};

#endif _TimeManagerAttorney
