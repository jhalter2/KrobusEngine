#include "AlarmRegistrationCommand.h"
#include "Alarmable.h"
#include "AlarmableAttorney.h"

//registration class for AlarmCommand system.
//AlarmManager has list of commands to execute and are
//processed when engine Update loop is called

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
