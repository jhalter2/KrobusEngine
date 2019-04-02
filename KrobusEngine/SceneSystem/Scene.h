#ifndef _Scene
#define _Scene

#include "UpdatableManager.h"
#include "DrawableManager.h"
#include "SceneRegistrationBroker.h"
#include "AlarmableManager.h"
#include "KeyboardEventManager.h"
#include "CollisionManager.h"
#include "CameraManager.h"

class CommandBase;
class Camera;

enum class EVENT_TYPE;

class Scene {
public:
	Scene() = default;
	virtual ~Scene() = default;
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Camera* Scene::GetCurrentCamera();
	///
	/// \brief	Gets current camera
	/// 		
	///Returns the currently used camera, which is specifically needed when rendering something in the Draw() step
	///
	/// \author	Jehal
	/// \date	3/4/2019
	///
	/// \returns	Null if it fails, else the current camera.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Camera* GetCurrentCamera();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Camera* Scene::GetCurrent2DCamera();
	///
	/// \brief	Gets current camera
	/// 		
	///Returns the currently used 2D camera, which is specifically needed when rendering something in the Draw2D() step
	///used for sprites/UI elements
	/// \author	Jehal
	/// \date	3/4/2019
	///
	/// \returns	Null if it fails, else the current camera.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Camera* GetCurrent2DCamera();

private:

	UpdatableManager UpdateMgr;
	DrawableManager DrawMgr;
	AlarmableManager AlarmMgr;
	KeyboardEventManager KBEventMgr;
	SceneRegistrationBroker RegistrationBrkr;
	CollisionManager CollisionMgr;
	CameraManager CamMgr;

	void SubmitCommand(CommandBase* cmd);

	void Update();
	void Draw();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Scene::SceneEnd()
	///
	/// \brief	Scene end
	/// 		
	/// 		
	///This method is called by the engine as part of the scene clean-up process 
	/// 
	/// \author	Jehal
	/// \date	3/4/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void SceneEnd() {};

	friend class SceneAttorney;

protected:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Scene::Initialize()
	///
	/// \brief	called as the start of a scene
	/// 	
	/// 			
	/// This is where game objects and entities within the scene should be created
	/// REMEMBER to create a CAMERA here as well
	/// IMPORTANT: collision pairs need to be specified here between two types of objects
	/// or self collison
	/// 		
	/// \par Example:
	/// 	 How a collision pair would be created to be recognized by the scene
	/// 	 
	/// \code
	/// 	 void Scene::Initialize()
	/// 	 {
	/// 		//will detect collisions between player and enemy class, NOT SPECIFIC OBJECTS
	/// 		SetCollisionPair<Player, Enemy>();
	/// 		//will detect collisions between multiple of the same enemy class, NOT SPECIFIC OBJECTS
	/// 		SetCollisionSelf<Enemy>();
	/// \endcode
	/// 		
	/// \author	Jehal
	/// \date	3/4/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Initialize() {};

	template< typename C1, typename C2>
	void SetCollisionPair()
	{
		CollisionMgr.SetCollisionPair<C1, C2>();
	}

	template< typename C3>
	void SetCollisionSelf ()
	{
		CollisionMgr.SetCollisionSelf<C3>();
	}

};

#endif _Scene
