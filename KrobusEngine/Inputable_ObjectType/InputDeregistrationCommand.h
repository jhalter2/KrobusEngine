#ifndef _InputDeregistrationCommand
#define _InputDeregistrationCommand

#include "CommandBase.h"
#include "AzulCore.h"


class Inputable;
enum class EVENT_TYPE;

class InputDeregistrationCommand : public CommandBase {
public:
	InputDeregistrationCommand() = default;
	InputDeregistrationCommand(Inputable* in, AZUL_KEY k, EVENT_TYPE e);
	InputDeregistrationCommand(const InputDeregistrationCommand&) = delete;
	InputDeregistrationCommand& operator= (const InputDeregistrationCommand&) = delete;
	~InputDeregistrationCommand() = default;

	void Set(Inputable* in, AZUL_KEY k, EVENT_TYPE e);

	Inputable* ptrUp;
	AZUL_KEY key;
	EVENT_TYPE ev;
	void execute();

};

#endif _InputDeregistrationCommand
