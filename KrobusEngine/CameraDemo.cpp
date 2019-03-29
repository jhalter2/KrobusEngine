#include "CameraDemo.h"
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

///this demo shows off the use of the camera, especially for debugging
///camera controls are up, down, left, right arrows for movement(forward, back, left, right)
///and 1,2,3,4 for rotation (left, right, up, down)

CameraDemo::~CameraDemo() {
	SceneEnd();
	DebugMsg::out("camera demo deleted\n");
}

void CameraDemo::Initialize() {
	Cam = new CameraManager();
	GOFrig = new Frigate();
	GOPlane = new WorldPlane();
	fCam = new FlyingCamera();
}

void CameraDemo::SceneEnd() {
	delete GOFrig;
	delete GOPlane;
	BulletFactory::Terminate();
	delete Cam;
	delete fCam;
}