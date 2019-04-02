#include "DrawDeregistrationCommand.h"
#include "Drawable.h"
#include "DrawableAttorney.h"

DrawDeregistrationCommand::DrawDeregistrationCommand(Drawable* dr) : ptrUp(dr) {}

void DrawDeregistrationCommand::execute() {
	DrawableAttorney::Registration::SceneDeregistration(ptrUp);
}
