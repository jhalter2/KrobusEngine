#ifndef _CollisionManager
#define _CollisionManager

#include <vector>
#include <list>
#include "CollisionDispatch.h"
#include "CollisionTestPairCommand.h"
#include "CollisionTestSelfCommand.h"

class CollisionTestCommandBase;
class CollidableGroup;

class CollisionManager {

public:
	CollisionManager();
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager& operator=(const CollisionManager&) = delete;
	~CollisionManager();

	//type definition
	using PWTypeID = int;
	static const PWTypeID PWID_UNDEFINED = -1;

	CollidableGroup* GetColGroup(PWTypeID id);

	void ProcessCollisions();
private:
	//starting id number
	PWTypeID TypeIDNextNumber = 0;

	void SetGroupForTypeID(CollisionManager::PWTypeID ind);

	//need to keep array updated based on number of object groups used
	using CollidableGroupCollection = std::vector<CollidableGroup*>;
	CollidableGroupCollection ColGroupCollection;

	using CollisionTestCommands = std::list<CollisionTestCommandBase*>;
	CollisionTestCommands colTestCommands;

public:
	//setting id for object groups
	template <typename C>
	PWTypeID GetTypeID() {
		static PWTypeID myTypeID = TypeIDNextNumber++;

		SetGroupForTypeID(myTypeID);

		DebugMsg::out("Type ID: %i\n", myTypeID);
		return myTypeID;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	template< typename C1, typename C2> void CollisionManager::SetCollisionPair()
	///
	/// \brief	adding tests to manager's collection for pairs of objects
	///
	/// in Scene::Initialize(), you'll have to designate which pairs of object types need to look out for
	/// collisions with each other. Note that this is done for types and not for specific objects
	/// 
	/// \code
	/// 
	/// void MyScene::Initialize(){
	/// //I want collisions to be detected between bullets and enemies
	/// SetCollisionPair<Bullet, Enemy>();
	/// //note that this will detect both ways, no need to also declare the inverse relationship
	/// }
	/// 
	/// \endcode
	/// 		
	/// \tparam	C1	Type of the c 1.
	/// \tparam	C2	Type of the c 2.
	////////////////////////////////////////////////////////////////////////////////////////////////////


	template< typename C1, typename C2>
	void SetCollisionPair()
	{
		CollidableGroup* pg1 = ColGroupCollection[GetTypeID<C1>()];
		CollidableGroup* pg2 = ColGroupCollection[GetTypeID<C2>()];

		CollisionDispatch<C1, C2>* pDispatch = new CollisionDispatch<C1, C2>();

		colTestCommands.push_back(new CollisionTestPairCommand(pg1, pg2, pDispatch));
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	template< typename C3> void CollisionManager::SetCollisionSelf()
	///
	/// \brief	adding tests to manager's collection for self object checks
	///
	///  in Scene::Initialize(), you'll have to designate which pairs of object types need to look out for
	/// collisions with each other. Note that this is done for types and not for specific objects
	///
	/// \code
	///
	/// void MyScene::Initialize(){
	/// //I want collisions to be detected between enemies
	/// SetCollisionSelf<Enemy>();
	/// }
	///
	/// \endcode
	///
	/// \tparam	C3	Type of the c 3.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	template< typename C3>
	void SetCollisionSelf()
	{
		CollidableGroup* pg3 = ColGroupCollection[GetTypeID<C3>()];

		CollisionDispatch<C3, C3>* pDispatch = new CollisionDispatch<C3, C3>();

		colTestCommands.push_back(new CollisionTestSelfCommand(pg3, pDispatch));
	}
};

#endif _CollisionManager
