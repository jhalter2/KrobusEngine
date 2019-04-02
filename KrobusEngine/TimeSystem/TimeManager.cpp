#include "TimeManager.h"
#include "KrobusEngine.h"
#include "AzulCore.h"
#include "FreezeTime.h"

TimeManager* TimeManager::ptrInstance = nullptr;

TimeManager::TimeManager() {
	frameTime = KrobusEngine::GetTimeSeconds();
	previousTime = KrobusEngine::GetTimeSeconds();
	currentTime = KrobusEngine::GetTimeSeconds();
	pFreeze = new FreezeTime();
}

TimeManager::~TimeManager() {
	DebugMsg::out("time manager deleted\n");
}

float TimeManager::privGetTimeSeconds() {
	return Instance().currentTime;
}

void TimeManager::ProcessTime(float sys_time) {
	Instance().previousTime = Instance().currentTime;
	Instance().currentTime = Instance().pFreeze->GetTimeInSeconds(sys_time);
	Instance().frameTime = Instance().currentTime - Instance().previousTime;
}

float TimeManager::privGetFrameTime() {
	return frameTime;
}

void TimeManager::Terminate() {
	delete Instance().pFreeze;
	delete ptrInstance;
	ptrInstance = nullptr;
}
