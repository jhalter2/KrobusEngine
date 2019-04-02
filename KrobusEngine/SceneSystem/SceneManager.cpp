#include "SceneManager.h"
#include "Scene.h"
#include "SceneDemo.h"
#include "AzulCore.h"
#include "SceneNull.h"
#include "SceneChangeCommand.h"
#include "SceneChangeNullCommand.h"
#include "CommandBase.h"
#include "SceneAttorney.h"

SceneManager* SceneManager::ptrInstance = nullptr;

SceneManager::SceneManager() {
	CurrentScene = new SceneNull();

	sc = new SceneChangeCommand();
	nsc = new SceneChangeNullCommand();
	cb = nsc;
}

SceneManager::~SceneManager() {
	delete CurrentScene;
	delete sc;
	delete nsc;
	DebugMsg::out("scene manager & scenes deleted\n");
}

Scene* SceneManager::GetCurrentScene() {
	return Instance().CurrentScene;
}

void SceneManager::InitStartScene() {
	SceneAttorney::Initialize(Instance().CurrentScene);
}

void SceneManager::SetStartScene(Scene* ns) {
	//designate first scene
	Instance().SetNextScene(ns);
}

void SceneManager::SwitchToNextScene(Scene* ns) {
	//DELETE CURRENT SCENE
	//then swap to new scene
	delete Instance().CurrentScene;
	Instance().CurrentScene = ns;
	SceneAttorney::Initialize(Instance().CurrentScene);
	DebugMsg::out("swapped to new scene\n");
}

void SceneManager::SetNextScene(Scene* ns) {
	//swap to scene change command and place it in
	Instance().cb = Instance().sc;
	Instance().sc->SetScene(ns);
}

void SceneManager::Update() {
	SceneAttorney::Update(Instance().CurrentScene);
	//scene manager will process any scene changes after all updates/draws/etc of current frame are completed
	//execute the change command then switch it back to a scene null command
	Instance().cb->execute();
	Instance().cb = Instance().nsc;
}

void SceneManager::Draw() {
	SceneAttorney::Draw(Instance().CurrentScene);
}

void SceneManager::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}

