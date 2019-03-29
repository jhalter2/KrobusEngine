#ifndef _ShaderManagerAttorney
#define _ShaderManagerAttorney

#include "ShaderManager.h"

class ShaderManagerAttorney {
	friend class KrobusEngine;

private:
	static void Terminate() { ShaderManager::Terminate(); }
};

#endif _ShaderManagerAttorney