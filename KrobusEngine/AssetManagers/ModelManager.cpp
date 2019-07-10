//ModelManager is a singleton where models
//need to be loaded in before they are used.
//Models are stored in a map by name(key)
//All models to be used during runtime should be
//loaded in using the LoadResources() function in the
//KrobusEngine.cpp main class.

#include "ModelManager.h"
#include "EngineBridge.h"
#include "d3dUtil.h"
#include <assert.h>

ModelManager* ModelManager::ptrInstance = nullptr;

typedef std::string string;

//default models used in demos
const string ModelManager::DefaultPath = "../Assets/Models/";
const string ModelManager::Axis = "Axis.azul";
const string ModelManager::Plane = "Plane.azul";
const string ModelManager::Frigate = "space_frigate.azul";
const string ModelManager::Cottage = "Cottage.azul";
const string ModelManager::Tank = "Tank.azul";
const string ModelManager::Missile = "rocket.azul";
const string ModelManager::BoundingSphere = "BoundingSphere.azul";
const string ModelManager::BoundingBox = "BoundingBox.azul";

ModelManager::~ModelManager() {
	//delete all models created
	for (StorageMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
	{
		delete it->second;
	}
	storageMap.clear();
}

//for loading models based on name(key) and filepath
void ModelManager::privLoad(string name, string model) {
	StorageMap::iterator it = storageMap.find(name);

	if (it != storageMap.end()) {
		assert(false && "model key already used");
	}
	else {

		string path = DefaultPath + model;
		storageMap[name] = new Model(EngineBridge::GetDevice(), path.c_str());
	}
}

//for premade models
void ModelManager::privLoad(string name, Model::PreMadeModels premade) {
	StorageMap::iterator it = storageMap.find(name);

	if (it != storageMap.end()) {
		assert(false && "model key already used");
	}
	else {
		storageMap[name] = new Model(EngineBridge::GetDevice(), premade , 1.0f);
	}
}

//retrieve model by name(key)
Model* ModelManager::privGet(string name) {
	StorageMap::iterator it = storageMap.find(name);

	if (it == storageMap.end()) {
		assert(false && "Unknown model key");
	}
	return storageMap[name];
}

void ModelManager::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}
