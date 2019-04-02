#ifndef _Alarmable
#define _Alarmable

#include "AlarmableManager.h"
#include "AlarmRegistrationCommand.h"
#include "AlarmDeregistrationCommand.h"
#include <list>
enum class RegistrationState;

class Alarmable {
public:
	Alarmable();
	Alarmable(const Alarmable&) = delete;
	Alarmable& operator=(const Alarmable&) = delete;
	virtual ~Alarmable();
private:
	struct RegistrationData {
		//iterator for quick delete
		AlarmableManager::StorageListRef pMyDeleteRef;
		//enum class for state assertions
		RegistrationState RegStateCurr;
		//create both commands now to be reused
		AlarmRegistrationCommand* pRegistrationCmd;
		AlarmDeregistrationCommand* pDeregistrationCmd;
	};	

	RegistrationData RegData[AlarmableManager::ALARM_NUMBER];

	friend class AlarmableAttorney;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Alarmable::Alarm0()
	///
	/// \brief	Alarm for timed events
	/// 		
	/// 		
	///Once you submit for Alarm registraton using a time and id, it will then call the specified alarm after time t
	/// seconds have passed. Currently can use Alarm0()-Alarm2() simultaneously. Alarms can be called again within 
	/// their own body with a different time.
	///
	/// 
	/// \par Example:
	/// 	 
	/// 	  		The following example shows proper input submission for an alarm on a game
	/// 	  		object
	/// 	  		
	/// \code
	/// 			void Player::Player()
	/// 			{
	/// 				//once this object is created, call Alarm0() after 2 seconds
	/// 				SubmitAlarmRegistration(2, 0);
	///				}
	///				
	///				void Player::Alarm0()
	///				{
	///					DebugMsg::out("Alarm0 called after 2 seconds");
	///					//now you can optionally reset this alarm to keep triggering after
	///					//another 2 seconds pass
	///					SubmitAlarmRegistration(2, 0);
	///				}
	///	\endcode
	///			
	///	IMPORTANT: up to 3 alarms can be set for each gameobject, Alarm0()-Alarm2()
	/// \author	Jehal
	/// \date	3/4/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Alarm0() {};
	virtual void Alarm1() {};
	virtual void Alarm2() {};

	void TriggerAlarm(AlarmableManager::ALARM_ID id);

	float time;

protected:
	void AlarmRegistration(float t, AlarmableManager::ALARM_ID id);
	void AlarmDeregistration(AlarmableManager::ALARM_ID id);
	void SubmitAlarmRegistration(float t, int id);
	void SubmitAlarmDeregistration(int id);
};

#endif _Alarmable
