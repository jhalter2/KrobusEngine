#include "MovementDemo.h"
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

///this demo shows off movement controls and movement of game objects
///the object frigate is setup such that w will add to it's z, which pushes it forward
///s subtracts from the z which moves it backwards
///a and d affect the rotation from side to side

MovementDemo::~MovementDemo() {
	SceneEnd();
	DebugMsg::out("scene demo deleted\n");
}

void MovementDemo::Initialize() {
	Cam = new CameraManager();
	GOFrig = new Frigate();
	GOPlane = new WorldPlane();
	fCam = new FlyingCamera();
}

void MovementDemo::SceneEnd() {
	delete GOFrig;
	delete GOPlane;
	BulletFactory::Terminate();
	delete Cam;
	delete fCam;
}
