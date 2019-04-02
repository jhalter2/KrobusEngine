#ifndef _CameraManager
#define _CameraManager

class Camera;
class GameObject;

class CameraManager : public Align16 {

public:
	CameraManager();
	CameraManager(const CameraManager&) = delete;
	CameraManager& operator=(const CameraManager&) = delete;
	~CameraManager();

	void Delete();

	Camera* GetCurrentCamera();
	Camera* GetCurrent2DCamera();

	void SetCurrentCamera(Camera* newcam);
private:
	 
	Camera* camCurrent;
	Camera* DefaultCamera;
	Camera* pCam2D;
};

#endif _CameraManager