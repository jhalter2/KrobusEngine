#ifndef _GameObject
#define _GameObject

#include "Drawable.h"
#include "Updatable.h"
#include "Alarmable.h"
#include "Inputable.h"
#include "Collidable.h"
#include "GameObjectEntryCommand.h"
#include "GameObjectExitCommand.h"

enum class RegistrationState;

class GameObject : public Drawable, public Updatable, public Alarmable, public Inputable, public Collidable {
public:

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \fn	GameObject::GameObject();
///
/// \brief	creation of a game object 
/// 		
/// 
///Create a game object and set its parameters and details here. Details include specifying a model, 
/// setting that model's world matrix as well as its scale. The same should be done for the collider model
/// 
/// \code
/// 	 pGraphics = new GraphicsObject_ColorNoTexture(ModelManager::Get("Enemy"), ShaderManager::Get("textureLight"));
/// 	 SetColliderModel(ModelManager::Get("modelSpaceFrigate"));
/// \endcode
/// 		
/// 		
///Most other creation parameters should be passed through the Initialize() function since inputs/registrations/updates would only 
/// want to be called when the object is initialized, not just when it is constructed
/// This is also where you need to specify what kind of inputs/updates the gameobject will need to listen for.
/// 								
/// \par IMPORTANT: if game object is recycled through a pool or factory,
/// 	  make sure to disable and renable inputs, updates, draws etc. through initialization and not construction
/// 		 				
///
/// \author	Jehal
/// \date	3/4/2019
////////////////////////////////////////////////////////////////////////////////////////////////////

	GameObject();
	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;
	virtual ~GameObject();

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \fn	virtual void GameObject::Initialize()
///
/// \brief	Initializes this object
/// 		
/// 	
///This is where you should initialize most info for an object so that it wll properly be used through a pool.
/// The model should also be altered through here if it will change over the course of the game.
/// 
///Submitting the object for update/draw/inputs/alarms must be done manually
///  \code
/// 	SubmitUpdateRegistration();
///		SubmitDrawRegistration();
///		//specified key followed by press or release event type
///		SubmitKeyRegistration(AZUL_KEY::KEY_SPACE, EVENT_TYPE::KEY_PRESS);
///		//timer on the alarm as well as alarm id (0-2)
///		SubmitAlarmRegistration(2.0f, 0);
///	\endcode
///
/// Finally, this is also where you must specify if this game object will use collision and what collision
/// group it belongs to
///
/// \code
/// 	 SetCollidableGroup<Enemy>();
///		 SubmitCollisionRegistration();
/// \endcode
///
///
/// \author	Jehal
/// \date	3/4/2019
////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Initialize() {};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void GameObject::SubmitEntry();
	///
	/// \brief	Submit entry
	/// 		
	///Submit Entry should be called by game objects when they enter the scene. This will register them within
	/// the internal engine systems and eventually result in the gameobject's SceneEntry() function being called
	/// IMPORTANT: do not place registration, collision, or any rendering data within submit entry. All of that should
	/// either be placed within Initialization() or SceneEntry()
	/// 
	/// NOTE: submit entry is not strictly necessary unless an object will re-enter (or be recycled)
	/// within the same scene while it runs
	///
	/// \author	jehalter
	/// \date	3/17/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SubmitEntry();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void GameObject::SubmitExit();
	///
	/// \brief	Submit exit
	/// 		
	///Submit exit should be called by game objects when they exit the scene. This will deregister them within
	/// the internal engine systems and eventually result in the gameobject's SceneExit() function being called
	/// IMPORTANT: do not place deregistration or extra data inside SubmitExit(). All of that should
	/// either be placed within SceneExit()
	/// 
	///  NOTE: submit exit is not strictly necessary unless an object will re-exit (to be recycled)
	/// within the same scene while it runs
	/// 
	/// \author	jehalter
	/// \date	3/17/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SubmitExit();
private:
	RegistrationState currState;
	GameObjectEntryCommand* pRegCmd;
	GameObjectExitCommand* pDeregCmd;

	friend class GameObjectExitCommand;
	friend class GameObjectEntryCommand;
	void ConnectToScene();
	void DisconnectFromScene();

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \fn	virtual void GameObject::SceneEntry()
///
/// \brief	Scene entry
///
/// This is where you should place registration code for any object entering the scene. 
/// It's especially useful to add submissions for Update() and Draw() here for any
/// objects that are being recycled into a scene
/// 
/// \author	Jehal
/// \date	3/4/2019
////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void SceneEntry() {};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \fn	virtual void GameObject::SceneExit()
///
/// \brief	Scene exit
/// 		
/// This is where you would place any code for deregistering an object that is leaving the scene but
/// you're planning to reuse or recycle back into the same scene. Make sure to deregister methods like Update()
/// and Draw() to properly place the object into a dormant state
///
/// \author	Jehal
/// \date	3/4/2019
////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void SceneExit() {};
};

#endif _GameObject
