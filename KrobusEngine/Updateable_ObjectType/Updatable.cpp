#include "Updatable.h"
#include "SceneManager.h"
#include "Scene.h"
#include "AzulCore.h"
#include "RegistrationState.h"
#include "SceneAttorney.h"

Updatable::Updatable() {
	RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
	pRegistrationCmd = new UpdateRegistrationCommand(this);
	pDeregistrationCmd = new UpdateDeregistrationCommand(this);
}

Updatable::~Updatable() {
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
}

void Updatable::SceneRegistration() {
	assert(RegStateCurr == RegistrationState::PENDING_REGISTRATION);
	pMyDeleteRef = SceneAttorney::GetUpdateMgr()->Register(this);
	RegStateCurr = RegistrationState::CURRENTLY_REGISTERED;
}

void Updatable::SceneDeregistration() {
	assert(RegStateCurr == RegistrationState::PENDING_DEREGISTRATION);
	SceneAttorney::GetUpdateMgr()->Deregister(pMyDeleteRef);
	RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Updatable::SubmitUpdateRegistration() {
	assert(RegStateCurr == RegistrationState::CURRENTLY_DEREGISTERED);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), pRegistrationCmd);
	RegStateCurr = RegistrationState::PENDING_REGISTRATION;
}

void Updatable::SubmitUpdateDeregistration() {
	assert(RegStateCurr == RegistrationState::CURRENTLY_REGISTERED);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), pDeregistrationCmd);
	RegStateCurr = RegistrationState::PENDING_DEREGISTRATION;
}
