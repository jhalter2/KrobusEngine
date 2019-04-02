#include "InputRegistrationCommand.h"
#include "Inputable.h"
#include "EVENT_TYPE.h"
#include "InputableAttorney.h"

InputRegistrationCommand::InputRegistrationCommand(Inputable* in, AZUL_KEY k, EVENT_TYPE e) : ptrUp(in), key(k), ev(e) {}

void InputRegistrationCommand::Set(Inputable* in, AZUL_KEY k, EVENT_TYPE e) 
{
	ptrUp = in;
	key = k;
	ev = e;
}

void InputRegistrationCommand::execute() 
{
	InputableAttorney::Registration::SceneRegistration(ptrUp, key, ev);
}
