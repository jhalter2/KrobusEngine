#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "CollisionVolumeBSphere.h"
#include "PWMathTools.h"
#include "Visualizer.h"

CollisionVolumeOBB::~CollisionVolumeOBB() {
	DebugMsg::out("collision volume obb deleted");
}

void CollisionVolumeOBB::ComputeData(Model* mod, Matrix& mat, const float scale) {
	CornerMax = (scale * (mod->getMaxAABB()));
	CornerMin = (scale * (mod->getMinAABB()));
	HalfDiagonal = 0.5f * (mod->getMaxAABB() - mod->getMinAABB());
	CenterInWorld = (mod->getMaxAABB() + HalfDiagonal) * mat;
	ScaleSquared = scale * scale;
	world = mat;
}

void CollisionVolumeOBB::DebugView(const Vect& col) const {
	Visualizer::ShowOBB(*this, col);
}

bool CollisionVolumeOBB::IntersectAccept(const CollisionVolume& other) const {
	return other.IntersectVisit(*this);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeBSphere& other) const {
	return PWMathTools::Intersect(*this, other);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeAABB& other) const {
	return PWMathTools::Intersect(*this, other);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeOBB& other) const {
	return PWMathTools::Intersect(*this, other);
}

const Vect& CollisionVolumeOBB::GetCornerMax() const {
	return CornerMax;
}

const Vect& CollisionVolumeOBB::GetCornerMin() const {
	return CornerMin;
}

const Matrix& CollisionVolumeOBB::GetWorld() const {
	return world;
}

const Vect& CollisionVolumeOBB::GetCenterInWorld() const {
	return CenterInWorld;
}

const float CollisionVolumeOBB::GetScaleSquared() const {
	return ScaleSquared;
}

const Vect& CollisionVolumeOBB::GetHalfDiagonal() const {
	return HalfDiagonal;
}
