#ifndef _CollisionVolumeBSphere
#define _CollisionVolumeBSphere

#include "AzulCore.h"
#include "CollisionVolume.h"

class CollisionVolumeBSphere : public CollisionVolume, public Align16 {
public:
	CollisionVolumeBSphere() = default;
	CollisionVolumeBSphere(const CollisionVolumeBSphere&) = delete;
	CollisionVolumeBSphere& operator=(const CollisionVolumeBSphere&) = delete;
	~CollisionVolumeBSphere();

	void ComputeData(Model* mod, Matrix& mat, const float scale);
	//bool Intersect(const CollisionVolume& other);
	bool Intersect(const CollisionVolumeBSphere& other);
	const Vect& GetCenter() const;
	float GetRadius() const;

private:
	Vect Center;
	float Radius;
};

#endif _CollisionVolumeBSphere
