#include "CollisionRegistrationCommand.h"
#include "Collidable.h"
#include "CollidableAttorney.h"

CollisionRegistrationCommand::CollisionRegistrationCommand(Collidable* up) : ptrUp(up) {}

void CollisionRegistrationCommand::execute() {
	CollidableAttorney::Registration::SceneRegistration(ptrUp);
}