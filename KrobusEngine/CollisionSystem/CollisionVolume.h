#ifndef _CollisionVolume
#define _CollisionVolume

class Model;
class Matrix;
class Vect;
class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;

class CollisionVolume {
public:
	CollisionVolume() = default;
	CollisionVolume(const CollisionVolume&) = delete;
	CollisionVolume& operator=(const CollisionVolume&) = delete;
	virtual ~CollisionVolume() = default;

	virtual void ComputeData(Model*, Matrix&, const float scale) = 0;
	virtual void DebugView(const Vect&) const = 0;
	virtual bool IntersectAccept(const CollisionVolume& other) const = 0;
	virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const = 0;
	virtual bool IntersectVisit(const CollisionVolumeAABB& other) const = 0;
	virtual bool IntersectVisit(const CollisionVolumeOBB& other) const = 0;
};

#endif _CollisionVolume
