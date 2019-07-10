//clears out any queued text and deleted
//the singleton when the engine is shut down
#ifndef _ScreenLogAttorney
#define _ScreenLogAttorney

#include "ScreenLog.h"

class ScreenLogAttorney {
	friend class KrobusEngine;

private:
	static void Terminate() { ScreenLog::Terminate(); }
	static void Render() { ScreenLog::Render(); }
};
#endif _ScreenLogAttorney
