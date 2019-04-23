#ifndef _CollisionVolumeAABB
#define _CollisionVolumeAABB

#include "CollisionVolume.h"

class CollisionVolumeBSphere;
class CollisionVolumeOBB;

class CollisionVolumeAABB : public CollisionVolume, public Align16 {
public:
	CollisionVolumeAABB() = default;
	CollisionVolumeAABB(const CollisionVolumeAABB&) = delete;
	CollisionVolumeAABB& operator=(const CollisionVolumeAABB&) = delete;
	~CollisionVolumeAABB();

	void ComputeData(Model* mod, Matrix& mat, const float scale) override;
	void DebugView(const Vect& col) const override;
	bool IntersectAccept(const CollisionVolume& other) const override;
	bool IntersectVisit(const CollisionVolumeBSphere& other) const override;
	bool IntersectVisit(const CollisionVolumeAABB& other) const override;
	bool IntersectVisit(const CollisionVolumeOBB& other) const override;
	const Vect& GetCornerMax() const;
	const Vect& GetCornerMin() const;

private:
	Vect CornerMax;
	Vect CornerMin;
};

#endif _CollisionVolumeAABB
