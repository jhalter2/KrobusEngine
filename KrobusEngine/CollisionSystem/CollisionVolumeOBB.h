#ifndef _CollisionVolumeOBB
#define _CollisionVolumeOBB

#include "CollisionVolume.h"

class CollisionVolumeBSphere;
class CollisionVolumeAABB;

class CollisionVolumeOBB : public Align16, public CollisionVolume
{
public:
	CollisionVolumeOBB() = default;
	CollisionVolumeOBB(const CollisionVolumeOBB&) = delete;
	CollisionVolumeOBB& operator=(const CollisionVolumeOBB&) = delete;
	~CollisionVolumeOBB();

	void ComputeData(Model* mod, Matrix& mat, const float scale) override;
	void DebugView(const Vect& col) const override;
	bool IntersectAccept(const CollisionVolume& other) const override;
	bool IntersectVisit(const CollisionVolumeBSphere& other) const override;
	bool IntersectVisit(const CollisionVolumeAABB& other) const override;
	bool IntersectVisit(const CollisionVolumeOBB& other) const override;
	const Vect& GetCornerMax() const;
	const Vect& GetCornerMin() const;
	const Matrix& GetWorld() const;
	const Vect& GetCenterInWorld() const;
	const float GetScaleSquared() const;
	const Vect& GetHalfDiagonal() const;

private:
	Matrix world;
	Vect CornerMax;
	Vect CornerMin;
	Vect CenterInWorld;
	Vect HalfDiagonal;
	float ScaleSquared;
};

#endif _CollisionVolumeOBB
