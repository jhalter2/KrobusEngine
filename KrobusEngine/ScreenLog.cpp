#include "ScreenLog.h"
#include <cstdarg>
#include "SpriteFont.h"
#include "SpriteString.h"
#include "SceneManager.h"
#include "Scene.h"

ScreenLog* ScreenLog::ptrInstance = nullptr;

ScreenLog::~ScreenLog() {
	delete pSS;
}

void ScreenLog::Add(char* A, ...) {
	va_list args;
	va_start(args, A);

	vsprintf_s(Instance().DebugBuff, A, args);

	std::string s(Instance().DebugBuff);
	Instance().messages.push_back(s);
}

void ScreenLog::Render() {
	//render each message in our log
	//count number of strings added to properly increment y spacing
	for (MessageCollection::iterator it = Instance().messages.begin(); it != Instance().messages.end(); it++) {
		Instance().pSS->Set(Instance().font, (*it), Instance().DEFAULT_POS_X, Instance().DEFAULT_POS_Y - (Instance().count * Instance().Y_SPACING));
		Instance().pSS->Render();
		Instance().count++;
	}
	Instance().count = 0;
	Instance().messages.clear();
}

void ScreenLog::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}