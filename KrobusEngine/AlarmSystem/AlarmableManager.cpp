#include "AlarmableManager.h"
#include "Alarmable.h"
#include "AzulCore.h"
#include "KrobusEngine.h"
#include "TimeManager.h"
#include "AlarmableAttorney.h"

//Manager for processing any alarms.
//Gets called during every engine Update loop
//to check if any alarms should be triggered
AlarmableManager::~AlarmableManager() {
	DebugMsg::out("alarmable manager deleted \n");
}

//ProcessAlarms() gets called from engine Update() and
//checks current time vs alarm time in an ordered list
void AlarmableManager::ProcessAlarms() {
	TimeLineMap::iterator it;
	it = timeline.begin();
	//current time
	float seconds = TimeManager::GetTime();
	//process all alarms that need to go off
	while (it != timeline.end()) {
		//keep checking alarms only if the first one is triggered (since list is ordered)
		if (seconds >= it->first) {
			AlarmableAttorney::TriggerAlarm(it->second.first, it->second.second);
			it = timeline.begin();
		}
		//if first one doesn't pass then break the loop
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
