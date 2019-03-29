#include "Alarmable.h"
#include "RegistrationState.h"
#include "SceneManager.h"
#include "Scene.h"
#include "AzulCore.h"
#include "SceneAttorney.h"

Alarmable::Alarmable() {
	for (int i = 0; i < AlarmableManager::ALARM_NUMBER; i++) {
		RegData[i].RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
		RegData[i].pRegistrationCmd = new AlarmRegistrationCommand();
		RegData[i].pDeregistrationCmd = new AlarmDeregistrationCommand();
	}
}

Alarmable::~Alarmable() {
	//delete commands
	for (int i = 0; i < AlarmableManager::ALARM_NUMBER; i++) {
		delete RegData[i].pRegistrationCmd;
		delete RegData[i].pDeregistrationCmd;
	}
	DebugMsg::out("alarmable deleted\n");
}

void Alarmable::AlarmRegistration(float t, AlarmableManager::ALARM_ID id) {
	assert(RegData[id].RegStateCurr == RegistrationState::PENDING_REGISTRATION);
	RegData[id].pMyDeleteRef = SceneAttorney::GetAlarmMgr()->Register(t, this, id);
	RegData[id].RegStateCurr = RegistrationState::CURRENTLY_REGISTERED;
}

void Alarmable::AlarmDeregistration(AlarmableManager::ALARM_ID id) {
	assert(RegData[id].RegStateCurr == RegistrationState::PENDING_DEREGISTRATION);
	SceneAttorney::GetAlarmMgr()->Deregister(RegData[id].pMyDeleteRef);
	RegData[id].RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Alarmable::SubmitAlarmRegistration(float t, int id) {
	assert(RegData[id].RegStateCurr == RegistrationState::CURRENTLY_DEREGISTERED);
	time = t;
	RegData[id].pRegistrationCmd->Set(this, (AlarmableManager::ALARM_ID)id);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), RegData[id].pRegistrationCmd);
	RegData[id].RegStateCurr = RegistrationState::PENDING_REGISTRATION;
}

void Alarmable::SubmitAlarmDeregistration(int id) {
	assert(RegData[id].RegStateCurr == RegistrationState::CURRENTLY_REGISTERED);
	RegData[id].pDeregistrationCmd->Set(this, (AlarmableManager::ALARM_ID)id);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), RegData[id].pDeregistrationCmd);
	RegData[id].RegStateCurr = RegistrationState::PENDING_DEREGISTRATION;

}

void Alarmable::TriggerAlarm(AlarmableManager::ALARM_ID id) {
	//need to set alarm state to deregistered so that it can trigger itself if it needs to
	//deregister from scene after it is triggered
	//currently 3 alarms available for use per object

	switch (id) {
	case AlarmableManager::ALARM_0:
		RegData[0].RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
		this->Alarm0();
		SceneAttorney::GetAlarmMgr()->Deregister(RegData[0].pMyDeleteRef);
		break;

	case AlarmableManager::ALARM_1:
		RegData[1].RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
		this->Alarm1();
		SceneAttorney::GetAlarmMgr()->Deregister(RegData[1].pMyDeleteRef);
		break;

	case AlarmableManager::ALARM_2:
		RegData[2].RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
		this->Alarm2();
		SceneAttorney::GetAlarmMgr()->Deregister(RegData[2].pMyDeleteRef);
		break;
	};
}