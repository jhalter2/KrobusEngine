#ifndef _ShaderManagerAttorney
#define _ShaderManagerAttorney

#include "ShaderManager.h"

//attorney for unloading shaders at the end of the engine loop
class ShaderManagerAttorney {
	friend class KrobusEngine;

private:
	static void Terminate() { ShaderManager::Terminate(); }
};

#endif _ShaderManagerAttorney
