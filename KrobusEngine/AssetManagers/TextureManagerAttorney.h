#ifndef _TextureManagerAttorney
#define _TextureManagerAttorney

#include "TextureManager.h"

//attorney that unloads all textures once game engine loop ends

class TextureManagerAttorney {
	friend class KrobusEngine;

private:
	static void Terminate() { TextureManager::Terminate(); }
};
#endif _TextureManagerAttorney
