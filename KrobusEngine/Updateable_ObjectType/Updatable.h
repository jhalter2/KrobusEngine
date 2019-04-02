#ifndef _Updatable
#define _Updatable

#include "UpdatableManager.h"
#include "UpdateRegistrationCommand.h"
#include "UpdateDeregistrationCommand.h"

enum class RegistrationState;

class Updatable {
public:
	Updatable();
	Updatable(const Updatable&) = delete;
	Updatable& operator=(const Updatable&) = delete;
	virtual ~Updatable();
private:
	UpdatableManager::StorageListRef pMyDeleteRef; //iterator for quick delete
	RegistrationState RegStateCurr; //enum class for state assertions

	//create both commands to be reused
	UpdateRegistrationCommand* pRegistrationCmd;
	UpdateDeregistrationCommand* pDeregistrationCmd;

	friend class UpdatableAttorney;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Updatable::Update()
	///
	/// \brief	Update called once per frame
	/// 		
	/// 		
	///Update contains any code that needs to be checked or called once per frame
	/// 
	/// \par Example:
	/// 	 
	/// 	  		The following example shows our player object waiting for inputs and moving only while the w key is held down
	/// 	  		Important to remember that Update() will only be called properly if the game object was submitted for 
	/// 	  		update registration
	/// 	  		
	/// \code
	/// 			void Player::Update()
	/// 			{
	/// 			if (Keyboard::GetKeyState(AZUL_KEY::KEY_W))
	///					{
	///						ShipPos += Vect(0, 0, 1) * ShipRot * ShipTransSpeed;
	///					}
	/// 			 }		
	/// \endcode
	/// 		
	/// \author	Jehal
	/// \date	3/4/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Update() {};
protected:
	void SceneRegistration();
	void SceneDeregistration();
	void SubmitUpdateRegistration();
	void SubmitUpdateDeregistration();

};
#endif _Updatable
