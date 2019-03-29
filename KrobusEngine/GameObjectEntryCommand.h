#ifndef _GameObjectEntryCommand
#define _GameObjectEntryCommand

#include "CommandBase.h"

class GameObject;

class GameObjectEntryCommand : public CommandBase {
public:
	GameObjectEntryCommand() = delete;
	GameObjectEntryCommand(GameObject* obj);
	GameObjectEntryCommand(const GameObjectEntryCommand&) = delete;
	GameObjectEntryCommand& operator=(const GameObjectEntryCommand&) = delete;
	~GameObjectEntryCommand() = default;

	void execute();

private:
	GameObject* go;
};

#endif _GameObjectEntryCommand
