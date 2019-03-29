#ifndef _MovementDemo
#define _MovementDemo

#include "Scene.h"

class Frigate;
class WorldPlane;
class CameraManager;
class FlyingCamera;

class MovementDemo : public Scene, public Align16 {
public:
	MovementDemo() = default;
	MovementDemo(const MovementDemo&) = delete;
	MovementDemo& operator= (const MovementDemo&) = delete;
	~MovementDemo();

	void Initialize();
	void SceneEnd();

private:
	Frigate * GOFrig;
	WorldPlane *GOPlane;
	CameraManager *Cam;
	FlyingCamera *fCam;
};

#endif _MovementDemo

