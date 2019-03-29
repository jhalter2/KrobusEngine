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

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Camera* CameraManager::GetCurrentCamera();
	///
	/// \brief	Gets current camera
	/// 		
	/// The camera manager will create a default camera when it gets created. To use a custom camera
	/// you must create your own then call CameraManager::SetCurrentCamera(Camera*) then
	/// it can be retrieved from this
	///
	/// \author	Jehal
	/// \date	3/4/2019
	///
	/// \returns	Null if it fails, else the current camera.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Camera* GetCurrentCamera();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Camera* CameraManager::GetCurrent2DCamera();
	///
	/// \brief	Gets current 2D camera
	///
	/// The camera manager has a default 2D camera that should be used for sprites and UI elements.
	/// Make sure to only use the 2D camera for rendering sprites or UI elements to the screen
	/// \author	Jehal
	/// \date	3/11/2019
	///
	/// \returns	Null if it fails, else the current 2D camera.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Camera* GetCurrent2DCamera();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void CameraManager::SetCurrentCamera(Camera* newcam);
	///
	/// \brief	Sets current camera
	///
	/// Once you create a new camera, it can be set to the currently used camera with this function
	/// 
	/// \author	Jehal
	/// \date	3/4/2019
	///
	/// \param [in,out]	newcam	If non-null, the newcam.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetCurrentCamera(Camera* newcam);
private:
	 
	Camera* camCurrent;
	Camera* DefaultCamera;
	Camera* pCam2D;
};

#endif _CameraManager