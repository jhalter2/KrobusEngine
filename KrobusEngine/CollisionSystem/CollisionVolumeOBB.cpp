//collision volume oriented bounding box (OBB)
//OBBs are only used when the user specifically selects
//them while looking for a certain level of collision
//precision. This means that they never need to be 
//specially constructed, and only need their data
//to be computed based on a model, world matrix, 
//and a scale factor

#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "CollisionVolumeBSphere.h"
#include "PWMathTools.h"
#include "Visualizer.h"

void CollisionVolumeOBB::ComputeData(Model* mod, Matrix& mat, const float scale) {
	CornerMax = (scale * (mod->GetMaxAABB()));
	CornerMin = (scale * (mod->GetMinAABB()));
	HalfDiagonal = 0.5f * (CornerMax - CornerMin);
	CenterInWorld = (CornerMin + HalfDiagonal) * mat;
	ScaleSquared = mat.get(ROW_2).magSqr();
	world = mat;
	Scale = scale;
}

void CollisionVolumeOBB::DebugView(const Vect&) const {
	//Visualizer::ShowOBB(*this, col);
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
