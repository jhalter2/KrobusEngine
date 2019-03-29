#ifndef _CameraDemo
#define _CameraDemo

#include "Scene.h"

class Frigate;
class WorldPlane;
class CameraManager;
class FlyingCamera;

class CameraDemo : public Scene, public Align16 {
public:
	CameraDemo() = default;
	CameraDemo(const CameraDemo&) = delete;
	CameraDemo& operator= (const CameraDemo&) = delete;
	~CameraDemo();

	void Initialize();
	void SceneEnd();

private:
	Frigate * GOFrig;
	WorldPlane *GOPlane;
	CameraManager *Cam;
	FlyingCamera *fCam;
};

#endif _CameraDemo

