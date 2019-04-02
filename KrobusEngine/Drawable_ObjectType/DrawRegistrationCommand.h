#ifndef _DrawRegistrationCommand
#define _DrawRegistrationCommand

#include "CommandBase.h"

class Drawable;

class DrawRegistrationCommand : public CommandBase {
public:
	DrawRegistrationCommand() = default;
	DrawRegistrationCommand(Drawable* dr);
	DrawRegistrationCommand(const DrawRegistrationCommand&) = delete;
	DrawRegistrationCommand& operator=(const DrawRegistrationCommand&) = delete;
	~DrawRegistrationCommand() = default;

	Drawable* ptrUp;

	void execute();

};

#endif _DrawRegistrationCommand
