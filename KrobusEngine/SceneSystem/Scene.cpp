#include "Scene.h"
#include "Camera.h"
#include "CameraManager.h"

Camera* Scene::GetCurrentCamera() {
	return CamMgr.GetCurrentCamera();
}

Camera* Scene::GetCurrent2DCamera() {
	return CamMgr.GetCurrent2DCamera();
}

void Scene::SubmitCommand(CommandBase* cmd) {
	//add game object commands for draw, update, etc to our broker
	RegistrationBrkr.addCommand(cmd);
}

void Scene::Update() {
	//all commands will be processed within the update call
	RegistrationBrkr.ExecuteCommands();

	AlarmMgr.ProcessAlarms();
	KBEventMgr.ProcessKeyEvents();
	CollisionMgr.ProcessCollisions();
	UpdateMgr.ProcessElements();
}

void Scene::Draw() {
	DrawMgr.ProcessElements();
}
