#include "CollisionTestSelfCommand.h"
#include "CollidableGroup.h"
#include "CollisionDispatchBase.h"
#include "CollisionVolumeBSphere.h"
#include "GameObject.h"
#include "PWMathTools.h"
#include "Visualizer.h"
#include "Colors.h"

CollisionTestSelfCommand::CollisionTestSelfCommand(CollidableGroup* g1, CollisionDispatchBase* pd)
	: pG1(g1), pDispatch(pd)
{ }

CollisionTestSelfCommand::~CollisionTestSelfCommand()
{
	delete pDispatch;
}

void CollisionTestSelfCommand::Execute()
{
	const CollidableGroup::CollidableCollection& Collection1 = pG1->GetColliderCollection();

	for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1)
	{
		const CollisionVolumeBSphere& bs1 = (*it1)->GetBSphere();
		for (auto it2 = ++it1; it2 != Collection1.end(); it2++)
		{
			//process collisions code if colliding = true
			const CollisionVolumeBSphere& bs2 = (*it2)->GetBSphere();

			if (PWMathTools::Intersect(bs1, bs2))
			{
				pDispatch->ProcessCallbacks(*it1, *it2);

				//Visualizer::ShowBSphere(bs1, Colors::RED);
				//Visualizer::ShowBSphere(bs2, Colors::RED);
			}
			else {
				//Visualizer::ShowBSphere(bs1, Colors::BLUE);
				//Visualizer::ShowBSphere(bs2, Colors::BLUE);
			}
		}
	}
}
