#include "Collidable.h"
#include "SceneManager.h"
#include "Scene.h"
#include "RegistrationState.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeOBB.h"

Collidable::Collidable() {
	RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;
	pRegistrationCmd = new CollisionRegistrationCommand(this);
	pDeregistrationCmd = new CollisionDeregistrationCommand(this);
}

Collidable::~Collidable() {
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
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

const CollisionVolume& Collidable::GetCollisionVolume() {
	return *ColVolume;
}

void Collidable::SetColliderModel(Model* m , COLLISION_VOLUMES c) {
	int i = (int)c;
	pColModel = m;
	if (i == 0)  ColVolume = new CollisionVolumeBSphere();
	else if (i == 1) ColVolume = new CollisionVolumeAABB();
	else ColVolume = new CollisionVolumeOBB();
}

void Collidable::UpdateCollisionData(Matrix& t, const float scale) {
	ColVolume->ComputeData(pColModel, t, scale);
}
