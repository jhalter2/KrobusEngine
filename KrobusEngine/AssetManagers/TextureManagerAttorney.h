#ifndef _TextureManagerAttorney
#define _TextureManagerAttorney

#include "TextureManager.h"

class TextureManagerAttorney {
	friend class KrobusEngine;

private:
	static void Terminate() { TextureManager::Terminate(); }
};
#endif _TextureManagerAttorney
