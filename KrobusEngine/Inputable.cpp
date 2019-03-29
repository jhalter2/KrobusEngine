#include "Inputable.h"
#include "EVENT_TYPE.h"
#include "RegistrationState.h"
#include "SceneManager.h"
#include "Scene.h"
#include "InputRegistrationCommand.h"
#include "InputDeregistrationCommand.h"
#include "SceneAttorney.h"

Inputable::Inputable() {
	RegData.RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
	RegData.pRegistrationCmd = new InputRegistrationCommand();
	RegData.pDeregistrationCmd = new InputDeregistrationCommand();
}

void Inputable::KeyPressed(AZUL_KEY k) {
	key = k;
}

void Inputable::KeyReleased(AZUL_KEY k) {
	key = k;
}

Inputable::~Inputable() {
	//delete commands
	delete RegData.pRegistrationCmd;
	delete RegData.pDeregistrationCmd;
	DebugMsg::out("inputable deleted\n");
}

void Inputable::SceneRegistration(AZUL_KEY k, EVENT_TYPE e) {
	assert(RegData.RegStateCurr == RegistrationState::PENDING_REGISTRATION);
	SceneAttorney::GetInputMgr()->Register(this, k, e);
	RegData.RegStateCurr = RegistrationState::CURRENTLY_REGISTERED;
}

void Inputable::SceneDeregistration(AZUL_KEY k, EVENT_TYPE e) {
	assert(RegData.RegStateCurr == RegistrationState::PENDING_DEREGISTRATION);
	SceneAttorney::GetInputMgr()->Deregister(this, k, e);
	RegData.RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Inputable::SubmitKeyRegistration(AZUL_KEY k, EVENT_TYPE e) {
	assert(RegData.RegStateCurr == RegistrationState::CURRENTLY_DEREGISTERED);
	key = k;
	ev = e;
	RegData.pRegistrationCmd->Set(this, k, e);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), RegData.pRegistrationCmd);
	RegData.RegStateCurr = RegistrationState::PENDING_REGISTRATION;
}

void Inputable::SubmitKeyDeregistration(AZUL_KEY k, EVENT_TYPE e) {
	assert(RegData.RegStateCurr == RegistrationState::CURRENTLY_REGISTERED);
	key = k;
	ev = e;
	RegData.pDeregistrationCmd->Set(this, key, e);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), RegData.pDeregistrationCmd);
	RegData.RegStateCurr = RegistrationState::PENDING_DEREGISTRATION;
}