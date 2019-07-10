#ifndef _CollisionVolumeOBB
#define _CollisionVolumeOBB

#include "CollisionVolumeBoundingBoxBase.h"

class CollisionVolumeBSphere;
class CollisionVolumeAABB;

class CollisionVolumeOBB : public CollisionVolumeBoundingBoxBase {
public:
	CollisionVolumeOBB() = default;
	CollisionVolumeOBB(const CollisionVolumeOBB&) = delete;
	CollisionVolumeOBB& operator=(const CollisionVolumeOBB&) = delete;
	~CollisionVolumeOBB() = default;

	void ComputeData(Model* mod, Matrix& mat, const float scale) override;
	void DebugView(const Vect& col) const override;
	bool IntersectAccept(const CollisionVolume& other) const override;
	bool IntersectVisit(const CollisionVolumeBSphere& other) const override;
	bool IntersectVisit(const CollisionVolumeAABB& other) const override;
	bool IntersectVisit(const CollisionVolumeOBB& other) const override;
};

#endif _CollisionVolumeOBB
