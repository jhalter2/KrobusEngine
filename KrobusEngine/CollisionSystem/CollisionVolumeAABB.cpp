//Axis aligned bounding box (AABB) class.
//AABBs data can be computed in 3 different ways.
//A model and world matrix, an existing bsphere, or
//2 different vectors and a world matrix. Scale also
//must be input separately due to uneven scaling issues
//that can arise from inputing it with the world matrix.
//Also offers methods to change the max and the
//min of the AABB which is useful when adjusting 
//the group AABBs during pair collision testing

#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "CollisionVolumeBSphere.h"
#include "PWMathTools.h"
#include "Model.h"

void CollisionVolumeAABB::ComputeData(Model* mod, Matrix& mat, const float scale) {
	Vect newMax;
	PWMathTools::GetMaxWorldVect(mod->GetVectList(), mod->GetVectNum(), newMax);
	Vect newMin;
	PWMathTools::GetMinWorldVect(mod->GetVectList(), mod->GetVectNum(), newMin);
	CornerMax = (scale * (newMax));
	CornerMin = (scale * (newMin));
	HalfDiagonal = 0.5f * (CornerMax - CornerMin);
	CenterInWorld = (CornerMin + HalfDiagonal) * mat;
	ScaleSquared = mat.get(ROW_2).magSqr();
	world = mat;
	Scale = scale;
	CornerMax *= mat;
	CornerMin *= mat;
}

void CollisionVolumeAABB::ComputeData(const CollisionVolumeBSphere& other) {
	float r = other.GetRadius();
	CornerMax = Vect(r, r, r);
	CornerMin = Vect(-r, -r, -r);
	HalfDiagonal = 0.5f * (CornerMax - CornerMin);
	CenterInWorld = other.GetCenter();
	world = other.GetWorld();
	Scale = other.GetScale();
}

void CollisionVolumeAABB::ComputeData(Vect& max, Vect& min, Matrix& mat, const float scale) {
	CornerMax = scale * max;
	CornerMin = scale * min;
	HalfDiagonal = 0.5f * (CornerMax - CornerMin);
	CenterInWorld = (CornerMin + HalfDiagonal) * mat;
	ScaleSquared = mat.get(ROW_2).magSqr();
	world = mat;
	Scale = scale;
}

void CollisionVolumeAABB::DebugView(const Vect&) const {
	//Visualizer::ShowAABB(*this, col);
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

void CollisionVolumeAABB::SetMin(const Vect& newMin) {
	CornerMin = newMin;
}

void CollisionVolumeAABB::SetMax(const Vect& newMax) {
	CornerMax = newMax;
}
