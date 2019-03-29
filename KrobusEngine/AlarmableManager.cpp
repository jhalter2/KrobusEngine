#include "AlarmableManager.h"
#include "Alarmable.h"
#include "AzulCore.h"
#include "KrobusEngine.h"
#include "TimeManager.h"
#include "AlarmableAttorney.h"

AlarmableManager::~AlarmableManager() {
	DebugMsg::out("alarmable manager deleted \n");
}

void AlarmableManager::ProcessAlarms() {
	TimeLineMap::iterator it;
	it = timeline.begin();
	//current time
	float seconds = TimeManager::GetTime();
	//process all alarms that need to go off
	while (it != timeline.end()) {
		if (seconds >= it->first) {
			AlarmableAttorney::TriggerAlarm(it->second.first, it->second.second);
			it = timeline.begin();
		}
		else {
			break;
		}
	}
}

AlarmableManager::StorageListRef AlarmableManager::Register(float t, Alarmable* al, ALARM_ID id) {
	AlarmEvent a1(al, id);
	//add alarm time to current time and insert into the timeline
	return ref = timeline.insert(std::pair<float, AlarmEvent>((TimeManager::GetTime() + t), a1));
}

void AlarmableManager::Deregister(AlarmableManager::StorageListRef r) {
	timeline.erase(r);
}