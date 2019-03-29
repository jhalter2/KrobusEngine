#include "CollisionVolumeBSphere.h"
#include "PWMathTools.h"

CollisionVolumeBSphere::~CollisionVolumeBSphere() {
	DebugMsg::out("deleted BSphere\n");
}

void CollisionVolumeBSphere::ComputeData(Model* mod, Matrix& mat, const float scale) {
	//pass in model and matrix transformation and update values
	Center = mod->getCenter() * mat;
	Radius = mod->getRadius() * scale;
}

//bool CollisionVolumeBSphere::Intersect(const CollisionVolume& other) {
//
//}

bool CollisionVolumeBSphere::Intersect(const CollisionVolumeBSphere& other) {
	return PWMathTools::Intersect(*this, other);
}

const Vect& CollisionVolumeBSphere::GetCenter() const {
	return Center;
}

float CollisionVolumeBSphere::GetRadius() const {
	return Radius;
}