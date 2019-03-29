#include "UpdateRegistrationCommand.h"
#include "Updatable.h"
#include "UpdatableAttorney.h"

UpdateRegistrationCommand::UpdateRegistrationCommand(Updatable* up) : ptrUp(up) {}

void UpdateRegistrationCommand::execute() {
	UpdatableAttorney::Registration::SceneRegistration(ptrUp);
}