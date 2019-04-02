#include "SpriteFontManager.h"
#include "SpriteFont.h"
#include "AzulCore.h"

SpriteFontManager* SpriteFontManager::ptrInstance = nullptr;

typedef std::string string;

const string SpriteFontManager::DefaultPath = "Font/";

SpriteFontManager::~SpriteFontManager() {
	//delete all sprite fonts we created
	for (StorageMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
	{
		delete it->second;
	}
	DebugMsg::out("sprite fonts deleted and now sprite font manager deleted\n");
}

void SpriteFontManager::privLoad(string name, string path) {
	StorageMap::iterator it = storageMap.find(name);

	if (it != storageMap.end()) {
		DebugMsg::out("ERROR sprite font Manager: font key '%s' already in use.\n'", name.c_str());
		assert(false && "font key already used");
	}
	else {
		storageMap[name] = new SpriteFont(SpriteFontManager::DefaultPath + path);
		DebugMsg::out("sprite font Manager: font '%s' loaded.\n'", name.c_str());
	}
}

SpriteFont* SpriteFontManager::privGet(string name) {
	StorageMap::iterator it = storageMap.find(name);

	if (it == storageMap.end()) {
		DebugMsg::out("ERROR sprite font Manager: Unknown font key '%s'.\n'", name.c_str());
		assert(false && "Unknown font key");
	}
	return storageMap[name];
}

void SpriteFontManager::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}
