#ifndef _TimeManager
#define _TimeManager

class FreezeTime;

class TimeManager {
private:
	static TimeManager* ptrInstance;

	TimeManager();
	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;
	~TimeManager();

	static TimeManager& Instance() {
		if (!ptrInstance)
			ptrInstance = new TimeManager;
		return *ptrInstance;
	};

	friend class TimeManagerAttorney;

	float privGetTimeSeconds();
	float privGetFrameTime();
	float frameTime;
	float previousTime;
	float currentTime;

	FreezeTime *pFreeze;
	static void ProcessTime(float sys_time);
	static void Terminate();
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static float TimeManager::GetTime()
	///
	/// \brief	Gets the time
	/// 		
	/// Returns current time in seconds that engine has been running
	///
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \returns	The time.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float GetTime() { return Instance().privGetTimeSeconds(); }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static float TimeManager::GetFrameTime()
	///
	/// \brief	Gets frame time
	///
	/// Returns current frame time 
	/// 
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \returns	The frame time.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float GetFrameTime() { return Instance().privGetFrameTime(); }
};

#endif _TimeManager
