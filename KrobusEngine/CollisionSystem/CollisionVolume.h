#ifndef _CollisionVolume
#define _CollisionVolume

class Model;
class Matrix;
class CollisionVolumeBSphere;

class CollisionVolume {
public:
	CollisionVolume() {};
	CollisionVolume(const CollisionVolume&) = delete;
	CollisionVolume& operator=(const CollisionVolume&) = delete;
	virtual ~CollisionVolume() {};

	virtual void ComputeData(Model*, Matrix&) {};
	virtual bool Intersect(const CollisionVolume&) { return false;  };
	virtual bool Intersect(const CollisionVolumeBSphere&) { return false;  };
};

#endif _CollisionVolume
