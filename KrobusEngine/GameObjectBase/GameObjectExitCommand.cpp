#include "GameObjectExitCommand.h"
#include "GameObject.h"

GameObjectExitCommand::GameObjectExitCommand(GameObject* obj) : go(obj) {}

void GameObjectExitCommand::execute() {
	go->DisconnectFromScene();
}
