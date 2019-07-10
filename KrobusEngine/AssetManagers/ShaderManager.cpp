//ShaderManager is a singleton where shaders
//need to be loaded in before they are used.
//shaders are stored in a map by name(key) and
//are stored in different maps according to which
//shader it is.
//This is done in order to optimize the DirectX Draw()
//step so that device context does not need to be reset
//multiple times per shader.
//All shaders to be used during runtime should be
//loaded in using the LoadResources() function in the
//KrobusEngine.cpp main class.

#include "ShaderManager.h"
#include "ShaderBase.h"
#include "ShaderMultiPointlight.h"
#include "ShaderColorLight.h"
#include "ShaderTexture.h"
#include "EngineBridge.h"
#include <assert.h>

ShaderManager* ShaderManager::ptrInstance = nullptr;

typedef std::string string;

ShaderManager::~ShaderManager() {
	//delete all shaders created
	for (TextureStorageMap::iterator it = texStorageMap.begin(); it != texStorageMap.end(); it++)
	{
		delete it->second;
	}
	texStorageMap.clear();

	for (ColorStorageMap::iterator it = colStorageMap.begin(); it != colStorageMap.end(); it++)
	{
		delete it->second;
	}
	colStorageMap.clear();

	for (TexStorageMap::iterator it = textureStorageMap.begin(); it != textureStorageMap.end(); it++)
	{
		delete it->second;
	}
	textureStorageMap.clear();
}

//load shader by name along with the type as defined in the enum class
void ShaderManager::privLoad(string name, SHADER_TYPES render) {
	int i = (int)render;
	if (i == 0) {
		ColorStorageMap::iterator it = colStorageMap.find(name);

		if (it != colStorageMap.end()) {
			assert(false && "texture shader key already used");
		}
		colStorageMap[name] = new ShaderColorLight(EngineBridge::GetDevice());
	}
	else if (i == 1) {
		TextureStorageMap::iterator it = texStorageMap.find(name);

		if (it != texStorageMap.end()) {
			assert(false && "color shader key already used");
		}
		else {
			texStorageMap[name] = new ShaderMultiPointlight(EngineBridge::GetDevice());
		}
	}
	else {
		TexStorageMap::iterator it = textureStorageMap.find(name);

		if (it != textureStorageMap.end()) {
			assert(false && "texture_no_light shader key already used");
		}
		else {
			textureStorageMap[name] = new ShaderTexture(EngineBridge::GetDevice());
		}
	}
}

//the separate get functions below are in order to assist in optimization
//of the internal DirectX Draw() step

ShaderMultiPointlight* ShaderManager::privGetTextureShader(string name) {
	TextureStorageMap::iterator it = texStorageMap.find(name);

	if (it == texStorageMap.end()) {
		assert(false && "Unknown shader key");
	}
	return texStorageMap[name];
}

ShaderColorLight* ShaderManager::privGetColorShader(string name) {
	ColorStorageMap::iterator it = colStorageMap.find(name);

	if (it == colStorageMap.end()) {
		assert(false && "Unknown shader key");
	}
	return colStorageMap[name];
}

ShaderTexture* ShaderManager::privGetTexShader(string name) {
	TexStorageMap::iterator it = textureStorageMap.find(name);

	if (it == textureStorageMap.end()) {
		assert(false && "Unknown shader key");
	}
	return textureStorageMap[name];
}

void ShaderManager::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}
