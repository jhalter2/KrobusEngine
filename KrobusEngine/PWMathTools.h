#ifndef _PWMathTools
#define _PWMathTools

#include "CollisionVolumeBSphere.h"
#include "AzulCore.h"

class PWMathTools {
public:
	static bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeBSphere& B) {
		//radius of the two bspheres
		float r1 = A.GetRadius() + B.GetRadius();
		//distance between two centers(vectors)
		Vect v1(A.GetCenter().X(), A.GetCenter().Y(), A.GetCenter().Z());
		Vect v2(B.GetCenter().X(), B.GetCenter().Y(), B.GetCenter().Z());
		//compare it to the sum of radii 
		return (r1 >= (v2 - v1).mag());
	}
};

#endif _PWMathTools