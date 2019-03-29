#ifndef _Drawable
#define _Drawable

#include "DrawableManager.h"
#include "DrawDeregistrationCommand.h"
#include "DrawRegistrationCommand.h" 

enum class RegistrationState;

class Drawable {
public:
	Drawable();
	Drawable(const Drawable&) = delete;
	Drawable& operator=(const Drawable&) = delete;
	virtual ~Drawable();
private:
	DrawableManager::StorageListRef pMyDeleteRef; //iterator for quick delete
	RegistrationState RegStateCurr; //enum class for state assertions

	//create both commands now to be reused
	DrawRegistrationCommand* pRegistrationCmd;
	DrawDeregistrationCommand* pDeregistrationCmd;

	friend class DrawableAttorney;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Drawable::Draw()
	///
	/// \brief	Update called once per frame
	/// 		
	/// 		
	///Draw should ONLY contain the relevant code to render the object's own model
	/// 
	/// \par Example:
	/// 	 
	/// 	  		The following example shows rendering the model attached to the current object to the screen
	/// 	  		
	/// \code
	/// 			void Player::Draw()
	/// 			{
	/// 			//make sure to call the render function on the currently used camera, which can be conveniently accessed
	/// 			//through the scene manager
	/// 				pObjectGraphic->Render(SceneManager::GetCurrentScene()->GetCurrentCamera());
	///				}
	///	\endcode
	///			
	/// \author	Jehal
	/// \date	3/4/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Draw() {};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void GameObject::Draw2D()
	///
	/// \brief	Update called once per frame
	/// 		
	/// 		
	///Draw should ONLY contain the relevant code to render the object's own sprite model
	/// 
	/// \par Example:
	/// 	 
	/// 	  		The following example shows rendering a sprite game object
	/// 	  		
	/// \code
	/// 			void Sprite::Draw()
	/// 			{
	/// 			//make sure to call the render function on the currently used 2D camera, which can be conveniently accessed
	/// 			//through the scene manager
	/// 				pObjectSprite->Render(SceneManager::GetCurrentScene()->GetCurrent2DCamera());
	///				}
	///	\endcode
	///			
	/// \author	Jehal
	/// \date	3/4/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Draw2D() {};
protected:
	void SceneRegistration();
	void SceneDeregistration();
	void SubmitDrawRegistration();
	void SubmitDrawDeregistration();
};
#endif _Drawable
