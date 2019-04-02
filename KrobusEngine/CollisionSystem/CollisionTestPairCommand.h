#ifndef _CollisionTestPairCommand
#define _CollisionTestPairCommand

#include "CollisionTestCommandBase.h"

class CollidableGroup;
class CollisionDispatchBase;

class CollisionTestPairCommand: public CollisionTestCommandBase {

public:
	CollisionTestPairCommand() = delete;;
	CollisionTestPairCommand(CollidableGroup* g1, CollidableGroup* g2, CollisionDispatchBase* pd);
	CollisionTestPairCommand(const CollisionTestPairCommand&) = delete;
	CollisionTestPairCommand& operator=(const CollisionTestPairCommand&) = delete;
	~CollisionTestPairCommand();

	void Execute();
private:
	CollisionDispatchBase* pDispatch;
	CollidableGroup* pG1;
	CollidableGroup* pG2;
};

#endif _CollisionTestPairCommand
