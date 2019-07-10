//base class which GameObject class derives from.
//collidable is the class which allows GameObjects
//to register for the collision system.
//Methods are included for the user to set the CollisionModel
//that will be used for the object based on the 3 types
//of collision model available - 
//bounding sphere, object oriented bounding box,
//and axis aligned bounding box
//
//NOTE: all collidables have a default bounding sphere
//that is in addition to their user chosen collision volume.
//this bounding sphere is for optimization of collision 
//calculations between groups of same-type objects

#include "Collidable.h"
#include "SceneManager.h"
#include "Scene.h"
#include "RegistrationState.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeOBB.h"
#include <assert.h>

Collidable::Collidable() {
	RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
	pRegistrationCmd = new CollisionRegistrationCommand(this);
	pDeregistrationCmd = new CollisionDeregistrationCommand(this);
	ColVolume = new CollisionVolumeBSphere();
	pColBSphere = new CollisionVolumeBSphere();
}

Collidable::~Collidable() {
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
	delete ColVolume;
	delete pColBSphere;
}

void Collidable::SceneRegistration() {
	assert(RegStateCurr == RegistrationState::PENDING_REGISTRATION);
	pMyDeleteRef = SceneAttorney::GetCollisionMgr()->GetColGroup(myID)->Register(this);
	RegStateCurr = RegistrationState::CURRENTLY_REGISTERED;
}

void Collidable::SceneDeregistration() {
	assert(RegStateCurr == RegistrationState::PENDING_DEREGISTRATION);
	SceneAttorney::GetCollisionMgr()->GetColGroup(myID)->Deregister(pMyDeleteRef);
	RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Collidable::SubmitCollisionRegistration() {
	assert(RegStateCurr == RegistrationState::CURRENTLY_DEREGISTERED);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), pRegistrationCmd);
	RegStateCurr = RegistrationState::PENDING_REGISTRATION;
}

void Collidable::SubmitCollisionDeregistration() {
	assert(RegStateCurr == RegistrationState::CURRENTLY_REGISTERED);
	SceneAttorney::SubmitCommand(SceneManager::GetCurrentScene(), pDeregistrationCmd);
	RegStateCurr = RegistrationState::PENDING_DEREGISTRATION;
}

//used by many internal methods during collision calculation
const CollisionVolume& Collidable::GetCollisionVolume() {
	return *ColVolume;
}

//gets the default bsphere of an object
const CollisionVolumeBSphere& Collidable::GetBSphere() {
	return *pColBSphere;
}

//user can set the CollisionVolume that will be used for a
//specific object
void Collidable::SetColliderModel(Model* m , COLLISION_VOLUMES c) {
	delete ColVolume;
	int i = (int)c;
	pColModel = m;
	if (i == 0)  ColVolume = new CollisionVolumeBSphere();
	else if (i == 1) ColVolume = new CollisionVolumeAABB();
	else ColVolume = new CollisionVolumeOBB();
}

//called by backend update to keep collision info
//updated
void Collidable::UpdateCollisionData(Matrix& t, const float scale) {
	ColVolume->ComputeData(pColModel, t, scale);
	pColBSphere->ComputeData(pColModel, t, scale);
}
