#include "SceneDemo.h"
#include "Frigate.h"
#include "WorldPlane.h"
#include "AzulCore.h"
#include "KeyStateTest.h"
#include "KeyPressTester.h"
#include "CameraManager.h"
#include "FreezeTime.h"
#include "BulletFactory.h"
#include "CollisionManager.h"
#include "FlyingCamera.h"
#include "Cottage.h"

///this demo shows off the functionality of collisions and bspheres
///the frigate and cottage class have built in bspheres and submit for collisions
///see gameobject collisions for more info on how those work
///included is a flying camera currently mapped to 1,2 (left, right) and
///3,4(up, down) and up, down, left, right arrows for movement
///the flying camera allows us to move in close to the bspheres and see where
///the point of collision is calculated
///note that the collision pair <Frigate,Cottage> can detect collisions
///both ways, not just from the frigate or cottage object

SceneDemo::~SceneDemo() {
	SceneEnd();
	DebugMsg::out("scene demo deleted\n");
}

void SceneDemo::Initialize(){
	Cam = new CameraManager();
	GOFrig = new Frigate();
	GOPlane = new WorldPlane();
	fCam = new FlyingCamera();
	Vect pos = Vect(100.0f, 0.0f, -100.0f);
	pCot = new Cottage(pos);
	SetCollisionPair<Frigate, Cottage>();
}

void SceneDemo::SceneEnd() {
	delete GOFrig;
	delete GOPlane;
	BulletFactory::Terminate();
	delete Cam;
	delete fCam;
	delete pCot;
}
