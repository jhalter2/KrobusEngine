#ifndef _UpdateRegistrationCommand
#define _UpdateRegistrationCommand

#include "CommandBase.h"

class Updatable;

class UpdateRegistrationCommand : public CommandBase {
public:
	UpdateRegistrationCommand() = default;
	UpdateRegistrationCommand(Updatable* up);
	UpdateRegistrationCommand(const UpdateRegistrationCommand&) = delete;
	UpdateRegistrationCommand& operator=(const UpdateRegistrationCommand&) = delete;
	~UpdateRegistrationCommand() = default;

	Updatable* ptrUp;

	void execute();

};

#endif _UpdateRegistrationCommand
