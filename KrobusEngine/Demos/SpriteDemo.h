#ifndef _SpriteDemo
#define _SpriteDemo

#include "Scene.h"

class WorldPlane;
class CameraManager;
class FlyingCamera;
class Player;
class EnemyTank;
class SpriteTest;
class SpriteFontTest;

class SpriteDemo : public Scene, public Align16 {
public:
	SpriteDemo() = default;
	SpriteDemo(const SpriteDemo&) = delete;
	SpriteDemo& operator= (const SpriteDemo&) = delete;
	~SpriteDemo();

	void Initialize();
	void SceneEnd();

private:
	WorldPlane * GOPlane;
	CameraManager* Cam;
	FlyingCamera* fCam;
	Player* GOPlayer;
	SpriteTest* pSpriteTest;
	SpriteFontTest* pSFTest;
};

#endif _SpriteDemo
