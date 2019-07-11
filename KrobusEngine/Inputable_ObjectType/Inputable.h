#ifndef _Inputable
#define _Inputable

#include <list>

enum class EVENT_TYPE;
enum class RegistrationState;
class InputRegistrationCommand;
class InputDeregistrationCommand;

class Inputable {
public:
	Inputable();
	Inputable(const Inputable&) = delete;
	Inputable& operator=(const Inputable&) = delete;
	virtual ~Inputable();
private:
	struct RegistrationData {
		//enum class for state assertions
		RegistrationState RegStateCurr;
		//create both commands now to be reused
		InputRegistrationCommand* pRegistrationCmd;
		InputDeregistrationCommand* pDeregistrationCmd;
	};

	RegistrationData RegData;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Inputable::KeyPressed(AZUL_KEY k)
	///
	/// \brief	watch for key presses
	/// 		
	/// 		
	///Once you submit input registration for a specific key on an object, this code will define what should happen
	/// when that key is pressed
	/// 
	/// \par Example:
	/// 	 
	/// 	  		The following example shows proper input submission for a game object and code that will watch 
	/// 	  		for a key press
	/// 	  		
	/// \code
	/// 			void Player::Player()
	/// 			{
	/// 				//looking for space bar press only, not release
	/// 				SubmitKeyRegistration(AZUL_KEY::KEY_SPACE, EVENT_TYPE::KEY_PRESS);
	///				}
	///				
	///				void Player::KeyPressed(AZUL_KEY k)
	///				{
	///					//fire bullet on space key press
	///					//important to remember that this will only be called once. it needs to be in update if
	///					//you want it to register a continuous press
	///					this->FireBullet();
	///				}
	///	\endcode
	///			
	/// \author	Jehal
	/// \date	3/4/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void KeyPressed(char k);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Inputable::Released(AZUL_KEY k)
	///
	/// \brief	watch for key releases
	/// 		
	/// 		
	///Once you submit input registration for a specific key on an object, this code will define what should happen
	/// when that key is released
	/// 
	/// \par Example:
	/// 	 
	/// 	  		The following example shows proper input submission for a game object and code that will watch 
	/// 	  		for a key release
	/// 	  		
	/// \code
	/// 			void Player::Player()
	/// 			{
	/// 				//looking for space bar release only, not press
	/// 				SubmitKeyRegistration(AZUL_KEY::KEY_SPACE, EVENT_TYPE::KEY_RELEASE);
	///				}
	///				
	///				void Player::KeyReleased(AZUL_KEY k)
	///				{
	///					//fire bullet on space key release
	///					//important to remember that this will only be called once
	///					this->FireBullet();
	///				}
	///	\endcode
	///			
	/// \author	Jehal
	/// \date	3/4/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void KeyReleased(char k);

	friend class InputableAttorney;

	char key;
	EVENT_TYPE ev;
protected:
	void SceneRegistration(char k, EVENT_TYPE e);
	void SceneDeregistration(char k, EVENT_TYPE e);
	void SubmitKeyRegistration(char k, EVENT_TYPE e);
	void SubmitKeyDeregistration(char k, EVENT_TYPE e);
};
#endif _Inputable
