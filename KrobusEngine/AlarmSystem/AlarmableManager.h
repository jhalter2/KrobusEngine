#ifndef _AlarmableManager
#define _AlarmableManager

#include <map>

class Alarmable; 

class AlarmableManager {
public:
	enum ALARM_ID { ALARM_0, ALARM_1, ALARM_2 };
	static const int ALARM_NUMBER = 3;
private:
	using AlarmEvent = std::pair<Alarmable*, ALARM_ID>;
	using TimeLineMap = std::multimap<float, AlarmEvent>;
	TimeLineMap timeline;
public:
	AlarmableManager() = default;
	AlarmableManager(const AlarmableManager&) = delete;
	AlarmableManager& operator=(const AlarmableManager&) = delete;
	~AlarmableManager();

	void ProcessAlarms();

	using StorageListRef = TimeLineMap::iterator;
	StorageListRef ref;
	StorageListRef Register(float t, Alarmable* al, ALARM_ID id);
	void Deregister(StorageListRef r);
};

#endif _AlarmableManager
