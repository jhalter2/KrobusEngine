#ifndef _SceneChangeCommand
#define _SceneChangeCommand

#include "CommandBase.h"

class Scene;

class SceneChangeCommand : public CommandBase {
public:
	SceneChangeCommand() = default;
	SceneChangeCommand(Scene* ns);
	SceneChangeCommand(const SceneChangeCommand&) = delete;
	SceneChangeCommand& operator=(const SceneChangeCommand&) = delete;
	~SceneChangeCommand() = default;

	void execute();
	void SetScene(Scene* ns);

private:
	Scene *pScene;
};

#endif _SceneChangeCommand
