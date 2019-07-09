#include "SpriteDemo.h"
#include "CameraManager.h"
#include "BulletFactory.h"
#include "CollisionManager.h"
#include "FlyingCamera.h"
#include "Player.h"
#include "KrobusSprite.h"
#include "SpriteTest.h"

SpriteDemo::~SpriteDemo() {
	SceneEnd();
	DebugMsg::out("tank demo start deleted\n");
}

void SpriteDemo::Initialize() {
	Cam = new CameraManager();
	pSpriteTest = new SpriteTest();
	GOPlayer = new Player();
	GOPlane = new WorldPlane();
	fCam = new FlyingCamera();
}

void SpriteDemo::SceneEnd() {
	delete GOPlane;
	BulletFactory::Terminate();
	delete Cam;
	delete fCam;
	delete GOPlayer;
	delete pSpriteTest;
}
