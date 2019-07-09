#ifndef _ModelManagerAttorney
#define _ModelManagerAttorney

#include "ModelManager.h"

//attorney class to unload models once engine loop ends

class ModelManagerAttorney {
	friend class KrobusEngine;

private:
	static void Terminate() { ModelManager::Terminate(); }
};
#endif _ModelManagerAttorney
