#include "AlarmDeregistrationCommand.h"
#include "Alarmable.h"
#include "AlarmableAttorney.h"

//deregistration command for alarm command system.
//processed through AlarmManager which is called during
//engine Update Loop
AlarmDeregistrationCommand::AlarmDeregistrationCommand(Alarmable* al, AlarmableManager::ALARM_ID id) : ptrAl(al), al_id(id) {}

void AlarmDeregistrationCommand::Set(Alarmable* al, AlarmableManager::ALARM_ID id) {
	ptrAl = al;
	al_id = id;
}

void AlarmDeregistrationCommand::execute() {
	AlarmableAttorney::Registration::SceneDeregistration(ptrAl, al_id);
}
