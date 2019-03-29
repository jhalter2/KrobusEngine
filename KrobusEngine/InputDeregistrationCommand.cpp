#include "InputDeregistrationCommand.h"
#include "Inputable.h"
#include "EVENT_TYPE.h"
#include "InputableAttorney.h"

InputDeregistrationCommand::InputDeregistrationCommand(Inputable* in, AZUL_KEY k, EVENT_TYPE e) : ptrUp(in), key(k), ev(e) {}

void InputDeregistrationCommand::Set(Inputable* in, AZUL_KEY k, EVENT_TYPE e)
{
	ptrUp = in;
	key = k;
	ev = e;
}

void InputDeregistrationCommand::execute()
{
	InputableAttorney::Registration::SceneDeregistration(ptrUp, key, ev);
}