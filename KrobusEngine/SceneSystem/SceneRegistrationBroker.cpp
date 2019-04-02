#include "SceneRegistrationBroker.h"
#include "CommandBase.h"
#include "EVENT_TYPE.h"

void SceneRegistrationBroker::addCommand(CommandBase* c) {
	lstCommands.push_front(c);
}

void SceneRegistrationBroker::ExecuteCommands() {
	CommandList::iterator it = lstCommands.begin();
	while (it != lstCommands.end()) {
		(*it)->execute();
		lstCommands.erase(it);
		it = lstCommands.begin();
	}
}
