//base class for inputable objects that the GameObject class
//derives from. Inputable allows objects to receive inputs
//from the keyboard during runtime. The user must register 
//objects for input based on specific keys to look for
//and also for either a key press/key release event.

#include "Inputable.h"
#include "EVENT_TYPE.h"
#include "RegistrationState.h"
#include "SceneManager.h"
#include "Scene.h"
#include "InputRegistrationCommand.h"
#include "InputDeregistrationCommand.h"
#include "SceneAttorney.h"
#include <assert.h>

Inputable::Inputable() {
	RegData.RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
	RegData.pRegistrationCmd = new InputRegistrationCommand();
	RegData.pDeregistrationCmd = new InputDeregistrationCommand();
}

void Inputable::KeyPressed(char k) {
	key = k;
}

void Inputable::KeyReleased(char k) {
	key = k;
}

Inputable::~Inputable() {
	//delete commands
	delete RegData.pRegistrationCmd;
	delete RegData.pDeregistrationCmd;
	//DebugMsg::out("inputable deleted\n");
}

void Inputable::SceneRegistration(char k, EVENT_TYPE e) {
	assert(RegData.RegStateCurr == RegistrationState::PENDING_REGISTRATION || 
		RegData.RegStateCurr == RegistrationState::CURRENTLY_REGISTERED);
	SceneAttorney::GetInputMgr()->Register(this, k, e);
	RegData.RegStateCurr = RegistrationState::CURRENTLY_REGISTERED;
}

void Inputable::SceneDeregistration(char k, EVENT_TYPE e) {
	assert(RegData.RegStateCurr == RegistrationState::PENDING_DEREGISTRATION);
	SceneAttorney::GetInputMgr()->Deregister(this, k, e);
	RegData.RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
}

//event type must be specified press/release
void Inputable::SubmitKeyRegistration(char k, EVENT_TYPE e) {
	assert(RegData.RegStateCurr == RegistrationState::CURRENTLY_DEREGISTERED || 
		RegData.RegStateCurr == RegistrationState::PENDING_REGISTRATION);
	key = k;
	ev = e;
	RegData.pRegistrationCmd->Set(this, k, e);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), RegData.pRegistrationCmd);
	RegData.RegStateCurr = RegistrationState::PENDING_REGISTRATION;
}

//event type must be specified press/release
void Inputable::SubmitKeyDeregistration(char k, EVENT_TYPE e) {
	assert(RegData.RegStateCurr == RegistrationState::CURRENTLY_REGISTERED);
	key = k;
	ev = e;
	RegData.pDeregistrationCmd->Set(this, key, e);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), RegData.pDeregistrationCmd);
	RegData.RegStateCurr = RegistrationState::PENDING_DEREGISTRATION;
}
