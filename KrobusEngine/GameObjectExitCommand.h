#ifndef _GameObjectExitCommand
#define _GameObjectExitCommand

#include "CommandBase.h"

class GameObject;

class GameObjectExitCommand : public CommandBase {
public:
	GameObjectExitCommand() = delete;
	GameObjectExitCommand(GameObject* obj);
	GameObjectExitCommand(const GameObjectExitCommand&) = delete;
	GameObjectExitCommand& operator=(const GameObjectExitCommand&) = delete;
	~GameObjectExitCommand() = default;

	void execute();

private:
	GameObject * go;
};

#endif _GameObjectExitCommand
