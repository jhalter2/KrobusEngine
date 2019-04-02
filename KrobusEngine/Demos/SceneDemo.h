#ifndef _SceneDemo
#define _SceneDemo

#include "Scene.h"

class Frigate;
class WorldPlane;
class CameraManager;
class FlyingCamera;
class Cottage;

class SceneDemo : public Scene, public Align16 {
public:
	SceneDemo() = default;
	SceneDemo(const SceneDemo&) = delete;
	SceneDemo& operator= (const SceneDemo&) = delete;
	~SceneDemo();

	void Initialize();
	void SceneEnd();

private:
	Frigate *GOFrig;
	WorldPlane *GOPlane;
	CameraManager *Cam;
	FlyingCamera *fCam;
	Cottage* pCot;
};

#endif _SceneDemo
