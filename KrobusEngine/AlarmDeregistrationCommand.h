#ifndef _AlarmDeregistrationCommand
#define _AlarmDeregistrationCommand

#include "CommandBase.h"
#include "AlarmableManager.h"

class Alarmable;

class AlarmDeregistrationCommand : public CommandBase {
public:
	AlarmDeregistrationCommand() = default;
	AlarmDeregistrationCommand(Alarmable* al, AlarmableManager::ALARM_ID id);
	AlarmDeregistrationCommand(const AlarmDeregistrationCommand&) = delete;
	AlarmDeregistrationCommand& operator= (const AlarmDeregistrationCommand&) = delete;
	~AlarmDeregistrationCommand() = default;

	void Set(Alarmable* al, AlarmableManager::ALARM_ID id);

	void execute();

private:
	Alarmable* ptrAl;
	AlarmableManager::ALARM_ID al_id;
};
#endif _AlarmDeregistrationCommand
