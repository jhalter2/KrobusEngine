#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "PWMathTools.h"
#include "Visualizer.h"

CollisionVolumeBSphere::~CollisionVolumeBSphere() {
	DebugMsg::out("deleted BSphere\n");
}

void CollisionVolumeBSphere::ComputeData(Model* mod, Matrix& mat, const float scale) {
	//pass in model and matrix transformation and update values
	Center = mod->getCenter() * mat;
	Radius = mod->getRadius() * scale;
}

void CollisionVolumeBSphere::DebugView(const Vect& col) const {
	Visualizer::ShowBSphere(*this, col);
}

bool CollisionVolumeBSphere::IntersectAccept(const CollisionVolume& other) const {
	return other.IntersectVisit(*this);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeBSphere& other) const {
	return PWMathTools::Intersect(*this, other);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeAABB& other) const {
	return PWMathTools::Intersect(*this, other);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeOBB& other) const {
	return PWMathTools::Intersect(*this, other);
}

const Vect& CollisionVolumeBSphere::GetCenter() const {
	return Center;
}

float CollisionVolumeBSphere::GetRadius() const {
	return Radius;
}
