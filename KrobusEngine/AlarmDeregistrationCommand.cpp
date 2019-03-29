#include "AlarmDeregistrationCommand.h"
#include "Alarmable.h"
#include "AlarmableAttorney.h"

AlarmDeregistrationCommand::AlarmDeregistrationCommand(Alarmable* al, AlarmableManager::ALARM_ID id) : ptrAl(al), al_id(id) {}

void AlarmDeregistrationCommand::Set(Alarmable* al, AlarmableManager::ALARM_ID id) {
	ptrAl = al;
	al_id = id;
}

void AlarmDeregistrationCommand::execute() {
	AlarmableAttorney::Registration::SceneDeregistration(ptrAl, al_id);
}