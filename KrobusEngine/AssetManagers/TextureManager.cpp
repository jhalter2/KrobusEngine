#include "TextureManager.h"
#include "EngineBridge.h"
#include "Texture.h"
#include <assert.h>

//TextureManager is a singleton where textures
//need to be loaded in before they are used.
//Textures are stored in a map by name(key)
//All textures to be used during runtime should be
//loaded in using the LoadResources() function in the
//KrobusEngine.cpp main class.

TextureManager* TextureManager::ptrInstance = nullptr;

typedef std::string string;
//default textures file location
const LPCWSTR TextureManager::DefaultPath = L"../Assets/Textures/";

TextureManager::~TextureManager() {
	//delete all textures we created
	for (StorageMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
	{
		delete it->second;
	}
	storageMap.clear();
}

//the only way to load textures is to give them a name and to
//have a texture file in the default file path specified above

void TextureManager::privLoad(string name, LPCWSTR texture) {
	StorageMap::iterator it = storageMap.find(name);

	std::wstring mywstring(texture);
	std::wstring concatted_stdstr = DefaultPath + mywstring;
	LPCWSTR concatted = concatted_stdstr.c_str();

	if (it != storageMap.end()) {
		assert(false && "texture key already used");
	}
	else {
		storageMap[name] = new Texture(EngineBridge::GetDevice(), concatted);
	}
}

Texture* TextureManager::privGet(string name) {
	StorageMap::iterator it = storageMap.find(name);

	if (it == storageMap.end()) {
		assert(false && "Unknown texture key");
	}
	return storageMap[name];
}

void TextureManager::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}
