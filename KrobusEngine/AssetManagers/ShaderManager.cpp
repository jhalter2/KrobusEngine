#include "AzulCore.h"
#include "ShaderManager.h"

ShaderManager* ShaderManager::ptrInstance = nullptr;

typedef std::string string;
//our shaders so far
const string ShaderManager::DefaultPath = "Shaders/";
const string ShaderManager::Texture = "textureFlatRender";
const string ShaderManager::TextureLight = "textureLightRender";
const string ShaderManager::ColorConstant = "colorConstantRender";
const string ShaderManager::Color = "colorNoTextureRender";
const string ShaderManager::ColorLight = "colorNoTextureLightRender";
const string ShaderManager::VaryColor = "colorVaryRender";
const string ShaderManager::ColorByPosition = "colorVaryRender";
const string ShaderManager::Sprite = "spriteRender";
const string ShaderManager::SpriteLine = "spriteLineRender";

ShaderManager::~ShaderManager() {
	//delete all shaders we created
	for (StorageMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
	{
		delete it->second;
	}
	DebugMsg::out("shaders deleted and now shader manager deleted\n");
}

void ShaderManager::privLoad(string name, string render) {
	StorageMap::iterator it = storageMap.find(name);

	if (it != storageMap.end()) {
		DebugMsg::out("ERROR shader Manager: shader key '%s' already in use.\n'", name.c_str());
		assert(false && "shader key already used");
	}
	else {
		string path = DefaultPath + render;
		storageMap[name] = new ShaderObject(path.c_str());
		DebugMsg::out("shader manager: shader '%s' loaded.\n'", name.c_str());
	}
}

ShaderObject* ShaderManager::privGet(string name) {
	StorageMap::iterator it = storageMap.find(name);

	if (it == storageMap.end()) {
		DebugMsg::out("ERROR shader Manager: Unknown shader key '%s'.\n'", name.c_str());
		assert(false && "Unknown shader key");
	}
	return storageMap[name];
}

void ShaderManager::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}
