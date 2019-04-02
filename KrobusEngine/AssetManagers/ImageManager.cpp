#include "ImageManager.h"

ImageManager* ImageManager::ptrInstance = nullptr;

typedef std::string string;

ImageManager::~ImageManager() {
	for (StorageMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
	{
		delete it->second;
	}
	DebugMsg::out("images deleted and now image manager deleted\n");
}

Image* ImageManager::privLoad(string name, Texture* tex) {
	StorageMap::iterator it = storageMap.find(name);

	if (it != storageMap.end()) {
		DebugMsg::out("ERROR image Manager: image key '%s' already in use.\n'", name.c_str());
		assert(false && "image key already used");
		return nullptr;
	}
	else {
		storageMap[name] = new Image(tex, new Rect(0.0f, 0.0f, float(tex->getWidth()), float(tex->getHeight())));
		DebugMsg::out("image manager: image '%s' loaded.\n'", name.c_str());
		return storageMap[name];
	}
}

Image* ImageManager::privLoad(string name, Texture* tex, Rect* r) {
	StorageMap::iterator it = storageMap.find(name);

	if (it != storageMap.end()) {
		DebugMsg::out("ERROR image Manager: image key '%s' already in use.\n'", name.c_str());
		assert(false && "image key already used");
		return nullptr;
	}
	else {
		storageMap[name] = new Image(tex, r);
		DebugMsg::out("image manager: image '%s' loaded.\n'", name.c_str());
		return storageMap[name];
	}
}

Image* ImageManager::privGet(string name) {
	StorageMap::iterator it = storageMap.find(name);

	if (it == storageMap.end()) {
		DebugMsg::out("ERROR image Manager: Unknown image key '%s'.\n'", name.c_str());
		assert(false && "Unknown image key");
	}
	return storageMap[name];
}

void ImageManager::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}
