#ifndef _DrawDeregistrationCommand
#define _DrawDeregistrationCommand

#include "CommandBase.h"

class Drawable;

class DrawDeregistrationCommand : public CommandBase {
public:
	DrawDeregistrationCommand() = default;
	DrawDeregistrationCommand(Drawable* dr);
	DrawDeregistrationCommand(const DrawDeregistrationCommand&) = delete;
	DrawDeregistrationCommand& operator=(const DrawDeregistrationCommand&) = delete;
	~DrawDeregistrationCommand() = default;

	Drawable* ptrUp;

	void execute();

};

#endif _DrawDeregistrationCommand
