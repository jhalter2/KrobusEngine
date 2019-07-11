//Drawable is one of the base class types that the GameObject
//class derives from. Any object that needs to be rendered to
//the screen in any way must be a drawable type object. There 
//is no difference for Drawables between 2D and 3D. The difference
//there is just down to which camera the object gets rendered to.

#include "Drawable.h"
#include "SceneManager.h"
#include "Scene.h"
#include "RegistrationState.h"
#include "SceneAttorney.h"
#include <assert.h>

Drawable::Drawable() {
	RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
	pRegistrationCmd = new DrawRegistrationCommand(this);
	pDeregistrationCmd = new DrawDeregistrationCommand(this);
}

Drawable::~Drawable() {
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
}

void Drawable::SceneRegistration() {
	assert(RegStateCurr == RegistrationState::PENDING_REGISTRATION);
	pMyDeleteRef = SceneAttorney::GetDrawMgr()->Register(this);
	RegStateCurr = RegistrationState::CURRENTLY_REGISTERED;
}

void Drawable::SceneDeregistration() {
	assert(RegStateCurr == RegistrationState::PENDING_DEREGISTRATION);
	SceneAttorney::GetDrawMgr()->Deregister(pMyDeleteRef);
	RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Drawable::SubmitDrawRegistration() {
	assert(RegStateCurr == RegistrationState::CURRENTLY_DEREGISTERED);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), pRegistrationCmd);
	RegStateCurr = RegistrationState::PENDING_REGISTRATION;
}

void Drawable::SubmitDrawDeregistration() {	
	assert(RegStateCurr == RegistrationState::CURRENTLY_REGISTERED);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), pDeregistrationCmd);
	RegStateCurr = RegistrationState::PENDING_DEREGISTRATION;
}
