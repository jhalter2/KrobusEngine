#include "AlarmRegistrationCommand.h"
#include "Alarmable.h"
#include "AlarmableAttorney.h"

AlarmRegistrationCommand::AlarmRegistrationCommand(Alarmable* al, AlarmableManager::ALARM_ID id) : ptrAl(al), al_id(id), 
	al_time(AlarmableAttorney::Registration::GetTime(al)) {}

void AlarmRegistrationCommand::Set(Alarmable* al, AlarmableManager::ALARM_ID id) {
	ptrAl = al;
	al_id = id;
	al_time = AlarmableAttorney::Registration::GetTime(al);
}

void AlarmRegistrationCommand::execute() {
	AlarmableAttorney::Registration::SceneRegistration(ptrAl, al_time, al_id);
}