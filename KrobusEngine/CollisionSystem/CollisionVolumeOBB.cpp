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
	HalfDiagonal = 0.5f * (CornerMax - CornerMin);
	CenterInWorld = (CornerMin + HalfDiagonal) * mat;
	ScaleSquared = mat.get(ROW_2).magSqr();
	world = mat;
	Scale = scale;
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
