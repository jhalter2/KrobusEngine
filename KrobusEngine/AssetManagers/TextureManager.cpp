#include "AzulCore.h"
#include "TextureManager.h"

TextureManager* TextureManager::ptrInstance = nullptr;

typedef std::string string;
//our textures so far
const string TextureManager::DefaultPath = "Textures/";

TextureManager::~TextureManager() {
	//delete all textures we created
	for (StorageMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
	{
		delete it->second;
	}
	DebugMsg::out("texture's deleted and texture manager now deleted\n");
}

void TextureManager::privLoad(string name, string texture) {
	StorageMap::iterator it = storageMap.find(name);

	if (it != storageMap.end()) {
		DebugMsg::out("ERROR texture Manager: texture key '%s' already in use.\n'", name.c_str());
		assert(false && "texture key already used");
	}
	else {
		string path = DefaultPath + texture;
		storageMap[name] = new Texture(path.c_str());
		DebugMsg::out("texture Manager: texture '%s' loaded.\n'", name.c_str());
	}
}

//single pixel texture
void TextureManager::privLoad(string name, unsigned char r, unsigned char g, unsigned char b) {
	StorageMap::iterator it = storageMap.find(name);

	if (it != storageMap.end()) {
		DebugMsg::out("ERROR texture Manager: texture key '%s' already in use.\n'", name.c_str());
		assert(false && "texture key already used");
	}
	else {
		storageMap[name] = new Texture(r, g, b);
		DebugMsg::out("texture Manager: texture '%s' loaded.\n'", name.c_str());
	}
}

Texture* TextureManager::privGet(string name) {
	StorageMap::iterator it = storageMap.find(name);

	if (it == storageMap.end()) {
		DebugMsg::out("ERROR texture Manager: Unknown texture key '%s'.\n'");
		assert(false && "Unknown texture key");
	}
	return storageMap[name];
}

void TextureManager::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}
