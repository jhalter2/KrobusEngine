#include "GameObject.h"
#include "RegistrationState.h"
#include "SceneManager.h"
#include "Scene.h"

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
