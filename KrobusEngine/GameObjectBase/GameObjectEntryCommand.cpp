#include "GameObjectEntryCommand.h"
#include "GameObject.h"

GameObjectEntryCommand::GameObjectEntryCommand(GameObject* obj) : go(obj) {}

void GameObjectEntryCommand::execute() {
	go->ConnectToScene();
}
