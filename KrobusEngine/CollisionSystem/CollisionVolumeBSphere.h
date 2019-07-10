#ifndef _CollisionVolumeBSphere
#define _CollisionVolumeBSphere

#include "CollisionVolume.h"

class CollisionVolumeAABB;
class CollisionVolumeOBB;

class CollisionVolumeBSphere : public CollisionVolume {
public:
	CollisionVolumeBSphere() = default;
	CollisionVolumeBSphere(const CollisionVolumeBSphere& other);
	CollisionVolumeBSphere& operator=(const CollisionVolumeBSphere& other);
	~CollisionVolumeBSphere() = default;

	void ComputeData(Model* mod, Matrix& mat, const float scale) override;
	void DebugView(const Vect& col) const override;
	bool IntersectAccept(const CollisionVolume& other) const override;
	bool IntersectVisit(const CollisionVolumeBSphere& other) const override;
	bool IntersectVisit(const CollisionVolumeAABB& other) const override;
	bool IntersectVisit(const CollisionVolumeOBB& other) const override;
	const Matrix& GetWorld() const;
	const Vect& GetCenter() const;
	const Vect& GetMin() const;
	const Vect& GetMax() const;
	float GetRadius() const;
	float GetScale() const;

private:
	Matrix world;
	Vect Center;
	Vect CornerMax;
	Vect CornerMin;
	float Radius;
	float Scale;
};

#endif _CollisionVolumeBSphere
