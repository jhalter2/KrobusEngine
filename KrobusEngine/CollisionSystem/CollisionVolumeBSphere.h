#ifndef _CollisionVolumeBSphere
#define _CollisionVolumeBSphere
#include "CollisionVolume.h"

class CollisionVolumeAABB;
class CollisionVolumeOBB;

class CollisionVolumeBSphere : public CollisionVolume, public Align16 {
public:
	CollisionVolumeBSphere() = default;
	CollisionVolumeBSphere(const CollisionVolumeBSphere&) = delete;
	CollisionVolumeBSphere& operator=(const CollisionVolumeBSphere&) = delete;
	~CollisionVolumeBSphere();

	void ComputeData(Model* mod, Matrix& mat, const float scale) override;
	void DebugView(const Vect& col) const override;
	bool IntersectAccept(const CollisionVolume& other) const override;
	bool IntersectVisit(const CollisionVolumeBSphere& other) const override;
	bool IntersectVisit(const CollisionVolumeAABB& other) const override;
	bool IntersectVisit(const CollisionVolumeOBB& other) const override;
	const Vect& GetCenter() const;
	float GetRadius() const;

private:
	Vect Center;
	float Radius;
};

#endif _CollisionVolumeBSphere
