#include "CollisionDeregistrationCommand.h"
#include "Collidable.h"
#include "CollidableAttorney.h"

CollisionDeregistrationCommand::CollisionDeregistrationCommand(Collidable* up) : ptrUp(up) {}

void CollisionDeregistrationCommand::execute() {
	CollidableAttorney::Registration::SceneDeregistration(ptrUp);
}
