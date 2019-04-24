#ifndef _PWMathTools
#define _PWMathTools

#include "CollisionVolume.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include <cmath>
#include <cfloat>

class PWMathTools {
	//static class for housing math functions
public:
	static bool Intersect(const CollisionVolume& A, const CollisionVolume& B) {
		return A.IntersectAccept(B);
	}

	static bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeBSphere& B) {
		//test collision between 2 bspheres
		//radius of the two bspheres
		float r1 = A.GetRadius() + B.GetRadius();
		//distance between two centers(vectors)
		Vect v1(A.GetCenter().X(), A.GetCenter().Y(), A.GetCenter().Z());
		Vect v2(B.GetCenter().X(), B.GetCenter().Y(), B.GetCenter().Z());
		float r2 = (v2 - v1).mag();
		//compare it to the sum of radii 
		return (r1 >= r2);
	}

	static bool Intersect(const CollisionVolumeAABB& A, const CollisionVolumeAABB& B) {
		//test collisions between 2 aabb
		//test the intervals to see if they do not overlap, otherwise return true
		if (!IntervalOverlap(A.GetCornerMin(), A.GetCornerMax(), B.GetCornerMin(), B.GetCornerMax())) return false;
		else return true;
	}

	static bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeAABB& B) {
		//test collisions between bsphere and aabb
		//clamp bsphere center to aabb min/max then test if point falls inside
		Vect clampedCenter; 
		ClampVectToMinMax(A.GetCenter(), B.GetCornerMin(), B.GetCornerMax(), clampedCenter);
		return PointInBSphere(clampedCenter, A);
	}

	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeBSphere& B) {
		//test collisions between obb and bsphere
		//start with obb world inverse
		Matrix inverseWorldOBB = A.GetWorld().getInv();
		//compute bsphere center in local space
		Vect newBSphereCenter = B.GetCenter() * inverseWorldOBB;
		//clamp the new center along the obb axes
		Vect newClampedCenter;
		ClampVectToMinMax(newBSphereCenter, A.GetCornerMin(), A.GetCornerMax(), newClampedCenter);
		//compute clamped center into the original world space
		Vect newPoint = newClampedCenter * A.GetWorld();
		//test if new point is inside the original bsphere
		return PointInBSphere(newPoint, B);
	}

	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeAABB& B) {
		//collision detection between obb and obb
		//using satisfying axis theorem 
		//need to check overlap on 15 total axes
		//get face normals for each obb = 6 more axes
		Vect axes[15];
		SATVects(A.GetWorld(), B.GetWorld(), axes);

		//cross products of the 3x3 face normals = 9 more axes
		Get9AxesCrossProducts(axes);

		//test overlaps for every axis
		for (int i = 0; i < 15; i++) {
			if (axes[i].magSqr() > FLT_EPSILON) {
				if (!OBBOverlapAxis(A, B, axes[i]))
					return false;
			}
		}

		return true;
	}

	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeOBB& B) {
		//collision detection between obb and obb
		//using satisfying axis theorem 
		//need to check overlap on 15 total axes
		//get face normals for each obb = 6 more axes
		Vect axes [15];
		SATVects(A.GetWorld(), B.GetWorld(), axes);

		//cross products of the 3x3 face normals = 9 more axes
		Get9AxesCrossProducts(axes);

		//test overlaps for every axis
		for (int i = 0; i < 15; i++) {
			if (axes[i].magSqr() > FLT_EPSILON) {
				if (!OBBOverlapAxis(A, B, axes[i]))
					return false;
			}
		}

		return true;
	}

	static bool OBBOverlapAxis(const CollisionVolumeOBB& ob1, const CollisionVolumeOBB& ob2, const Vect& v) {
		//test if obb1 and obb2 overlap along axis v
		//float D = (abs(((ob2.GetCenterInWorld() * ob2.GetWorld()) - (ob1.GetCenterInWorld() * ob1.GetWorld())).dot(v))) / v.mag();
		float D = (abs((ob2.GetCenterInWorld() - ob1.GetCenterInWorld()).dot(v)))/v.mag();
		float p1 = OBBMaxProjection(ob1, v);
		float p2 = OBBMaxProjection(ob2, v);
		return (D <= (p1 + p2));
	}

	static float OBBMaxProjection(const CollisionVolumeOBB& ob, const Vect& v) {
		//get obb projection length on axis v
		Vect localV = v * ob.GetWorld().getInv();
		Vect d = ob.GetHalfDiagonal();
		float xPrime = abs(localV.X() * d.X());
		float yPrime = abs(localV.Y() * d.Y());
		float zPrime = abs(localV.Z() * d.Z());
		float projMax =  (xPrime + yPrime + zPrime) / localV.mag();
		return ob.GetScaleSquared() * projMax;
	}

	static bool OBBOverlapAxis(const CollisionVolumeOBB& ob1, const CollisionVolumeAABB& ob2, const Vect& v) {
		//test if obb1 and obb2 overlap along axis v
		//float D = (abs(((ob2.GetCenterInWorld() * ob2.GetWorld()) - (ob1.GetCenterInWorld() * ob1.GetWorld())).dot(v))) / v.mag();
		float D = (abs((ob2.GetCenterInWorld() - ob1.GetCenterInWorld()).dot(v))) / v.mag();
		float p1 = OBBMaxProjection(ob1, v);
		float p2 = OBBMaxProjection(ob2, v);
		return (D <= (p1 + p2));
	}

	static float OBBMaxProjection(const CollisionVolumeAABB& ob, const Vect& v) {
		//get obb projection length on axis v
		Vect localV = v * ob.GetWorld().getInv();
		Vect d = ob.GetHalfDiagonal();
		float xPrime = abs(localV.X() * d.X());
		float yPrime = abs(localV.Y() * d.Y());
		float zPrime = abs(localV.Z() * d.Z());
		float projMax = (xPrime + yPrime + zPrime) / localV.mag();
		return ob.GetScaleSquared() * projMax;
	}

	static void SATVects(const Matrix& w1, const Matrix& w2, Vect (&axes)[15]) {
		//get face normals for each obb = 6 more axes
		//use with obb collision
		//need to manually set each so w doesn't change to 0
		axes[0].set(w1.get(ROW_0));
		axes[1].set(w1.get(ROW_1));
		axes[2].set(w1.get(ROW_2));
		
		axes[3].set(w2.get(ROW_0));
		axes[4].set(w2.get(ROW_1));
		axes[5].set(w2.get(ROW_2));
	}

	static void Get9AxesCrossProducts(Vect (&axes)[15]) {
		//cross products of the 3x3 face normals = 9 more axes
		//use with obb collision
		//need to always zero out W value when doing cross product
		axes[6].set(axes[0].cross(axes[3]));
		axes[6].W() = 0;
		axes[7].set(axes[0].cross(axes[4]));
		axes[7].W() = 0;
		axes[8].set(axes[0].cross(axes[5]));
		axes[8].W() = 0;
		
		axes[9].set(axes[1].cross(axes[3]));
		axes[9].W() = 0;
		axes[10].set(axes[1].cross(axes[4]));
		axes[10].W() = 0;
		axes[11].set(axes[1].cross(axes[5]));
		axes[11].W() = 0;

		axes[12].set(axes[2].cross(axes[3]));
		axes[12].W() = 0;
		axes[13].set(axes[2].cross(axes[4]));
		axes[13].W() = 0;
		axes[14].set(axes[2].cross(axes[5]));
		axes[14].W() = 0;
	}

	static void VectorProjection(const Vect& v1, const Vect& v2, Vect& projVect) {
		//projection of v1 along v2
		float top = v1.dot(v2);
		float bottom = v2.dot(v2);
		projVect.set((top / bottom) * v2);
	}

	static float GetDotProductIdentity(const Vect& v1, const Vect& v2, const float& theta) {
		//get dot product by identity
		return v1.mag() * v2.mag() * cosf(theta);
	}

	static bool PointInBox(const Vect& point, const CollisionVolumeOBB& obb) {
		//test if a point is inside the radius of a box
		Matrix inverseWorldOBB = obb.GetWorld().getInv();
		Vect localPoint = point * inverseWorldOBB;
	}

	static bool PointInBSphere(const Vect& point, const CollisionVolumeBSphere& bsphere) {
		//test if a point is inside the radius of a bsphere
		Vect radVect = point - bsphere.GetCenter();
		float length = (radVect.mag());
		return (length <= bsphere.GetRadius());
	}

	static void ClampVectToMinMax(const Vect& center, const Vect& min, const Vect& max, Vect& newVect) {
		//clamp vect center to the constraints of min or max 
		float clampX = center.X(), clampY = center.Y(), clampZ = center.Z();

		if (clampX < min.X()) clampX = min.X();
		else if (clampX > max.X()) clampX = max.X();

		if (clampY < min.Y()) clampY = min.Y();
		else if (clampY > max.Y()) clampY = max.Y();

		if (clampZ < min.Z()) clampZ = min.Z();
		else if (clampZ > max.Z()) clampZ = max.Z();

		newVect.set(clampX, clampY, clampZ);
	}

	static bool PointInInterval(const Vect& p, const Vect& max, const Vect& min) {
		//see if point p is within the intervals
		if (p.X() < min.X() || p.X() > max.X()) return false;
		else if (p.Y() < min.Y() || p.Y() > max.Y()) return false;
		else if (p.Z() < min.Z() || p.Z() > max.Z()) return false;
		return true;
	}

	static bool IntervalOverlap(const Vect& v1, const Vect& v2, const Vect& w1, const Vect& w2) {
		//check if the intervals of two sets of vects overlap
		if (v2.X() < w1.X() || w2.X() < v1.X()) return false;
		else if (v2.Y() < w1.Y() || w2.Y() < v1.Y()) return false;
		else if (v2.Z() < w1.Z() || w2.Z() < v1.Z()) return false;
		return true;
	}

	static void GetMaxWorldVect(Vect vects[], int count, Vect& newVect) {
		//return maximum vect from array of vects
		Vect maxV = vects[0];
		float maxX = vects[0].X(), maxY = vects[0].Y(), maxZ = vects[0].Z();
		for (int i = 1; i < count; i++) {
			if (vects[i].X() > maxX) maxX = vects[i].X();
			if (vects[i].Y() > maxY) maxY = vects[i].Y();
			if (vects[i].Z() > maxZ) maxZ = vects[i].Z();
		}
		newVect.set(maxX, maxY, maxZ);
	}

	static void GetMinWorldVect(Vect vects[], int count, Vect& newVect) {
		//return minimum vect from array of vects
		Vect minV = vects[0];
		float minX = vects[0].X(), minY = vects[0].Y(), minZ = vects[0].Z();
		for (int i = 1; i < count; i++) {
			if (vects[i].X() < minX) minX = vects[i].X();
			if (vects[i].Y() < minY) minY = vects[i].Y();
			if (vects[i].Z() < minZ) minZ = vects[i].Z();
		}
		newVect.set(minX, minY, minZ);
	}
};

#endif _PWMathTools
