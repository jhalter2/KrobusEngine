//calls user defined DisconnectFromScene()
//when an object needs to leave the scene

#include "GameObjectExitCommand.h"
#include "GameObject.h"

GameObjectExitCommand::GameObjectExitCommand(GameObject* obj) : go(obj) {}

void GameObjectExitCommand::execute() {
	go->DisconnectFromScene();
}
