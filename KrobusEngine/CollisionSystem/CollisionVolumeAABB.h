#ifndef _CollisionVolumeAABB
#define _CollisionVolumeAABB

#include "CollisionVolumeBoundingBoxBase.h"

class CollisionVolumeBSphere;
class CollisionVolumeOBB;

class CollisionVolumeAABB : public CollisionVolumeBoundingBoxBase {
public:
	CollisionVolumeAABB() = default;
	CollisionVolumeAABB(const CollisionVolumeAABB&) = delete;
	CollisionVolumeAABB& operator=(const CollisionVolumeAABB&) = delete;
	~CollisionVolumeAABB() = default;

	void ComputeData(Model* mod, Matrix& mat, const float scale) override;
	void ComputeData(const CollisionVolumeBSphere& other);
	//the one below is used for terrain
	void ComputeData(Vect& max, Vect& min, Matrix& mat, const float scale);

	void DebugView(const Vect& col) const override;
	bool IntersectAccept(const CollisionVolume& other) const override;
	bool IntersectVisit(const CollisionVolumeBSphere& other) const override;
	bool IntersectVisit(const CollisionVolumeAABB& other) const override;
	bool IntersectVisit(const CollisionVolumeOBB& other) const override;
	void SetMin(const Vect& newMin);
	void SetMax(const Vect& newMax);
};

#endif _CollisionVolumeAABB
