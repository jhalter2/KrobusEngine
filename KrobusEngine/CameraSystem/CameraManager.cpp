//camera manager class needs to be setup by
//the user at the scene level if they want to
//use cameras within their scene. A default 3D and
//2D camera are automatically set up for the user
//to access and reference. The user also has the option
//to setup their own new camera from the camera class

#include "CameraManager.h"
#include "Camera.h"
#include "KrobusEngine.h"
#include "EngineBridge.h"
#include "GameObject.h"

CameraManager::CameraManager() {
	//setting up default 3D camera 
	DefaultCamera = new Camera();
	DefaultCamera->setPerspective(DefaultFOV, EngineBridge::GetWidth() / (float)EngineBridge::GetHeight(), NearDist, FarDist);
	DefaultCamera->setOrientAndPosition(Vect(0, 1, 0), Vect(0, 0, 0), Vect(0, 3, -5));
	DefaultCamera->updateCamera();

	camCurrent = DefaultCamera;
	EngineBridge::SetCamera(*camCurrent);

	//setting up 2D camera for orthographic view
	pCam2D = new Camera();
	
	pCam2D->setPerspective(DefaultFOV, EngineBridge::GetWidth() / (float)EngineBridge::GetHeight(), NearDist, FarDist);
	pCam2D->setOrthographic(-0.5f*float(EngineBridge::GetWidth()), 0.5f*float(EngineBridge::GetWidth()),
		-0.5f*float(EngineBridge::GetHeight()), 0.5f*float(EngineBridge::GetHeight()), NearDist, FarDist);

	pCam2D->setOrientAndPosition(Vect(0, 1, 0), Vect(0, 0, 0), Vect(0, 0, -1));
	pCam2D->updateCamera();
	EngineBridge::Set2DCamera(*pCam2D);
}

CameraManager::~CameraManager() {
	delete pCam2D;
	if (DefaultCamera != camCurrent) {
		delete camCurrent;
		delete DefaultCamera;
	}
	else {
		delete DefaultCamera;
	}
	//OutputDebugStringA("camera manager deleted\n");
}

Camera* CameraManager::GetCurrentCamera() const {
	return camCurrent;
}

Camera* CameraManager::Get2DCamera() const { 
	return pCam2D;
}

//set a new camera once created
void CameraManager::SetCurrentCamera(Camera* newcam) {
	camCurrent = newcam;
}
