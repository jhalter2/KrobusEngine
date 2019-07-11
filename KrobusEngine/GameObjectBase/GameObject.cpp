//central class that objects in scenes will need to use.
//derives from all types that gameobjects will need to be
//such as updatable, drawable, etc. Contains registration.
//
//NOTE: contains functions to connect and disconnect an object
//from a scene. Those two functions should be used when a specific
//object needs to be removed from a scene with the intention of later
//adding that object back into a scene. If there is no intention to
//reuse an object, then it can simply be deregistered and deleted.

#include "GameObject.h"
#include "RegistrationState.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneAttorney.h"
#include <assert.h>

GameObject::GameObject() {
	pRegCmd = new GameObjectEntryCommand(this);
	pDeregCmd = new GameObjectExitCommand(this);
	currState = RegistrationState::CURRENTLY_DEREGISTERED;
}

GameObject::~GameObject() {
	delete pRegCmd;
	delete pDeregCmd;
}

void GameObject::SubmitEntry() {
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), pRegCmd);
}

void GameObject::SubmitExit() {
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), pDeregCmd);
}

void GameObject::ConnectToScene() {
	//make sure game object is not connected to a scene
	assert(currState == RegistrationState::CURRENTLY_DEREGISTERED);

	currState = RegistrationState::CURRENTLY_REGISTERED;
	//user defined method
	this->SceneEntry();
}

void GameObject::DisconnectFromScene() {
	this->SceneExit();
	currState = RegistrationState::CURRENTLY_DEREGISTERED;
}
