#ifndef _CollisionDeregistrationCommand
#define _CollisionDeregistrationCommand

#include "CommandBase.h"

class Collidable;

class CollisionDeregistrationCommand : public CommandBase {
public:
	CollisionDeregistrationCommand() = default;
	CollisionDeregistrationCommand(Collidable* up);
	CollisionDeregistrationCommand(const CollisionDeregistrationCommand&) = delete;
	CollisionDeregistrationCommand& operator=(const CollisionDeregistrationCommand&) = delete;
	~CollisionDeregistrationCommand() = default;

	Collidable* ptrUp;

	void execute();
};
#endif _CollisionDeregistrationCommand
