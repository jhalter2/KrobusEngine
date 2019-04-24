#ifndef _CollisionVolumeBoundingBoxBase
#define _CollisionVolumeBoundingBoxBase

#include "CollisionVolume.h"

class CollisionVolumeBoundingBoxBase : public CollisionVolume, public Align16 {
public:
	CollisionVolumeBoundingBoxBase() = default;
	CollisionVolumeBoundingBoxBase(const CollisionVolumeBoundingBoxBase&) = delete;
	CollisionVolumeBoundingBoxBase& operator=(const CollisionVolumeBoundingBoxBase&) = delete;
	~CollisionVolumeBoundingBoxBase();

	const Vect& GetCornerMax() const;
	const Vect& GetCornerMin() const;
	const Matrix& GetWorld() const;
	const Vect& GetCenterInWorld() const;
	const float GetScaleSquared() const;
	const float GetScale() const;
	const Vect& GetHalfDiagonal() const;

protected:
	Matrix world;
	Vect CornerMax;
	Vect CornerMin;
	Vect CenterInWorld;
	Vect HalfDiagonal;
	float ScaleSquared;
	float Scale;
};

#endif _CollisionVolumeBoundingBoxBase
