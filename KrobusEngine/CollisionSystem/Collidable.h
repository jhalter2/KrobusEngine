#ifndef _Collidable
#define _Collidable

#include "CollisionManager.h"
#include "CollisionRegistrationCommand.h"
#include "CollisionDeregistrationCommand.h"
#include "CollidableGroup.h"
#include "SceneAttorney.h"
#include "CollisionVolumeBSphere.h"

enum class RegistrationState;

class Model;

class Collidable {
public:
	Collidable();
	Collidable(const Collidable&) = delete;
	Collidable& operator=(const Collidable&) = delete;
	virtual ~Collidable();

	virtual void Collision(Collidable*) {};

	virtual const CollisionVolumeBSphere& GetBSphere() { return BSphere; };
private:
	CollidableGroup::StorageListRef pMyDeleteRef; //iterator for quick delete
	RegistrationState RegStateCurr; //enum class for state assertions

									//create both commands to be reused
	CollisionRegistrationCommand* pRegistrationCmd;
	CollisionDeregistrationCommand* pDeregistrationCmd;

	CollisionManager::PWTypeID myID = CollisionManager::PWID_UNDEFINED;

	friend class CollidableAttorney;

	CollisionVolumeBSphere BSphere;
	Model* pColModel;

protected:
	void SceneRegistration();
	void SceneDeregistration();
	void SubmitCollisionRegistration();
	void SubmitCollisionDeregistration();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Collidable::SetColliderModel(Model*)
	///
	/// \brief	Sets collider model
	///
	/// for a game object to use collision, it needs to have a collider model set.
	/// to do this, simply pass in the model used when constructing the graphicsobject of
	/// the game object in question
	/// 
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param [in,out]	parameter1	If non-null, the first parameter.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void SetColliderModel(Model*) {};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Collidable::UpdateCollisionData(Matrix&)
	///
	/// \brief	Updates the collision data described by parameter1
	/// 		
	///if an object is going to be in motion or change at all during runtime and it needs to do
	/// collision, then UpdateCollisionData() will need to be called during the Update() step in 
	/// and the updated world matrix will need to be passed in
	/// 
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param [in,out]	parameter1	The first parameter.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void UpdateCollisionData(Matrix&) {};

	//template for collidable groupings
	template < typename C>
	void SetCollidableGroup()
	{
		myID = SceneAttorney::GetCollisionMgr()->GetTypeID<C>();
	}
};
#endif _Collidable
