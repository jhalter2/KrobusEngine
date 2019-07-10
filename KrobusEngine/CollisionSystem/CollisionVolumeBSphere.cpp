//Bounding sphere (bsphere) collision volume.
//bpheres can be constructed from other bspheres
//the only necessary way to compute data from a bsphere
//is to base it off of a model, a world matrix, and a scale
//factor of that model which is not part of the world matrix.

#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "PWMathTools.h"
#include "Visualizer.h"

CollisionVolumeBSphere::CollisionVolumeBSphere(const CollisionVolumeBSphere& other) {
	Center = other.GetCenter();
	Radius = other.GetRadius();
	world = other.GetWorld();
	Scale = other.GetScale();
	CornerMax = Vect(Radius, Radius, Radius);
	CornerMin = Vect(-Radius, -Radius, -Radius);
}

CollisionVolumeBSphere& CollisionVolumeBSphere::operator=(const CollisionVolumeBSphere& other) {
	Center = other.GetCenter();
	Radius = other.GetRadius();
	world = other.GetWorld();
	Scale = other.GetScale();
	CornerMax = Vect(Radius, Radius, Radius);
	CornerMin = Vect(-Radius, -Radius, -Radius);
	return *this;
}

void CollisionVolumeBSphere::ComputeData(Model* mod, Matrix& mat, const float scale) {
	//pass in model and matrix transformation and update values
	Center = mod->GetCenter() * mat;
	Radius = mod->GetRadius() * scale;
	world = mat;
	Scale = scale;
	CornerMax = Vect(Radius, Radius, Radius);
	CornerMin = Vect(-Radius, -Radius, -Radius);
}

void CollisionVolumeBSphere::DebugView(const Vect&) const {
	//Visualizer::ShowBSphere(*this, col);
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

const Matrix& CollisionVolumeBSphere::GetWorld() const {
	return world;
}

const Vect& CollisionVolumeBSphere::GetCenter() const {
	return Center;
}

const Vect& CollisionVolumeBSphere::GetMin() const {
	return CornerMin;
}

const Vect& CollisionVolumeBSphere::GetMax() const {
	return CornerMax;
}

float CollisionVolumeBSphere::GetRadius() const {
	return Radius;
}

float CollisionVolumeBSphere::GetScale() const {
	return Scale;
}
