#ifndef _AlarmRegistrationCommand
#define _AlarmRegistrationCommand

#include "CommandBase.h"
#include "AlarmableManager.h"

class Alarmable;

class AlarmRegistrationCommand : public CommandBase {
public:
	AlarmRegistrationCommand() = default;
	AlarmRegistrationCommand(Alarmable* al, AlarmableManager::ALARM_ID id);
	AlarmRegistrationCommand(const AlarmRegistrationCommand&) = delete;
	AlarmRegistrationCommand& operator=(const AlarmRegistrationCommand&) = delete;
	~AlarmRegistrationCommand() = default;

	void Set(Alarmable* al, AlarmableManager::ALARM_ID id);
	void execute();

private:
	Alarmable* ptrAl;
	AlarmableManager::ALARM_ID al_id;
	float al_time;
};

#endif _AlarmRegistrationCommand
