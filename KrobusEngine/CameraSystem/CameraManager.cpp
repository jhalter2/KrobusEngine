#include "AzulCore.h"
#include "CameraManager.h"
#include "KrobusEngine.h"
#include "GameObject.h"

CameraManager::CameraManager() {
	//setting up default 3D camera
	DefaultCamera = new Camera(Camera::Type::PERSPECTIVE_3D);
	DefaultCamera->setViewport(0, 0, KrobusEngine::GetWidth(), KrobusEngine::GetHeight());
	DefaultCamera->setPerspective(35.0f, float(KrobusEngine::GetWidth()) / float(KrobusEngine::GetHeight()), 1.0f, 5000.0f);

	// Orient 3D Camera
	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);

	//set the 3D camera to its position and pointing toward the target
	DefaultCamera->setOrientAndPosition(up3DCam, pos3DCam, pos3DCam);
	DefaultCamera->updateCamera();

	camCurrent = DefaultCamera;

	//setting up 2D camera
	pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);

	pCam2D->setViewport(0, 0, KrobusEngine::GetWidth(), KrobusEngine::GetHeight());
	pCam2D->setOrthographic(-0.5f*float(KrobusEngine::GetWidth()), 0.5f*float(KrobusEngine::GetWidth()),
		-0.5f*float(KrobusEngine::GetHeight()), 0.5f*float(KrobusEngine::GetHeight()), 1.0f, 1000.0f);

	Vect up2DCam(0.0f, 1.0f, 0.0f);
	Vect pos2DCam(0.0f, 0.0f, 0.0f);
	Vect lookAt2DCam(0.0f, 0.0f, -1.0f);
	//set 2D camera to its position then update it
	pCam2D->setOrientAndPosition(up2DCam, lookAt2DCam, pos2DCam);
	pCam2D->updateCamera();
}

CameraManager::~CameraManager() {
	delete DefaultCamera;
	DebugMsg::out("camera manager deleted\n");
}

void CameraManager::Delete() {
	if (DefaultCamera != camCurrent) {
		delete camCurrent;
		delete DefaultCamera;
	}
	else {
		delete DefaultCamera;
	}
}

Camera* CameraManager::GetCurrentCamera() {
	return camCurrent;
}

Camera* CameraManager::GetCurrent2DCamera() {
	return pCam2D;
}

void CameraManager::SetCurrentCamera(Camera* newcam) {
	camCurrent = newcam;
}
