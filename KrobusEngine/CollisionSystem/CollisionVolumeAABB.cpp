#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "CollisionVolumeBSphere.h"
#include "PWMathTools.h"
#include "Visualizer.h"

CollisionVolumeAABB::~CollisionVolumeAABB() {
	DebugMsg::out("deleted AABB\n");
}

void CollisionVolumeAABB::ComputeData(Model* mod, Matrix& mat, const float scale) {
	Vect newMax;
	PWMathTools::GetMaxWorldVect(mod->getVectList(), mod->getVectNum(), newMax);
	Vect newMin;
	PWMathTools::GetMinWorldVect(mod->getVectList(), mod->getVectNum(), newMin);
	CornerMax = (scale * (newMax)) * mat;
	CornerMin = (scale * (newMin)) * mat;
}

void CollisionVolumeAABB::DebugView(const Vect& col) const {
	Visualizer::ShowAABB(*this, col);
}

bool CollisionVolumeAABB::IntersectAccept(const CollisionVolume& other) const {
	return other.IntersectVisit(*this);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeBSphere& other) const {
	return PWMathTools::Intersect(*this, other);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeAABB& other) const {
	return PWMathTools::Intersect(*this, other);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeOBB& other) const {
	return PWMathTools::Intersect(*this, other);
}

const Vect& CollisionVolumeAABB::GetCornerMax() const {
	return CornerMax;
}

const Vect& CollisionVolumeAABB::GetCornerMin() const {
	return CornerMin;
}
