#ifndef _SceneRegistrationBroker
#define _SceneRegistrationBroker

#include <list>
#include "AzulCore.h"

enum class EVENT_TYPE;
class CommandBase;

class SceneRegistrationBroker {
public:
	SceneRegistrationBroker() = default;
	SceneRegistrationBroker(const SceneRegistrationBroker&) = delete;
	SceneRegistrationBroker& operator=(const SceneRegistrationBroker&) = delete;
	~SceneRegistrationBroker() = default;

	void addCommand(CommandBase* c);
	void ExecuteCommands();
private:
	using CommandList = std::list<CommandBase*>;
	CommandList lstCommands;
};

#endif _SceneRegistrationBroker
