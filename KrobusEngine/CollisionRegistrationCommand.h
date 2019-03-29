#ifndef _CollisionRegistrationCommand
#define _CollisionRegistrationCommand

#include "CommandBase.h"

class Collidable;

class CollisionRegistrationCommand : public CommandBase {
public:
	CollisionRegistrationCommand() = default;
	CollisionRegistrationCommand(Collidable* up);
	CollisionRegistrationCommand(const CollisionRegistrationCommand&) = delete;
	CollisionRegistrationCommand& operator=(const CollisionRegistrationCommand&) = delete;
	~CollisionRegistrationCommand() = default;

	Collidable* ptrUp;

	void execute();

};

#endif _CollisionRegistrationCommand
