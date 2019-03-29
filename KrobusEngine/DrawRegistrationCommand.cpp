#include "DrawRegistrationCommand.h"
#include "Drawable.h"
#include "DrawableAttorney.h"

DrawRegistrationCommand::DrawRegistrationCommand(Drawable* dr) : ptrUp(dr) {}

void DrawRegistrationCommand::execute() {
	DrawableAttorney::Registration::SceneRegistration(ptrUp);
}