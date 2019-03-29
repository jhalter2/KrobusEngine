#ifndef _InputRegistrationCommand
#define _InputRegistrationCommand

#include "CommandBase.h"
#include "AzulCore.h"


class Inputable;
enum class EVENT_TYPE;

class InputRegistrationCommand : public CommandBase {
public:
	InputRegistrationCommand() = default;
	InputRegistrationCommand(Inputable* in, AZUL_KEY k, EVENT_TYPE e);
	InputRegistrationCommand(const InputRegistrationCommand&) = delete;
	InputRegistrationCommand& operator=(const InputRegistrationCommand&) = delete;
	~InputRegistrationCommand() = default;

	void Set(Inputable* in, AZUL_KEY k, EVENT_TYPE e);

	Inputable* ptrUp;
	AZUL_KEY key;
	EVENT_TYPE ev;
	void execute();

};

#endif _InputRegistrationCommand
