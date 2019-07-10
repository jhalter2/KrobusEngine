#ifndef _CameraManager
#define _CameraManager

#include "Align16.h"

class Camera;
class GameObject;

class CameraManager : public Align16 {

public:
	CameraManager();
	CameraManager(const CameraManager&) = delete;
	CameraManager& operator=(const CameraManager&) = delete;
	~CameraManager();

	Camera* GetCurrentCamera() const;
	Camera* Get2DCamera() const;

	void SetCurrentCamera(Camera* newcam);
private:
	Camera* camCurrent;
	Camera* DefaultCamera;
	Camera* pCam2D;

	const float DefaultFOV = 3.14159 / 3;
	const float NearDist = 1.0f;
	const float FarDist = 1000.0f;
};

#endif _CameraManager
