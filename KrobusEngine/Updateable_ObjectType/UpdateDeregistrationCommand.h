#ifndef _UpdateDeregistrationCommand
#define _UpdateDeregistrationCommand

#include "CommandBase.h"

class Updatable;

class UpdateDeregistrationCommand : public CommandBase {
public:
	UpdateDeregistrationCommand() = default;
	UpdateDeregistrationCommand(Updatable* up);
	UpdateDeregistrationCommand(const UpdateDeregistrationCommand&) = delete;
	UpdateDeregistrationCommand& operator=(const UpdateDeregistrationCommand&) = delete;
	~UpdateDeregistrationCommand() = default;

	Updatable* ptrUp;

	void execute();
};
#endif _UpdateDeregistrationCommand
