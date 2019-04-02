#include "SceneChangeCommand.h"
#include "Scene.h"
#include "SceneManager.h"
#include "SceneManagerAttorney.h"

SceneChangeCommand::SceneChangeCommand(Scene* ns) : pScene(ns) {}

void SceneChangeCommand::execute() {
	SceneManagerAttorney::SwitchToNextScene(pScene);
}

void SceneChangeCommand::SetScene(Scene* ns) {
	pScene = ns;
}
